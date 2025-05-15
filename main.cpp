#include <iostream>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <locale.h>
#endif
#include "import/import.h"
#include "menu/menu.h"
#include "Pokemon/Pokemon.h"
using namespace std;

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #else
        setlocale(LC_ALL, "en_US.UTF-8"); 
    #endif
    import();
    mainMenu();
    return 0;
}


// TO DO LIST
// - verifier les const
// - adapter à linux
// - fix bug execution
