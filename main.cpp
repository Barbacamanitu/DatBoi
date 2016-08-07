#include <iostream>
#include "GraphicsWindow.h"
using namespace std;

int main()
{
    GraphicsWindow gWindow;
    gWindow.createWindow();
    gWindow.mainLoop();
    return 0;
}


