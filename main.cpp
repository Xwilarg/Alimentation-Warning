#include <windows.h>

int main()
{
    LPSYSTEM_POWER_STATUS powerStatus = new SYSTEM_POWER_STATUS();
    HDC screen = GetDC(0);
    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
    RECT r { 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
    bool needClean = false;
    while (true)
    {
        if (GetSystemPowerStatus(powerStatus))
        {
            if (powerStatus->ACLineStatus == 0)
            {
                FillRect(screen, &r, brush);
                needClean = true;
            }
            else if (needClean)
            {
                InvalidateRect(0, &r, TRUE);
                UpdateWindow(0);
                needClean = false;
            }
        }
        Sleep(500);
    }
    ReleaseDC(0, screen);
    delete powerStatus;
    return 0;
}