#include "TrafficLights_194.hpp"
#include "Garox_2B00.hpp"
#include "Globals.hpp"
#include "map_0x370.hpp"

// TODO
EXPORT_VAR extern wchar_t tmpBuff_67BD9C[640];

EXPORT_VAR TrafficLights_194* gTrafficLights_194_705958;
GLOBAL(gTrafficLights_194_705958, 0x705958);

u8 traffic_light_phase_timers_626840[] = {0x00, 0x64, 0x18, 0x18, 0x64, 0x18, 0x18, 0x96, 0x50, 0x00, 0x00, 0x00};

STUB_FUNC(0x5C1D00)
void TrafficLight_20::sub_5C1D00(u8 a2, u8 a3, u8 a4, u8 a5)
{

}

MATCH_FUNC(0x5c2910)
void TrafficLights_194::sub_5C2910(u8 x, u8 y, u8 w, u8 h)
{
    TrafficLight_20* pMem = new TrafficLight_20();
    field_0_traffic_lights[field_190_array_used_count++] = pMem;
    pMem->sub_5C1D00(x, y, w, h);
}

STUB_FUNC(0x5c2950)
void TrafficLights_194::sub_5C2950()
{
}

MATCH_FUNC(0x5c2a10)
void TrafficLights_194::ShowTrafficLightsInfo_5C2A10()
{
    swprintf(tmpBuff_67BD9C, L"timer: %d", field_193_timer);
    gGarox_2B00_706620->field_DC.field_650.sub_5D1F50(tmpBuff_67BD9C, -1, 0, word_706600, 1);

    swprintf(tmpBuff_67BD9C, L"phase: %d", field_192_phase);
    gGarox_2B00_706620->field_DC.field_650.sub_5D1F50(tmpBuff_67BD9C, -1, 16, word_706600, 1);

    if (field_192_phase == 7)
    {
        gGarox_2B00_706620->field_DC.field_650.sub_5D1F50(L"peds crossing now!", -1, 32, word_706600, 1);
    }
}

MATCH_FUNC(0x5c2ac0)
void TrafficLights_194::sub_5C2AC0()
{
    gmp_map_zone* pZoneIter = gMap_0x370_6F6268->first_zone_by_type_4DF1D0(2u);
    while (pZoneIter)
    {
        sub_5C2910(pZoneIter->field_1_x, pZoneIter->field_2_y, pZoneIter->field_3_w, pZoneIter->field_4_h);
        pZoneIter = gMap_0x370_6F6268->next_zone_4DF770();
    }
}

MATCH_FUNC(0x5c2b00)
TrafficLights_194::TrafficLights_194()
{
    field_190_array_used_count = 0;
    for (s32 i = 0; i < GTA2_COUNTOF(field_0_traffic_lights); i++)
    {
        field_0_traffic_lights[i] = 0;
    }
    field_192_phase = 1;
    field_193_timer = traffic_light_phase_timers_626840[1];
}

MATCH_FUNC(0x5c2b30)
TrafficLights_194::~TrafficLights_194()
{
    for (u32 i = 0; i < field_190_array_used_count; i++)
    {
        if (field_0_traffic_lights[i])
        {
            GTA2_DELETE_AND_NULL(field_0_traffic_lights[i]);
        }
    }
}
