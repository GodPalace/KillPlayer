#include <windows.h>

typedef DWORD(*LPREGISTERSERVICEPROCESS)(DWORD, DWORD);
int main() {
    HINSTANCE hDLL;
    LPREGISTERSERVICEPROCESS lpRegisterServiceProcess;

    hDLL = LoadLibrary(reinterpret_cast<LPCSTR>(L"KERNEL32"));

    lpRegisterServiceProcess = (LPREGISTERSERVICEPROCESS) GetProcAddress(hDLL, "RegisterServiceProcess");

    lpRegisterServiceProcess(GetCurrentProcessId(), 1);

    FreeLibrary(hDLL);
}
