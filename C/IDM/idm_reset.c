#include <windows.h>
#include <stdio.h>
#include <string.h>
#include<tlhelp32.h>
#define MAX_KEY_LENGTH 255

DWORD GetProcessID(const char *processName) {
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE)
        return 0;
    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    if (Process32First(hSnapshot, &pe32)) {
        do {
            if (strcmp(pe32.szExeFile, processName) == 0) {
                DWORD processID = pe32.th32ProcessID;
                CloseHandle(hSnapshot);
                return processID;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }
    CloseHandle(hSnapshot);
    return 0;
}

char* EnumerateKeys(HKEY hKeyRoot) {
    HKEY hKey;
    char* dest = NULL;
    if (RegOpenKeyEx(hKeyRoot, "", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        CHAR    achKey[MAX_KEY_LENGTH];   
        DWORD   cbName;                    
        DWORD   cSubKeys;                  
        DWORD   i;
        cSubKeys = 0;
        if (RegQueryInfoKey(hKey, NULL, NULL, NULL, &cSubKeys, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
            for (i = 0; i < cSubKeys; i++) {
                cbName = MAX_KEY_LENGTH;
                if (RegEnumKeyEx(hKey, i, achKey, &cbName, NULL, NULL, NULL, NULL) == ERROR_SUCCESS) {
                    if (strstr(achKey, "_Classes") != NULL) { 
						dest = (char*)malloc(strlen(achKey) + 1);
						strcpy(dest, achKey);
						break;
				    }
                }
            }
        }
        RegCloseKey(hKey);
    }
    return dest;
}

int main() {
    char* key = EnumerateKeys((HKEY)HKEY_USERS);
    char keyPath[255];
    const char* targetProcess = "IDMan.exe";
	if (key != NULL) {
    	sprintf(keyPath,"%s\\WOW6432Node\\CLSID\\{07999AC3-058B-40BF-984F-69EB1E554CA7}",key);
	    free(key);
    }
    printf("%s\n",keyPath);
    DWORD processID = GetProcessID(targetProcess);
    LONG result = RegOpenKeyEx(HKEY_USERS, keyPath, 0, KEY_READ, &hKey);
    HKEY hKey;
    if(processID == 0) 
    {
        printf("'%s' was not found or not working.\n",targetProcess);
    }
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE,FALSE,processID);
    if (hProcess == NULL) {
        printf("Failed to open the process. Error code: %lu\n", GetLastError());
    }
    if(TerminateProcess(hProcess,0)) 
    {
        MessageBox(NULL, "IDMan.exe process terminated.", "Success", MB_ICONINFORMATION);
    }
    else {
        printf("'%s' Failed to terminate the process.",targetProcess);
    }
    CloseHandle(hProcess);
    if (result == ERROR_SUCCESS) {
        int result_ = MessageBox(NULL, "Key Found! Are you want to delete key", keyPath, MB_YESNO | MB_ICONEXCLAMATION);
        if(result_ == IDYES) {
    		result = RegDeleteKey(HKEY_USERS, keyPath);
        	if (result == ERROR_SUCCESS) {
            	MessageBox(NULL, "Succesfuly deleted", "Succesfull", MB_OK | MB_ICONINFORMATION);
        		int result_ = MessageBox(NULL, "Are you want to restart computer", "Restart", MB_YESNO | MB_ICONQUESTION);
        		if(result_ == IDYES) {
        			RegCloseKey(hKey);
					//ExitWindowsEx(EWX_REBOOT, 0); didn't work idk why.
					system("shutdown.exe /r");
				}
			} else
            	MessageBox(NULL, "Unsuccesfull", "Error!", MB_OK | MB_ICONERROR);
		}
        RegCloseKey(hKey);
    } else
        MessageBox(NULL, "Key not Found!", "Error!", MB_OK | MB_ICONERROR);
    return 0;
}
