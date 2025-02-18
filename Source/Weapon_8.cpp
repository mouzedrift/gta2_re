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
Weapon_30* Weapon_8::sub_5E3C10(s32 a2, Ped* pPed, u8 ammo)
{
    Weapon_30* pNewWeap = gWeapon_2FDC_707014->field_0;
    gWeapon_2FDC_707014->field_0 = gWeapon_2FDC_707014->field_0->field_18;
    pNewWeap->field_18 = 0;
    pNewWeap->sub_5DCD90();
    field_4++;
    pNewWeap->field_1C_idx = a2;
    pNewWeap->field_24_pObj = pPed;
    pNewWeap->sub_5DCE20(ammo);
    return pNewWeap;
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

MATCH_FUNC(0x5E4090)
Weapon_2FDC::~Weapon_2FDC()
{
    field_0 = 0;
    field_4 = 0;
}