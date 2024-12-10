#include <windows.h>


int ONLY_LEFT = 0;
int WAY = 10;


void ShakeWindow(HWND hwnd) 
{
    RECT rect;
    GetWindowRect(hwnd, &rect);
    
    
    SetWindowPos(hwnd, NULL, rect.left + WAY, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    // Sleep(1);
    if (ONLY_LEFT == 0) SetWindowPos(hwnd, NULL, rect.left, rect.top, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    return;
}


BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) 
{
    if (IsWindowVisible(hwnd)) 
    {
        ShakeWindow(hwnd);
    }
    return TRUE;
}



int main(int argc, char* argv[]) 
{
    if (argc > 1) 
    {
        ONLY_LEFT = atoi(argv[1]);
    }


    if (argc > 2)
    {
        WAY = atoi(argv[2]);
    }


    while (1)
    {
        EnumWindows(EnumWindowsProc, 0);
    }
    
    return 0;
}
