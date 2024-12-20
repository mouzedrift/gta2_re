cmake_minimum_required (VERSION 3.5)
project (decomp)

ENABLE_LANGUAGE(ASM_MASM)

SET(CMAKE_WARN_VS6 CACHE BOOL OFF)

add_library (mss32 SHARED
    Source/3rdParty/mss.h
    Source/3rdParty/mss.cpp
    )
target_compile_definitions(mss32 PRIVATE BUILD_MSS)

#add_custom_command (
#    TARGET mss32
#    POST_BUILD
#    COMMAND del $(TargetPath)
#)

# we build the code 3 times as:
# a static lib where by we link it to an exe that is supposed to match the OG as closely as possible
# a dll that contains the global vars as being exported and no functions exported
# a dll that contains the global vars as being imported and all functions exported
# this is so that for the hook dll we can redirect importing the vars from the 2nd copy of the dll
# to the actual executable data/vars
set(gta2_lib_src
  Source/3rdParty/mss.h
  Source/types.hpp
  Source/winmain.cpp
  Source/frosty_pasteur_0xC1EA8.hpp
  Source/frosty_pasteur_0xC1EA8.cpp
  Source/map_0x370.hpp
  Source/map_0x370.cpp
  Source/nostalgic_ellis_0x28.hpp
  Source/nostalgic_ellis_0x28.cpp
  Source/fix16.hpp
  Source/fix16.cpp
  Source/error.hpp
  Source/error.cpp
  Source/memory.hpp
  Source/memory.cpp
  Source/chunk.hpp
  Source/keybrd_0x204.hpp
  Source/keybrd_0x204.cpp
  Source/debug.hpp
  Source/debug.cpp
  Source/cSampleManager.hpp
  Source/cSampleManager.cpp
  Source/sound_obj.hpp
  Source/sound_obj.cpp
  Source/dma_video.hpp
  Source/dma_video.cpp
  Source/magical_germain_0x8EC.hpp
  Source/magical_germain_0x8EC.cpp
  Source/sharp_pare_0x15D8.hpp
  Source/sharp_pare_0x15D8.cpp
  Source/Bink.hpp
  Source/Bink.cpp
  Source/gbh_graphics.hpp
  Source/gbh_graphics.cpp
  Source/text_0x14.hpp
  Source/text_0x14.cpp
  Source/root_sound.hpp
  Source/root_sound.cpp
  Source/angry_lewin_0x85C.hpp
  Source/angry_lewin_0x85C.cpp
  Source/laughing_blackwell_0x1EB54.hpp
  Source/laughing_blackwell_0x1EB54.cpp
  Source/Game_0x40.hpp
  Source/Game_0x40.cpp
  Source/jolly_poitras_0x2BC0.hpp
  Source/jolly_poitras_0x2BC0.cpp
  Source/goofy_thompson.hpp
  Source/goofy_thompson.cpp
  Source/input.hpp
  Source/input.cpp
  Source/lucid_hamilton.hpp
  Source/lucid_hamilton.cpp
  Source/registry.hpp
  Source/registry.cpp
  Source/file.hpp
  Source/file.cpp
  Source/sharp_bose_0x54.hpp
  Source/sharp_bose_0x54.cpp
  Source/distracted_einstein_0xC.hpp
  Source/distracted_einstein_0xC.cpp
  Source/gtx_0x106C.hpp
  Source/gtx_0x106C.cpp
  Source/Function.hpp
  Source/DrawUnk_0xBC.hpp
  Source/DrawUnk_0xBC.cpp
  Source/cool_nash_0x294.hpp
  Source/cool_nash_0x294.cpp
  Source/Car_BC.hpp
  Source/Car_BC.cpp
  Source/Car_10.hpp
  Source/Car_10.cpp
  Source/Ped_Unknown_4.hpp
  Source/Ped_Unknown_4.cpp
  Source/zealous_borg.hpp
  Source/zealous_borg.cpp
  Source/infallible_turing.hpp
  Source/infallible_turing.cpp
  Source/sad_mirzakhani.hpp
  Source/sad_mirzakhani.cpp
  Source/Zones_CA8.hpp
  Source/Zones_CA8.cpp
)

# global include dirs
include_directories(Source)
include_directories(${decomp_SOURCE_DIR})

add_library (gta2_lib ${gta2_lib_src})
target_compile_definitions(gta2_lib PRIVATE _CRT_SECURE_NO_WARNINGS _CRT_NON_CONFORMING_SWPRINTFS)

add_library (gta2_dll_exports SHARED ${gta2_lib_src})
target_compile_definitions(gta2_dll_exports PRIVATE EXPORT_VARS _CRT_SECURE_NO_WARNINGS _CRT_NON_CONFORMING_SWPRINTFS)
target_link_libraries(gta2_dll_exports mss32 Winmm)

add_library (gta2_dll_imports SHARED ${gta2_lib_src})
target_compile_definitions(gta2_dll_imports PRIVATE IMPORT_VARS EXPORT_FUNCS _CRT_SECURE_NO_WARNINGS _CRT_NON_CONFORMING_SWPRINTFS)
target_link_libraries(gta2_dll_imports gta2_dll_exports mss32 Winmm)

add_executable (decomp_main WIN32
    test.cpp
    StdAfx.cpp
    resources.rc)
target_link_libraries(decomp_main mss32 gta2_lib)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")

# NOICF is required because skip_ovly_5AAE20 and skip_psxt_5AAE30 have identical bodies and the linker will make them one and the same
# however the real binary does have 2 copies. NOREF keeps functions that are not yet called so we can diff the content against the original.
if (${MSVC_VERSION} GREATER 1200)
set (CMAKE_EXE_LINKER_FLAGS "/MAP:output.map /OPT:NOICF,NOREF /SAFESEH:NO" )
else()
set (CMAKE_EXE_LINKER_FLAGS "/MAP:output.map /OPT:NOICF,NOREF" )
endif()
set (CMAKE_SHARED_LINKER_FLAGS "/OPT:NOICF,NOREF")

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )

if (${MSVC_VERSION} EQUAL 1200)
foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/ML /W3 /GX" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()

foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/Zi" "/Z7" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()

foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/Ob2" "" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()

foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/GR" "/EHsc" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()
endif()

message(STATUS "${MSVC_VERSION}=${${MSVC_VERSION}}")

if (${MSVC_VERSION} GREATER 1200)
   SET ( CMAKE_SHARED_LINKER_FLAGS /MANIFEST:NO )
endif()

#install (TARGETS decomp_main DESTINATION bin)