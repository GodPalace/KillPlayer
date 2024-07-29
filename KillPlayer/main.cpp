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
        for (const auto& process : pids) {
            if (process.pid != 0) {
                string name = process.name;
                for (int j = 0; j < sizeof(games) / sizeof(games[0]); j++) {
                    cout << "KillPlayer [INFO] : checking process[" << process.name << "][" << process.pid << "]" << endl;

                    if (ToLowerCase(name).find(ToLowerCase(games[j])) != string::npos) {
                        cout << "KillPlayer [INFO] : found a process" << endl;
                        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, TRUE, process.pid);
                        if (handle != nullptr) {
                            TerminateProcess(handle, 0);
                            cout << "KillPlayer [INFO] : successful kill process[" << process.pid << "]"  << endl;
                            CloseHandle(handle);
                        } else {
                            cerr << "KillPlayer [ERROR] : Cannot kill process" << endl;
                        }
                    }
                }
            }
        }
    }
}
