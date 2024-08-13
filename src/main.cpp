#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "Headers/Jogo.hpp"
#include "Headers/Menu.hpp"
#include <time.h>

using namespace sf;
using namespace std;


int main()
{
    srand(time(static_cast<unsigned>(0))); 

    Menu* menu = new Menu();
    menu->runMenu();
    delete menu;
    menu = nullptr;


    return 0;
}