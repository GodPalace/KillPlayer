#include <windows.h>
#include <algorithm>
#include <iostream>
#include "games.h"
#include <vector>
#include <tlhelp32.h>
using namespace std;

string ToLowerCase(const string &str) {
    string temp(str);
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    return temp;
}

struct ProcessInfo {
    string name;
    DWORD pid;
};

vector<ProcessInfo> ListProcessesInfo() {
    vector<ProcessInfo> processList;
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(pe32);

    HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if(hProcessSnap == INVALID_HANDLE_VALUE){
        return processList;
    }

    BOOL bMore = ::Process32First(hProcessSnap, &pe32);
    while (bMore) {
        ProcessInfo info;
        info.name = pe32.szExeFile;
        info.pid = pe32.th32ProcessID;
        processList.push_back(info);
        bMore =::Process32Next(hProcessSnap, &pe32);
    }
    CloseHandle(hProcessSnap);

    return processList;
}

int main() {
    while (true) {
        vector<ProcessInfo> pids = ListProcessesInfo();
        for (int i = 0; i < pids.size(); i++) {
            if (pids[i].pid != 0) {
                string name = pids[i].name;
                for (int j = 0; j < sizeof(games) / sizeof(games[0]); j++) {
                    if (ToLowerCase(name).find(ToLowerCase(games[j])) != string::npos) {
                        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, TRUE, pids[i].pid);
                        if (handle != NULL) {
                            TerminateProcess(handle, 0);
                            CloseHandle(handle);
                        }
                    }
                }
            }
        }
    }
}
