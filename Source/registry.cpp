#include "stdafx.h"
#include "registry.hpp"
#include "error.hpp"
#include <windows.h>
#include <stdio.h>

HKEY dword_625018 = HKEY_LOCAL_MACHINE;

Registry gRegistry_6FF968;

// match
bool Registry::Open_Sound_Root_586A00(PHKEY phkResult)
{
    if (::RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\DMA Design Ltd\\GTA2\\Sound", 0, KEY_ALL_ACCESS, phkResult) != ERROR_SUCCESS)
    {
        DWORD dwDisposition;

        if (::RegCreateKeyExA(
            HKEY_LOCAL_MACHINE,
            "SOFTWARE\\DMA Design Ltd\\GTA2\\Sound",
            0,
            "", //byte_67DC88,
            0,
            KEY_ALL_ACCESS,
            NULL,
            phkResult,
            &dwDisposition) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(43, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 58);
        }
        return false;
    }
    return true;
}

// match
bool Registry::Get_Sound_Settting_586A70(const char *lpValueName)
{
    HKEY hKey;
    DWORD cbData;
    unsigned char data[4];

    bool settingReadOK = false;
    if (Open_Sound_Root_586A00(&hKey))
    {
        cbData = 4;
        if (::RegQueryValueExA(hKey, lpValueName, 0, 0, data, &cbData) == ERROR_SUCCESS)
        {
            settingReadOK = true;
        }
    }

    if (::RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 109);
    }
    return settingReadOK;
}

// match
int Registry::Set_Sound_Setting_586AE0(const char *lpValueName, int value)
{
    HKEY hKey;
    Open_Sound_Root_586A00(&hKey);

    DWORD cbData = sizeof(DWORD);
    DWORD data;
    if (::RegQueryValueExA(hKey, lpValueName, 0, 0, reinterpret_cast<BYTE*>(&data), &cbData) != ERROR_SUCCESS)
    {
        if (::RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, reinterpret_cast<const BYTE *>(&value), sizeof(DWORD)) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 138);
        }

        data = value;
    }

    if (::RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 146);
    }

    return data;
}

// match
void Registry::Set_Sound_Setting_586B80(const char* lpValueName, int Data)
{
    HKEY hKey;
    if (Open_Sound_Root_586A00(&hKey))
    {
        if (RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, reinterpret_cast<const BYTE*>(&Data), sizeof(DWORD)) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 169);
        }
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 175);
    }

}

// match
void Registry::Clear_Or_Delete_Sound_Setting_586BF0(const char* lpValueName, char bClear)
{
    HKEY hKey;
    DWORD Data = 0;
    if (Open_Sound_Root_586A00(&hKey))
    {
        if (bClear)
        {
            RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, reinterpret_cast<const BYTE*>(&Data), sizeof(DWORD));
            // note: wrong register fixed by adding else instead of early return + dup'ed close call
        }
        else
        {
            RegDeleteValueA(hKey, lpValueName);
        }
    }
    RegCloseKey(hKey); // bug: closes even if open fails
}

// match
char Registry::Open_Debug_Root_586C60(PHKEY phkResult)
{
    DWORD dwDisposition;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\DMA Design Ltd\\GTA2\\Debug", 0, KEY_ALL_ACCESS, phkResult) != ERROR_SUCCESS)
    {
        if (RegCreateKeyExA(
            HKEY_LOCAL_MACHINE,
            "SOFTWARE\\DMA Design Ltd\\GTA2\\Debug",
            0,
            "", //byte_67DC88,
            0,
            KEY_ALL_ACCESS,
            0,
            phkResult,
            &dwDisposition) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(43, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 232);
        }
        return 0;
    }
    return 1;
}

// match
char Registry::Open_Options_Root_586CD0(PHKEY phkResult)
{
    DWORD dwDisposition;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\DMA Design Ltd\\GTA2\\Option", 0, KEY_ALL_ACCESS, phkResult) != ERROR_SUCCESS)
    {
        if (RegCreateKeyExA(
            HKEY_LOCAL_MACHINE,
            "SOFTWARE\\DMA Design Ltd\\GTA2\\Option",
            0,
            "", //byte_67DC88,
            0,
            KEY_ALL_ACCESS,
            0,
            phkResult,
            &dwDisposition) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(43, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 265);
        }
        return 0;
    }
    return 1;
}

// match
char Registry::Open_Control_Root_586D40(PHKEY phkResult)
{
    DWORD dwDisposition;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\DMA Design Ltd\\GTA2\\Control", 0, KEY_ALL_ACCESS, phkResult) != ERROR_SUCCESS)
    {
        if (RegCreateKeyExA(
            HKEY_LOCAL_MACHINE,
            "SOFTWARE\\DMA Design Ltd\\GTA2\\Control",
            0,
            "", //byte_67DC88,
            0,
            KEY_ALL_ACCESS,
            0,
            phkResult,
            &dwDisposition) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(43, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 298);
        }
        return 0;
    }
    return 1;
}

// match
char Registry::Open_Screen_Root_586DB0(PHKEY phkResult)
{
    DWORD dwDisposition;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\DMA Design Ltd\\GTA2\\Screen", 0, KEY_ALL_ACCESS, phkResult) != ERROR_SUCCESS)
    {
        if (RegCreateKeyExA(
            HKEY_LOCAL_MACHINE,
            "SOFTWARE\\DMA Design Ltd\\GTA2\\Screen",
            0,
            "", //byte_67DC88,
            0,
            KEY_ALL_ACCESS,
            0,
            phkResult,
            &dwDisposition))
        {
            FatalError_4A38C0(43, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 331);
        }
        return 0;
    }
    return 1;
}

// match
bool Registry::Get_Debug_Setting_586E20(const char *lpValueName)
{
    bool bRead = false;
    HKEY hKey;
    DWORD Data;
    if (Open_Debug_Root_586C60(&hKey))
    {
        DWORD cbData = sizeof(DWORD);
        if (RegQueryValueExA(hKey, lpValueName, 0, 0, reinterpret_cast<BYTE*>(&Data), &cbData) == ERROR_SUCCESS)
        {
            bRead = 1;
        }
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 424);
    }

    return bRead;
}

// match
void Registry::Get_Debug_Setting_586E90(const char* lpValueName, LPBYTE lpData, int a3)
{
    HKEY hKey;
    DWORD cbData;
    if (Open_Debug_Root_586C60(&hKey))
    {
        cbData = static_cast<unsigned short>(a3);
        RegQueryValueExA(hKey, lpValueName, 0, 0, lpData, &cbData);
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 531);
    }

}

// match
void Registry::Get_Option_586F00(const char* lpValueName, BYTE *pBuffer, int bufferSize)
{
    DWORD cbData;
    HKEY hKey;
    *pBuffer = 0;

    if (Open_Options_Root_586CD0(&hKey))
    {
        cbData = static_cast<unsigned short>(bufferSize);
        RegQueryValueExA(hKey, lpValueName, 0, 0, pBuffer, &cbData);
    }

    // bug: closing key even if not opened
    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 586);
    }
}

// match
int Registry::Set_Option_586F70(const char *lpValueName, int a3)
{
    HKEY hKey;
    DWORD Data;

    Open_Options_Root_586CD0(&hKey);

    DWORD cbData = sizeof(DWORD);

    if (RegQueryValueExA(hKey, lpValueName, 0, 0, reinterpret_cast<BYTE*>(&Data), &cbData) != ERROR_SUCCESS)
    {
        if (RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, reinterpret_cast<const BYTE *>(&a3), sizeof(DWORD)) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 622);
        }
        Data = a3;
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 629);
    }

    return Data;
}

// match
int Registry::Set_Control_Setting_587010(int a1, int a2)
{
    HKEY hKey;
    DWORD Data;
    Open_Control_Root_586D40(&hKey);

    DWORD cbData = sizeof(DWORD);
    char ValueName[4];
    sprintf(ValueName, "%d", static_cast<BYTE>(a1));

    if (RegQueryValueExA(hKey, ValueName, 0, 0, reinterpret_cast<BYTE*>(&Data), &cbData) != ERROR_SUCCESS)
    {
        if (RegSetValueExA(hKey, ValueName, 0, REG_DWORD, reinterpret_cast<const BYTE *>(&a2), sizeof(DWORD)) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 667);
        }
        Data = a2;
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 674);
    }

    return Data;
}

// match
int Registry::Get_Screen_Setting_5870D0(const char *lpValueName, int a2)
{
    HKEY hKey;
    Open_Screen_Root_586DB0(&hKey);

    DWORD Data;
    DWORD cbData = sizeof(DWORD);
    if (RegQueryValueExA(hKey, lpValueName, 0, 0, reinterpret_cast<BYTE*>(&Data), &cbData) != ERROR_SUCCESS)
    {
        if (RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, reinterpret_cast<const BYTE *>(&a2), sizeof(DWORD)) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 709);
        }
        Data = a2;
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 716);
    }

    return Data;
}

// nomatch 0x587290
Registry::Registry()
{

}

// match
char Registry::sub_5872A0(HKEY hKey, const char *a2, BYTE *lpData, DWORD Data)
{
    char Buffer[260];
    char ret = 0;

    sprintf(Buffer, "%ss", a2);
    if (RegSetValueExA(hKey, Buffer, 0, REG_DWORD, reinterpret_cast<const BYTE *>(&Data), sizeof(DWORD)) == ERROR_SUCCESS)
    {
        sprintf(Buffer, "%sd", a2);
        if (RegSetValueExA(hKey, Buffer, 0, REG_BINARY, lpData, Data) == ERROR_SUCCESS)
        {
            ret = 1;
        }
    }
    return ret;
}

// match
bool Registry::sub_587340(HKEY hKey, const char *keyPath, int value, LPBYTE lpData)
{
    char ValueName[260]; // [esp+14h] [ebp-104h] BYREF
    bool ret = false;

    sprintf(ValueName, "%ss", keyPath);
    DWORD v = Get_Int_Setting_5874E0(hKey, ValueName);
    if (v == static_cast<DWORD>(value))
    {
        sprintf(ValueName, "%sd", keyPath);
        ret = RegQueryValueExA(hKey, ValueName, 0, 0, lpData, &v) == ERROR_SUCCESS;
    }
    return ret;
}

// match
int Registry::Get_Int_5873E0(HKEY hKey, const char *subKey)
{
    char keyPath[260];
    sprintf(keyPath, "%ss", subKey);
    return Get_Int_Setting_5874E0(hKey, keyPath);
}

// match
char Registry::CreateNetworkRoot_587420(PHKEY phkResult)
{
    DWORD dwDisposition;
    CHAR SubKey[260];

    strcpy(SubKey, "SOFTWARE\\DMA Design Ltd\\GTA2");
    strcat(SubKey, "\\Network");

    if (RegCreateKeyExA(dword_625018, SubKey, 0, "", 0, KEY_ALL_ACCESS, 0, phkResult, &dwDisposition) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(43, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 910);
    }

    return 1;
}

// nomatch
DWORD Registry::Get_Int_Setting_5874E0(HKEY hKey, const char* lpValueName)
{
    DWORD valueData;

    DWORD cbData = sizeof(DWORD);
    DWORD dataType;
    DWORD ret;
    DWORD err = RegQueryValueExA(hKey, lpValueName, 0, &dataType, reinterpret_cast<BYTE*>(&valueData), &cbData);
    if (err == ERROR_SUCCESS)
    {
        // the double return is removed without the printf, ran out of ideas to try
        printf("meh");
        return ( int)valueData;
    }
    else
    {
       ret = 0;
        err = 0;
        valueData = 99;
        cbData = 0;
        return ret;
    }
}

// match
int Registry::Set_Network_Setting_587690(const char *lpValueName, int a2)
{
    HKEY hKey;
    CreateNetworkRoot_587420(&hKey);

    DWORD Data;
    DWORD cbData = sizeof(DWORD);
    if (RegQueryValueExA(hKey, lpValueName, 0, 0, reinterpret_cast<BYTE*>(&Data), &cbData) != ERROR_SUCCESS)
    {
        if (RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, reinterpret_cast<const BYTE *>(&a2), sizeof(DWORD)) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 1051);
        }
        Data = a2;
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 1058);
    }

    return Data;
}

// match
void Registry::Set_Network_Setting_587730(const char* lpValueName, BYTE Data)
{
    HKEY hKey;
    if (CreateNetworkRoot_587420(&hKey))
    {
        if (RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, &Data, sizeof(DWORD)))
        {
            FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 1080);
        }
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 1086);
    }
}

// match
char Registry::Open_Player_Root_5877A0(PHKEY phkResult)
{
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\DMA Design Ltd\\GTA2\\Player", 0, KEY_ALL_ACCESS, phkResult) != ERROR_SUCCESS)
    {
        DWORD dwDisposition;
        if (RegCreateKeyExA(
            HKEY_LOCAL_MACHINE,
            "SOFTWARE\\DMA Design Ltd\\GTA2\\Player",
            0,
            "",
            0,
            KEY_ALL_ACCESS,
            0,
            phkResult,
            &dwDisposition) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(43, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 1110);
        }
        return 0;
    }
    return 1;
}

// match
int Registry::Create_Player_Setting_587810(const char* lpValueName)
{
    HKEY hKey;
    DWORD Data;
    if (Open_Player_Root_5877A0(&hKey))
    {
        DWORD cbData = sizeof(DWORD);
        if (RegQueryValueExA(hKey, lpValueName, 0, 0, reinterpret_cast<BYTE*>(&Data), &cbData) != ERROR_SUCCESS)
        {
            Data = 0;
        }
    }
    else
    {
        Data = 0;
        if (RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, reinterpret_cast<BYTE*>(&Data), sizeof(DWORD)) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 1143);
        }
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 1149);
    }

    return Data;
}

// match
void Registry::Set_Player_Setting_5878C0(const char* lpValueName, BYTE Data)
{
    HKEY hKey;
    if (Open_Player_Root_5877A0(&hKey))
    {
        if (RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, &Data, sizeof(DWORD)) != ERROR_SUCCESS)
        {
            FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 1171);
        }
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 1177);
    }
}

// match
void Registry::Set_Screen_Setting_587170(const char* lpValueName, int Data)
{
    HKEY hKey;
    Open_Screen_Root_586DB0(&hKey);

    if (RegSetValueExA(hKey, lpValueName, 0, REG_DWORD, reinterpret_cast<BYTE*>(&Data), sizeof(DWORD)) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 743);
    }

    if (RegCloseKey(hKey) != ERROR_SUCCESS)
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 745);
    }
}

// nomatch
void Registry::Set_Screen_Setting_5871E0(const char *lpValueName, BYTE *lpData, unsigned __int16 maxLen)
{
    HKEY hKey; // [esp+8h] [ebp-8h] BYREF
    DWORD cbData; // [esp+Ch] [ebp-4h] BYREF

    Open_Screen_Root_586DB0(&hKey);

    cbData = maxLen;
    if (RegQueryValueExA(hKey, lpValueName, 0, 0, lpData, &cbData)
        && RegSetValueExA(hKey, lpValueName, 0, 1u, lpData, strlen((const char *)lpData) + 1))
    {
        FatalError_4A38C0(46, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 781);
    }

    if (RegCloseKey(hKey))
    {
        FatalError_4A38C0(42, "C:\\Splitting\\Gta2\\Source\\registry.cpp", 787);
    }
}
