#include "Headers/Jogo.hpp"
#include "Jogo.hpp"


// --------------------------------- FUNCOES PRIVADAS ------------------------------------
void Jogo::initWindow(){
    this->window = new RenderWindow(VideoMode(800, 600), "Shoothemup", Style::Close | Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}


void Jogo::initAtirador()
{
    this->atirador = new Atirador();
}


// --------------------------------- CONST/DEST ---------------------------------------
Jogo::Jogo()
{
   
    this->initWindow();
    this->initAtirador();
   
}


Jogo::~Jogo()
{
    delete this->window;
    delete this->atirador;
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
void Jogo::updatePollEvents()
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


void Jogo::updateImput()
{
    // Mover Jogador
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        this->atirador->move(-1.f, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        this->atirador->move(1.f, 0.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        this->atirador->move(0.f, -1.f);
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        this->atirador->move(0.f, 1.f);
    }
}


void Jogo::update()
{
   this->updatePollEvents();


   this->updateImput();
}


void Jogo::render()
{
    this->window->clear(Color::Black);
   
    // desenhe todas as coisas
    this->atirador->render(this->window);


    this->window->display();


}


