#include <windows.h>

int main()
{
    LPSYSTEM_POWER_STATUS powerStatus = (LPSYSTEM_POWER_STATUS)malloc(sizeof(LPSYSTEM_POWER_STATUS));
    HDC screen = GetDC(0);
    HBRUSH brush = CreateSolidBrush(RGB(255, 0, 0));
    RECT r { 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
    while (true)
    {
        if (GetSystemPowerStatus(powerStatus))
        {
            if (powerStatus->ACLineStatus == 0)
            {
                FillRect(screen, &r, brush);
            }
        }
    }
    ReleaseDC(0, screen);
    free(powerStatus);
    return 0;
}