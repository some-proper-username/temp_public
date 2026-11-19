#include <windows.h>
#include <stdio.h>

int main(void)
{
    HKEY hKey;
    LSTATUS status;

    const wchar_t *keyPath =
        L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce";

    const wchar_t valueName[] =
        L"";

    const wchar_t command[] =
        L"notepad.exe \"C:\\Temp\\\"";

    status = RegOpenKeyExW(
        HKEY_LOCAL_MACHINE,
        keyPath,
        0,
        KEY_SET_VALUE,
        &hKey
    );

    if (status != ERROR_SUCCESS) {
        printf("RegOpenKeyExW failed: %ld\n", status);
        return 1;
    }

    status = RegSetValueExW(
        hKey,
        valueName,
        0,
        REG_SZ,
        (const BYTE *)command,
        sizeof(command)
    );

    RegCloseKey(hKey);

    if (status != ERROR_SUCCESS) {
        printf("RegSetValueExW failed: %ld\n", status);
        return 1;
    }

    printf("RunOnce value successfully created.\n");
    return 0;
}
