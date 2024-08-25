#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Headers/Menu.hpp"
#include "Headers/GameOver.hpp"
#include "Headers/Jogo.hpp"

using namespace sf;
using namespace std;


GameOver::GameOver(){
    window = new RenderWindow();
    winclose = new RectangleShape();
    font = new Font();
    image = new Texture();
    bg = new Sprite();
    music = new Music();

}

GameOver::~GameOver(){
    delete window;
    delete winclose;
    delete font;
    delete image;
    delete bg;
    delete music;
}

void GameOver::setValues(){
    window->create(VideoMode(800, 800), "Clutch", Style::Close | Style::Titlebar);
    
    pos = 0;
    pressed = false;
    font->loadFromFile("Assests/Fonts/MetalSlug.otf");
    //image->loadFromFile("Assests/BG/bgMenu2.jpg");

    //bg->setTexture(*image);
    posmouse = {0, 0};
    coormouse = {0, 0};

    music->openFromFile("Assests/Sounds/csThemeSong.mp3");
    music->setLoop(true);  // Configura a música para repetir continuamente
    music->play();

    options = {"Game Over !","Aperte qualquer tecla para voltar ao menu"};
    texts.resize(5);
    coords = {{280, 350},{130, 420}};
    sizes = {50, 30};

    
    // cada nome com seu tamanho e coodenada
    for(size_t i = {}; i < options.size(); i++){
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setFillColor(Color::Red);
        //texts[i].setOutlineColor(Color::White);
        texts[i].setPosition(coords[i]);
    }
    texts[1].setOutlineThickness(4);
    pos = 1;
}

void GameOver::loopEvents(){
    Event event;
    while(window->pollEvent(event)){
        if(event.type == Event::Closed){
            window->close();
        }
        if (event.type == sf::Event::KeyPressed){
            if (pos == 1){
                music->stop();
                Menu* menu = new Menu();
                window->close();
                menu->runMenu();
                delete menu;
                menu = nullptr;
            }
            
        }

    }
}

void GameOver::drawAll(){
    window->clear();
    for(auto t : texts){
        window->draw(t);
    }
    window->display();
}

void GameOver::runGameOver(){
    setValues();
    while(window->isOpen()){
        loopEvents();
        drawAll();
    }
}