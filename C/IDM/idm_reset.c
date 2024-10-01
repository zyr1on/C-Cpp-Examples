#include <windows.h>
#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 255

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
	if (key != NULL) {
    	sprintf(keyPath,"%s\\WOW6432Node\\CLSID\\{07999AC3-058B-40BF-984F-69EB1E554CA7}",key);
	    free(key);
    }
    printf("%s\n",keyPath);
    
    HKEY hKey;
    LONG result = RegOpenKeyEx(HKEY_USERS, keyPath, 0, KEY_READ, &hKey);
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
