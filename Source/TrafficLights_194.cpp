#include "TrafficLights_194.hpp"
#include "Globals.hpp"

EXPORT_VAR TrafficLights_194* gTrafficLights_194_705958;
GLOBAL(gTrafficLights_194_705958, 0x705958);

u8 traffic_light_phase_timers_626840[] = {0x00, 0x64, 0x18, 0x18, 0x64, 0x18, 0x18, 0x96, 0x50, 0x00, 0x00, 0x00};

STUB_FUNC(0x5c2910)
void TrafficLights_194::sub_5C2910(u8 x, u8 y, u8 w, u8 h)
{
}

STUB_FUNC(0x5c2950)
void TrafficLights_194::sub_5C2950()
{
}

STUB_FUNC(0x5c2a10)
void TrafficLights_194::ShowTrafficLightsInfo_5C2A10()
{
}

STUB_FUNC(0x5c2ac0)
void TrafficLights_194::sub_5C2AC0()
{
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

STUB_FUNC(0x5c2b30)
TrafficLights_194::~TrafficLights_194()
{
}
