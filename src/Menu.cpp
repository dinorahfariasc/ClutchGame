#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Headers/Menu.hpp"
#include "Headers/Jogo.hpp"

using namespace sf;
using namespace std;


Menu::Menu(){
    window = new RenderWindow();
    winclose = new RectangleShape();
    font = new Font();
    image = new Texture();
    bg = new Sprite();
    music = new Music();

}

Menu::~Menu(){
    delete window;
    delete winclose;
    delete font;
    delete image;
    delete bg;
    delete music;
}

void Menu::setValues(){
    window->create(VideoMode(1200, 670), "Shoot 'em up", Style::Close | Style::Titlebar);
    
    pos =0;
    pressed = false;
    font->loadFromFile("Assests/Fonts/MetalSlug.otf");
    image->loadFromFile("Assests/BG/bgMenu2.jpg");

    bg->setTexture(*image);
    posmouse = {0, 0};
    coormouse = {0, 0};

    music->openFromFile("Assests/Sounds/csThemeSong.mp3");
    music->setLoop(true);  // Configura a música para repetir continuamente
    music->play();

    options = {"Shoot 'em up","Jogar", "Opcoes", "Sobre","Sair"};
    texts.resize(5);
    coords = {{80, 70}, {80, 200}, {80, 250}, {80, 300}, {80, 350}};
    sizes = {80, 30, 30, 30, 30};

    // cada nome com seu tamanho e coodenada
    for(size_t i = {}; i < options.size(); i++){
        texts[i].setFont(*font);
        texts[i].setString(options[i]);
        texts[i].setCharacterSize(sizes[i]);
        texts[i].setFillColor(Color::White);
        texts[i].setOutlineColor(Color::Black);
        texts[i].setPosition(coords[i]);
    }
    texts[1].setOutlineThickness(4);
    pos = 1;
}

void Menu::loopEvents(){
    Event event;
    while(window->pollEvent(event)){
        if(event.type == Event::Closed){
            window->close();
        }
        if(event.type == Event::KeyPressed && !pressed){
            if(event.key.code == Keyboard::Down){
                if(pos < 4){
                    ++pos;
                    pressed = true;
                    texts[pos].setOutlineThickness(4);
                    texts[pos-1].setOutlineThickness(0);
                    pressed = false;
                    theselected = false;
                     
                }
            }
        }
        if(event.type == Event::KeyPressed && !pressed){
            if(event.key.code == Keyboard::Up){
                if(pos > 1){
                    --pos;
                    pressed = true;
                    texts[pos].setOutlineThickness(4);
                    texts[pos+1].setOutlineThickness(0);
                    pressed = false;
                    theselected = false;
                }
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Enter) && !theselected){
            theselected = true;
            if (pos == 1){
                music->stop();
                window->close();
                Jogo* jogo = new Jogo();
                jogo->run();
                delete jogo;
                jogo = nullptr;
                
            }
            if (pos == 4){
                window->close();
            }
        }

    }
}

void Menu::drawAll(){
    window->clear();
    window->draw(*bg);
    for(auto t : texts){
        window->draw(t);
    }
    window->display();
}

void Menu::runMenu(){
    setValues();
    while(window->isOpen()){
        loopEvents();
        drawAll();
    }
}