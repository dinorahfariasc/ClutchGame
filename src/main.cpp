#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include "Headers/Jogo.hpp"
#include "Headers/Menu.hpp"

using namespace sf;
using namespace std;


int main() {
    // Jogo jogo;

    // jogo.run();

    Menu* menu = new Menu();
    menu->runMenu();
    delete menu;
    menu = nullptr;


    return 0;
}