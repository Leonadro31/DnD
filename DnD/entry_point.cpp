#include "src/DnD.h"
#ifdef _WIN64
#include <Windows.h>
#endif

#define HIDE_CONSOLE 0

int main()
{

#if HIDE_CONSOLE
    ShowWindow(GetConsoleWindow(), SW_HIDE);
#else
    ShowWindow(GetConsoleWindow(), SW_SHOW);
#endif
    std::cout << "Test\n";
    DnD dnd(500, 500, "Dungeons & Dragons Character Sheet Builder");
    dnd.main();

    return 0;
}