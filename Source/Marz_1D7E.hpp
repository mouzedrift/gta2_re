#pragma once

#include "Function.hpp"

#pragma pack(push)
#pragma pack(1)
class Marz_3
{
  public:
    // ctor 463F90
    // dtor 463FA0
    EXPORT Marz_3();
    EXPORT ~Marz_3();

    char_type field_0;
    char_type field_1;
    char_type field_2;
};
#pragma pack(pop)

class Marz_96
{
  public:
    EXPORT ~Marz_96();
    EXPORT void sub_543EC0();
    EXPORT Marz_96();
    Marz_3 field_0[50];
};

class Marz_1D7E
{
  public:
    EXPORT ~Marz_1D7E();
    EXPORT Marz_1D7E();
    EXPORT Marz_96* sub_543F10(u8* a2);
    Marz_96 field_0[50];
    u16 field_1D4C[25];
};
