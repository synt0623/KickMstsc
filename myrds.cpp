#pragma comment(lib, "User32.lib")

#include <windows.h>
#include <string>
#include <iostream>

int main(){

    // あああ
    int x = GetSystemMetrics(SM_CXFULLSCREEN);
    int y = GetSystemMetrics(SM_CYFULLSCREEN);

    
    int monitor_x = GetSystemMetrics(SM_CXSCREEN);
    int monitor_y = GetSystemMetrics(SM_CYSCREEN);
    const wchar_t mstsc[] = L"C:\\Windows\\System32\\mstsc.exe";
    

    
    std::wstring op;
    
    if( (monitor_x < 1920) || (monitor_y < 1280) ){
        op = mstsc;
        op += L" /f";
        //op += L" /w:640 /h:480";
    }else{

        op = mstsc;
        op += L" /w:1920 /h:1280";
    }

    
    //std::wcout << op <<std::endl;
    STARTUPINFO si{};
    PROCESS_INFORMATION pi{};
    CreateProcess(NULL,(wchar_t*)op.c_str(),
                  NULL,NULL,false,0,NULL,NULL,&si,&pi);
    return 0;
}

