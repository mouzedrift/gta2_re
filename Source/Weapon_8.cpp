#include "Weapon_8.hpp"
#include "Globals.hpp"
#include "debug.hpp"
#include "error.hpp"
#include "root_sound.hpp"

EXPORT_VAR Weapon_2FDC* gWeapon_2FDC_707014;
GLOBAL(gWeapon_2FDC_707014, 0x707014);

EXPORT_VAR Weapon_8* gWeapon_8_707018;
GLOBAL(gWeapon_8_707018, 0x707018);

STUB_FUNC(0x5e3c10)
Weapon_30* Weapon_8::sub_5E3C10(s32 a2, cool_nash_0x294* a3, u8 a4)
{
    return 0;
}

STUB_FUNC(0x5e3cb0)
s32 Weapon_8::sub_5E3CB0(s32 a2)
{
    return 0;
}

STUB_FUNC(0x5e3ce0)
Weapon_30* Weapon_8::sub_5E3CE0(s32 a1, Car_BC* a2, u8 a3)
{
    return 0;
}

STUB_FUNC(0x5e3d20)
Weapon_30* Weapon_8::sub_5E3D20(Car_BC* a2, s32 a3)
{
    return 0;
}

STUB_FUNC(0x5e3d50)
char_type Weapon_8::sub_5E3D50(s32 a2, u8 a3, Car_BC* a4)
{
    return 0;
}

STUB_FUNC(0x5e3df0)
void Weapon_8::sub_5E3DF0(u32* a1)
{
}

STUB_FUNC(0x5e3e70)
char_type Weapon_8::sub_5E3E70(s32 a2)
{
    return 0;
}

STUB_FUNC(0x5e3e80)
char_type Weapon_8::sub_5E3E80(s32 a2)
{
    return 0;
}

MATCH_FUNC(0x5e3e90)
Weapon_8::Weapon_8()
{
    if (!gWeapon_2FDC_707014)
    {
        gWeapon_2FDC_707014 = new Weapon_2FDC();
        if (!gWeapon_2FDC_707014)
        {
            FatalError_4A38C0(0x20, "weapon.cpp", 2428);
        }
    }
    field_4 = 0;
    field_0.sub_4207E0();
}

MATCH_FUNC(0x5e3f60)
Weapon_8::~Weapon_8()
{
    if (gWeapon_2FDC_707014)
    {
        GTA2_DELETE_AND_NULL(gWeapon_2FDC_707014);
    }
}

MATCH_FUNC(0x5DCD10)
Weapon_30::Weapon_30()
{
    field_0 = 0;
    field_24 = 0;
    field_14 = 0;
    field_2 = 0;
    field_4 = 0;
    field_18 = 0;
    field_1C = 0;
    field_10 = 0;
    field_8 = 0;
    field_C = -1;
    field_20 = 0;
    field_21 = 0;
    field_2C = 0;
    field_28 = 0;
}

MATCH_FUNC(0x5DCD50)
Weapon_30::~Weapon_30()
{
    field_24 = 0;
    field_18 = 0;
    field_14 = 0;
    field_8 = 0;
    if (field_28)
    {
        gRoot_sound_66B038.DestroySoundObj_40FE60(field_28);
        field_28 = 0;
    }
}

MATCH_FUNC(0x5DCD90)
void Weapon_30::sub_5DCD90()
{
    field_24 = 0;
    field_14 = 0;
    field_1C = 0;
    field_0 = 0;
    field_2 = 0;
    field_4 = 0;
    field_21 = 0;
    field_8 = 0;
    field_C = -1;
    field_20 = 0;
    field_2C = 0;
    if (!field_28 && !bSkip_audio_67D6BE)
    {
        field_28 = gRoot_sound_66B038.CreateSoundObject_40EF40(this, 7);
    }
}

MATCH_FUNC(0x5DCDE0)
void Weapon_30::sub_5DCDE0()
{
    sub_5DCD90();

    field_8 = 0;

    if (field_28)
    {
        gRoot_sound_66B038.DestroySoundObj_40FE60(field_28);
        field_28 = 0;
    }
}

MATCH_FUNC(0x5E4090)
Weapon_2FDC::~Weapon_2FDC()
{
    field_0 = 0;
    field_4 = 0;
}