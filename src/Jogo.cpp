#include "Headers/Jogo.hpp"
#include "Jogo.hpp"

// --------------------------------- FUNCOES PRIVADAS ------------------------------------
void Jogo::initWindow(){
    this->window = new RenderWindow(VideoMode(800, 600), "Shoothemup", Style::Close | Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

// --------------------------------- CONST/DEST ---------------------------------------
Jogo::Jogo()
{
    
    this->initWindow();
}

Jogo::~Jogo()
{
    delete this->window;
}

// --------------------------------------- FUNCOES ---------------------------------------
void Jogo::run()
{

    while(this->window->isOpen())
    {
        this->update();
        this->render();
    }
   
}
void Jogo::update()
{
    Event e;
    while(this->window->pollEvent(e))
    {
        if(e.type == Event::Closed)
            this->window->close();
        if (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)
        {
            this->window->close();
        }
    } 

}

void Jogo::render()
{
    this->window->clear(Color::Black);
    // draw all the stuffs


    this->window->display();
    
}
