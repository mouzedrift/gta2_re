#include "Tango_28.hpp"
#include "debug.hpp"

// https://decomp.me/scratch/68yPe
STUB_FUNC(0x4a85f0)
void Tango_54::sub_4A85F0()
{
    if (!bSkip_fire_engines_67D53A)
    {
        for (u16 i = 0; i < 2; i++)
        {
            if (field_0[i].field_4)
            {
                field_0[i].sub_4A81F0();
            }
        }
    }
}

STUB_FUNC(0x4a8620)
Tango_28* Tango_54::sub_4A8620(Car_BC* a2, s32 a3, s32 a4, s32 a5)
{
    return 0;
}

STUB_FUNC(0x4a8800)
Tango_28* Tango_54::sub_4A8800()
{
    return 0;
}

STUB_FUNC(0x4a8820)
char_type Tango_54::sub_4A8820(Car_BC* a2)
{
    return 0;
}

MATCH_FUNC(0x4a88d0)
void Tango_54::sub_4A88D0()
{
    field_50 = 0;
}

STUB_FUNC(0x4a7fc0)
char_type Tango_28::sub_4A7FC0()
{
    return 0;
}

STUB_FUNC(0x4a81a0)
void Tango_28::sub_4A81A0()
{
}

STUB_FUNC(0x4a81f0)
void Tango_28::sub_4A81F0()
{
}

MATCH_FUNC(0x4a85c0)
void Tango_28::init_4A85C0()
{
    sub_450C10();
}

STUB_FUNC(0x4a85e0)
s32 Tango_28::sub_4A85E0()
{
    return 0;
}
