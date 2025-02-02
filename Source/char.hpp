#pragma once

#include "Function.hpp"
#include "Ped.hpp"
#include "angle.hpp"

class Sprite_3C;
class Ped;
class Car_BC;
class Sprite;

class Char_B4
{
  public:
    s32 field_0;
    s8 field_4;
    u8 field_5_remap;
    s8 field_6;
    s8 field_7;
    s32 field_8_ped_state_1;
    s32 field_C_ped_state_2;
    s32 field_10;
    angle field_14;
    s8 field_16;
    s8 field_17;
    s32 field_18;
    s32 field_1c;
    s32 field_20;
    s32 field_24;
    angle field_28;
    angle field_2a;
    angle field_2c;
    s8 field_2e;
    s8 field_2f;
    s32 field_30;
    s16 field_34;
    s8 field_36;
    s8 field_37;
    Fix16 field_38;
    Fix16 field_3c;
    angle field_40_rotation;
    angle field_42;
    s8 field_44;
    s8 field_45;
    s16 field_46;
    s8 field_48;
    s8 field_49;
    s16 field_4a;
    Fix16 field_4c;
    Fix16 field_50;
    s8 field_54;
    s8 field_55;
    s8 field_56;
    s8 field_57;
    s32 field_58;
    s8 field_5c;
    s8 field_5d;
    s8 field_5e;
    s8 field_5f;
    s32 field_60;
    s32 field_64;
    u8 field_68;
    s8 field_69;
    s8 field_6a;
    s8 field_6b;
    s32 field_6c;
    s8 field_70;
    s8 field_71;
    s8 field_72;
    s8 field_73;
    angle field_74;
    s8 field_76;
    s8 field_77;
    Char_B4* field_78_next;
    Ped* field_7c_ped_ptr;
    Sprite* field_80_sprite_ptr; // TODO: Or sprite_3c, are they the same type ??
    Car_BC* field_84_AutoClass21_s1_ptr1;
    Car_BC* field_88AutoClass21_s1_ptr2;
    Fix16 field_8c;
    Fix16 field_90;
    Fix16 field_94;
    Fix16 field_98;
    Fix16 field_9c;
    s8 field_a0;
    s8 field_a1;
    s8 field_a2;
    s8 field_a3;
    Fix16 field_a4_x;
    Fix16 field_a8_y;
    Fix16 field_ac_z;
    s32 field_b0;

    Char_B4();
    ~Char_B4();

    // TODO: Stubs/func ordering
    EXPORT void sub_5453D0();
    EXPORT void sub_5454B0();
};

class Char_11944
{
  public:
    Char_B4* field_0_next;
    Char_B4 field_4_array[400];

    Char_11944();

    // inline 0x4355C0
    void sub_4355C0(Char_B4* pB4)
    {
        pB4->sub_5453D0();
        pB4->field_78_next = field_0_next;
        field_0_next = pB4;
    }

    EXPORT void sub_5453D0();
};

class Char_8
{
  public:
    Ped* field_0_char_ped;
    Char_8* field_4_pOwner;
};

class Char_324
{
  public:
    Char_8* field_0_next;
    Char_8 field_4_array[99];
    s8 field_31c;
    s8 field_31d;
    s8 field_31e;
    s8 field_31f;
    s32 field_320_in_use;

    Char_324();
};

class Char_C
{
  public:
    EXPORT void sub_46EB60(u32* a2);
    EXPORT void sub_4703F0();
    EXPORT Char_C();
    EXPORT ~Char_C();
    EXPORT Ped* sub_470A50(Fix16 xpos, Fix16 ypos, Fix16 zpos, u8 remap, Ang16 a6);
    EXPORT Ped* sub_470B00(Car_BC* a2);
    EXPORT Ped* sub_470BA0(Car_BC* a1, s32 a2);
    EXPORT Ped* sub_470CC0(Car_BC* a2);
    EXPORT Ped* sub_470D60();
    EXPORT Ped* sub_470E30();
    EXPORT Ped* sub_470F30();
    EXPORT Ped* sub_470F90(Ped* pSrc);
    EXPORT void DoIanTest_471060(s16 a1);
    EXPORT Ped* sub_4710C0(s32 a2);

    s16 field_0;
    char_type field_2;
    char_type field_3;
    char_type field_4;
    char_type field_5;
    char_type field_6_num_peds_on_screen;
    char_type field_7_make_all_muggers;
    Sprite* field_8;
};

class Char_203AC
{
  public:
    EXPORT ~Char_203AC();
    Ped* field_0;
    Ped* field_4;
    Ped field_8[200];
    s16 field_203A8;
    s16 field_203AA;
};

EXPORT_VAR extern Char_C* gChar_C_6787BC;
EXPORT_VAR extern Char_203AC* gChar_203AC_6787B8;
EXPORT_VAR extern Char_11944* gChar_11944_6FDB44;
EXPORT_VAR extern Char_324* gChar_324_678b50;
