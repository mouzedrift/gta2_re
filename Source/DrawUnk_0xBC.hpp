#pragma once

#include "Function.hpp"
#include "fix16.hpp"

class Sprite;
class Car_BC;
class Ped;

EXPORT_VAR extern Fix16 dword_676840;
EXPORT_VAR extern Fix16 dword_67681C;

class DrawUnk_0xBC
{
  public:
    EXPORT char_type sub_4355D0(Sprite* a2);
    EXPORT char_type sub_435630(s16* a2, s32 a3);
    EXPORT void sub_4357B0();
    EXPORT void sub_4357F0();
    EXPORT void sub_435810();
    EXPORT void sub_435830();
    EXPORT void sub_435840();
    EXPORT void sub_435860(DrawUnk_0xBC* a2);
    EXPORT s16* sub_4358D0(s16* a2);
    EXPORT s32* sub_435A20(s32* a2);
    EXPORT s32 sub_435A70(Fix16 a2, Fix16 a3, Fix16 a4);
    EXPORT s32 sub_435B90();
    EXPORT void sub_435D20(char_type a2, char_type a3, char_type a4, char_type a5, char_type a6, char_type a7);
    EXPORT void sub_435DD0();
    EXPORT void sub_435F90(Car_BC * a2);
    EXPORT s32 sub_435FF0();
    EXPORT s32 sub_436110();
    EXPORT void sub_436120(Fix16 a2);
    EXPORT void sub_436140();
    EXPORT u32 sub_4361B0(u32 a2, u32 a3);
    EXPORT s32 sub_436200(s32 a2, s32* a3, s32* a4, s32* a5);
    EXPORT void sub_4364A0(Car_BC* pCar);
    EXPORT void sub_436540(s32* a2);
    EXPORT char_type sub_436710(char_type a2, char_type a3, char_type a4, char_type a5);
    EXPORT void sub_436830();
    EXPORT void sub_436860(s32 a2, s32* a3, s32* a4, s32 a5);
    EXPORT DrawUnk_0xBC(); // 4368E0
    EXPORT ~DrawUnk_0xBC(); // empty 4369E0
    EXPORT void sub_4397D0(Fix16 a2, Fix16 a3, Fix16 a4, Fix16 a5);
    EXPORT bool sub_58CF10(Fix16 a2, Fix16 a3);

    inline void inline_sub_475B60()
    {
        field_3C = 1;
    }

    Fix16_Point sub_40CFC0(Fix16 x, Fix16 y, Fix16 z)
    {
        Fix16_Point tmp;
        Fix16 u = field_A0_z - z;
        Fix16 t(dword_67681C / Fix16(u.mValue + dword_676840.mValue, 0));

        tmp.x = (((x - field_98_x) * field_64) * t) + Fix16(320);
        tmp.y = (((y - field_9C_y) * field_64) * t) + Fix16(240);

        return tmp;
    }

    // inline sub_40CF60
    inline bool check_camera(Fix16 a2_fp, Fix16 a3_fp)
    {
        return a2_fp >= field_78_win_left && a2_fp <= field_7C_win_right &&
                 a3_fp >= field_80_win_top &&
                 a3_fp <= field_84_win_bottom;
    }

    Fix16 field_0;
    Fix16 field_4_unk;
    Fix16 field_8;
    Fix16 field_C;
    Fix16 field_10;
    Fix16 field_14;
    Fix16 field_18;
    Fix16 field_1C;
    s32 field_20_right;
    s32 field_24_left;
    s32 field_28_bottom;
    s32 field_2C_top;
    s32 field_30;
    Ped* field_34;
    s32 field_38;
    s32 field_3C;
    Fix16 field_40;
    u8 field_44;
    char_type field_45;
    char_type field_46;
    char_type field_47;
    s32 field_48;
    s32 field_4C;
    s32 field_50;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s32 field_60;
    Fix16 field_64;
    s32 field_68;
    s32 field_6C;
    s32 field_70;
    s32 field_74;
    Fix16 field_78_win_left;
    Fix16 field_7C_win_right;
    Fix16 field_80_win_top;
    Fix16 field_84_win_bottom;
    Fix16 field_88;
    Fix16 field_8C;
    Fix16 field_90;
    Fix16 field_94;
    Fix16 field_98_x;
    Fix16 field_9C_y;
    Fix16 field_A0_z;
    Fix16 field_A4;
    s32 field_A8;
    Fix16 field_AC;
    Fix16 field_B0;
    Fix16 field_B4;
    Fix16 field_B8;
};
GTA2_ASSERT_SIZEOF_ALWAYS(DrawUnk_0xBC, 0xBC)

EXPORT_VAR extern DrawUnk_0xBC* gViewCamera_676978;
