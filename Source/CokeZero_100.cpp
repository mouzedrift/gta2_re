#include "CokeZero_100.hpp"
#include "Globals.hpp"
#include <memory.h>

EXPORT_VAR CokeZero_100* gCokeZero_100_702F34;
GLOBAL(gCokeZero_100_702F34, 0x702F34);

MATCH_FUNC(0x596a00)
CokeZero_50::CokeZero_50()
{
    field_0 = 0;
    for (s32 i = 0; i < 9; i++)
    {
        field_4[i] = 0;
    }
    field_36 = 0;
    field_38 = 0;
    field_3C = 0;
    field_40 = 0;
    field_4C = 0;
    field_48 = 0;
    field_44 = 0;
    field_34 = 9;
}

MATCH_FUNC(0x596a40)
CokeZero_50::~CokeZero_50()
{
    field_44 = 0;
}

MATCH_FUNC(0x596a50)
void CokeZero_50::Empty_596A50()
{
}

MATCH_FUNC(0x596a60)
void CokeZero_50::Empty_596A60()
{
}

MATCH_FUNC(0x596a70)
void CokeZero_50::sub_596A70(s32 a2)
{
    for (u32 i = a2; i > 0; i--)
    {
        field_4[i] = 0;
    }
}

MATCH_FUNC(0x596a90)
void CokeZero_50::sub_596A90(s32 xpos, s32 ypos, s32 zpos, u32 score)
{
    u32 tmpScore = score;

    this->field_4C = score;
    this->field_0 = 0;

    if (score >= 100000000)
    {
        this->field_0 = 8;
        this->field_4[8] = score / 100000000;
        sub_596A70(7);
        tmpScore = score % 100000000;
    }

    if (tmpScore >= 10000000)
    {
        if (!this->field_0)
        {
            this->field_0 = 7;
        }
        this->field_4[7] = tmpScore / 10000000;
        sub_596A70(6);
        tmpScore %= 10000000u;
    }

    if (tmpScore >= 1000000)
    {
        if (!this->field_0)
        {
            this->field_0 = 6;
        }
        this->field_4[6] = tmpScore / 1000000;
        sub_596A70(5);
        tmpScore %= 1000000u;
    }

    if (tmpScore >= 100000)
    {
        if (!this->field_0)
        {
            this->field_0 = 5;
        }
        this->field_4[5] = tmpScore / 100000;
        sub_596A70(4);
        tmpScore %= 100000u;
    }

    if (tmpScore >= 10000)
    {
        if (!this->field_0)
        {
            this->field_0 = 4;
        }
        this->field_4[4] = tmpScore / 10000;
        sub_596A70(3);
        tmpScore %= 10000u;
    }

    if (tmpScore >= 1000)
    {
        if (!this->field_0)
        {
            this->field_0 = 3;
        }
        this->field_4[3] = tmpScore / 1000;
        sub_596A70(2);
        tmpScore %= 1000u;
    }

    if (tmpScore >= 100)
    {
        if (!this->field_0)
        {
            this->field_0 = 2;
        }
        this->field_4[2] = tmpScore / 100;
        sub_596A70(1);
        tmpScore %= 100u;
    }

    if (tmpScore >= 10)
    {
        if (!this->field_0)
        {
            this->field_0 = 1;
        }
        this->field_4[1] = tmpScore / 10;
        this->field_4[0] = tmpScore % 10;
    }
    else
    {
        this->field_4[0] = tmpScore;
    }

    this->field_28 = xpos;
    this->field_2C = ypos;
    this->field_30 = zpos;

    this->field_34 = gCokeZero_100_702F34->sub_596860();

    this->field_36 = 25;
    this->field_38 = 2;
    this->field_3C = 1;
    this->field_40 = 1;
}

STUB_FUNC(0x596c90)
s32 CokeZero_50::sub_596C90()
{
    return 0;
}

STUB_FUNC(0x5970c0)
char_type CokeZero_50::sub_5970C0()
{
    return 0;
}

STUB_FUNC(0x597100)
void CokeZero_50::sub_597100(s32 a2, s32 a3)
{
}

MATCH_FUNC(0x5967e0)
CokeZero_100::CokeZero_100()
{
    CokeZero_50* pIter = field_C;
    for (s32 i = 0; i < 3 - 1; i++)
    {
        pIter->field_44 = pIter + 1;
        pIter++;
    }

    field_C[3 - 1].field_44 = 0;
    field_4 = field_C;

    field_8 = 0;
    field_FC_count = 0;
    field_0 = 9;
    field_2 = 3;
}

MATCH_FUNC(0x596840)
CokeZero_100::~CokeZero_100()
{
    field_4 = 0;
    field_8 = 0;
}

MATCH_FUNC(0x596860)
s16 CokeZero_100::sub_596860()
{
    field_0++;
    if (field_0 > 13u)
    {
        field_0 = 9;
    }
    return field_0;
}

MATCH_FUNC(0x596880)
void CokeZero_100::sub_596880()
{
    field_2++;
}

STUB_FUNC(0x596890)
void CokeZero_100::sub_596890(Fix16 a2, Fix16 a3, Fix16 a4, u32 a5)
{
}

STUB_FUNC(0x596940)
void CokeZero_100::sub_596940()
{
}

MATCH_FUNC(0x5969e0)
void CokeZero_100::DrawExploding_5969E0()
{
    CokeZero_50* pIter = field_8;
    while (pIter)
    {
        pIter->sub_596C90();
        pIter = pIter->field_44;
    }
}
