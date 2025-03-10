#include "sprite.hpp"
#include "Globals.hpp"
#include "error.hpp"
#include "memory.hpp"

EXPORT_VAR Sprite_8* gSprite_8_703820;
GLOBAL(gSprite_8_703820, 0x703820);

EXPORT_VAR Sprite_5D598* gSprite_5D598_70381C;
GLOBAL(gSprite_5D598_70381C, 0x70381C);

EXPORT_VAR Sprite_49B28* gSprite_49B28_703818;
GLOBAL(gSprite_49B28_703818, 0x703818);

EXPORT_VAR Sprite_3CC* gSprite_3CC_67AF1C;
GLOBAL(gSprite_3CC_67AF1C, 0x67AF1C);

EXPORT_VAR Sprite_1C24* gSprite_1C24_703B80;
GLOBAL(gSprite_1C24_703B80, 0x703B80);

EXPORT_VAR Sprite* gSprite_703814;
GLOBAL(gSprite_703814, 0x703814);

EXPORT_VAR Sprite* DAT_0066ff18;
GLOBAL(DAT_0066ff18, 0x66ff18);

STUB_FUNC(0x48f600)
char_type* Sprite_3CC::sub_48F600(u16* a2, u32* a3, u32* a4, u16* a5)
{
    return 0;
}

STUB_FUNC(0x48f690)
char_type* Sprite_3CC::sub_48F690(u32* a2)
{
    return 0;
}

STUB_FUNC(0x48f6e0)
s16* Sprite_3CC::sub_48F6E0(u16* a2)
{
    return 0;
}

MATCH_FUNC(0x48f710)
void Sprite_3CC::sub_48F710()
{
    Sprite_14* psVar1 = field_0;
    s32 iVar2 = 0x30;
    do {
        psVar1->field_4 = -1;
        psVar1++;
        iVar2--;
    } while (iVar2 != 0);
}

MATCH_FUNC(0x48f730)
Sprite_3CC::Sprite_3CC()
{
    u32 iVar4;
    field_3C0 = 0;
    field_3C4 = NULL;
    field_3C8 = NULL;

    // By the way this is later used, it seems to be an array of a structure of size 0x40.
    // For now, it's a s32* as it make the code to match.
    s32 *pvVar2 = (s32*)Memory::Aligned_malloc_4FE510(0x40000, (void**)(&field_3C8));
    field_3C4 = pvVar2;

    Sprite_14 *tmp = field_0;
    for(iVar4 = 8; iVar4 != 0; iVar4--, pvVar2 += 0x1000, tmp += 4)
    {
        tmp[0].field_0 = pvVar2;
        tmp[1].field_0 = (pvVar2+0x10);
        tmp[2].field_0 = (pvVar2+0x20);
        tmp[3].field_0 = (pvVar2+0x30);
    }

    tmp = field_0 + 33;
    for(iVar4 = 4; iVar4 != 0; iVar4--, pvVar2 += 0x2000, tmp += 4)
    {
        // I don't know why this one starts at -1...
        // Maybe an artifact of the decompilation
        tmp[-1].field_0 = pvVar2;
        tmp[0].field_0 = (pvVar2+0x10);
        tmp[1].field_0 = (pvVar2+0x20);
        tmp[2].field_0 = (pvVar2+0x30);
    }

    for(u16 uVar1 = 0; uVar1 < 48; uVar1++)
    {
        field_0[uVar1].field_10 = uVar1;
    }
}

STUB_FUNC(0x48F7F0)
Sprite_3CC::~Sprite_3CC()
{
}

MATCH_FUNC(0x5a5860)
void Sprite_8::sub_5A5860()
{
    field_0 = 0;
}

MATCH_FUNC(0x5a5870)
void Sprite_8::sub_5A5870()
{
    DAT_0066ff18 = gSprite_49B28_703818->get_new_sprite();
    DAT_0066ff18->sub_59F950(gFix16_7035C0, gFix16_7035C0, gFix16_7035C0);
}

MATCH_FUNC(0x5a58a0)
Sprite_8::Sprite_8()
{
    gSprite_49B28_703818 = new Sprite_49B28();
    if (gSprite_49B28_703818 == NULL)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\sprite.cpp", 5039);
    }

    gSprite_5D598_70381C = new Sprite_5D598();
    if (gSprite_5D598_70381C == NULL)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\sprite.cpp", 5041);
    }

    gSprite_3CC_67AF1C = new Sprite_3CC();
    if (gSprite_3CC_67AF1C == NULL)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\sprite.cpp", 5043);
    }

    gSprite_1C24_703B80 = new Sprite_1C24();
    if (gSprite_1C24_703B80 == NULL)
    {
        FatalError_4A38C0(32, "C:\\Splitting\\Gta2\\Source\\sprite.cpp", 5046);
    }

    field_0 = 0;
    field_4 = 1;
}

MATCH_FUNC(0x5a5b50)
Sprite_8::~Sprite_8()
{
    GTA2_DELETE_AND_NULL(gSprite_49B28_703818);
    GTA2_DELETE_AND_NULL(gSprite_5D598_70381C);
    GTA2_DELETE_AND_NULL(gSprite_3CC_67AF1C);
    GTA2_DELETE_AND_NULL(gSprite_1C24_703B80);
    gSprite_703814 = 0;
}

MATCH_FUNC(0x5a5c40)
Sprite_18::~Sprite_18()
{
}

MATCH_FUNC(0x5a5c50)
Sprite_18::Sprite_18()
{
    field_10 = 0;
}

MATCH_FUNC(0x5a5c20)
Sprite_1C24::~Sprite_1C24()
{
    field_0 = 0;
}

MATCH_FUNC(0x5a57a0)
s32 Sprite_4C::sub_5A57A0()
{
    field_2C_pNext = NULL;
    field_48 = 0;
    return 0;
}

MATCH_FUNC(0x5a57b0)
Sprite_4C::Sprite_4C()
{
    sub_5A57A0();
}

MATCH_FUNC(0x5a5840)
Sprite_4C::~Sprite_4C()
{
}

MATCH_FUNC(0x5a5be0)
Sprite_5D598::~Sprite_5D598()
{
    field_0_pFree = 0;
}

MATCH_FUNC(0x5A5C00)
Sprite_49B28::~Sprite_49B28()
{
    field_0_first_free = 0;
}

Sprite_49B28::Sprite_49B28()
{
}

MATCH_FUNC(0x5A6ca0)
Sprite* Sprite_18::sub_5A6CA0(s32 a2)
{
    if (field_0 != NULL)
    {
        for (Sprite_18* pNext = (Sprite_18*)field_0; pNext != NULL; pNext = pNext->field_4_next)
        {
            if (pNext->field_0->field_30_sprite_type_enum == a2)
            {
                return pNext->field_0;
            }
        }
    }
    return NULL;
}