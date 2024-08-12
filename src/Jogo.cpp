#include "Headers/Jogo.hpp"
#include "Jogo.hpp"


// --------------------------------- FUNCOES PRIVADAS ------------------------------------
void Jogo::initWindow(){
    this->window = new RenderWindow(VideoMode(800, 600), "Shoothemup", Style::Close | Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);
}

void Jogo::initTextures()
{
    this->texture["PROJETIL"] = new sf::Texture();
    this->texture["PROJETIL"]->loadFromFile("Assests/Projetil/projetil.png");
}


void Jogo::initAtirador()
{
    this->atirador = new Atirador();

    this->inimigo = new Inimigo(20.f, 20.f);
}


// --------------------------------- CONST/DEST ---------------------------------------
Jogo::Jogo()
{
   
    this->initWindow();
    this->initTextures();
    this->initAtirador();
   
}


Jogo::~Jogo()
{
    delete this->window;
    delete this->atirador;

    //Delete textures
    for (auto &i : this->texture)
    {
        delete i.second;
    }
    //Delete Projeteis
    for (auto *i : this->projetil)
    {
        delete i;
    }
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

    if (Mouse::isButtonPressed(Mouse::Left) && this->atirador->canAttack())
    {
        this->projetil.push_back(new Projetil(this->texture["PROJETIL"], this->atirador->getPos(). x, this->atirador->getPos(). y, 0.f, -1.f, 5.f));
    }
}

void Jogo::updateProjetil()
{
    unsigned counter = 0;
    for (auto *projetil : this->projetil)
    {
        projetil->update();

        //seleção de balas (parte superior da tela)
        if (projetil->getBounds().top + projetil->getBounds().height < 0.f)
        {
            //Apagar projetil
            delete projetil;
            this->projetil.erase(this->projetil.begin() + counter);
            --counter;
        }

        ++counter;

    }

}

void Jogo::update()
{
   this->updatePollEvents();

   this->updateImput();

   this->atirador->update();

   this->updateProjetil();
}


void Jogo::render()
{
    this->window->clear(Color::Black);
   
    // desenhe todas as coisas
    this->atirador->render(this->window);

    for (auto *projetil : this->projetil)
    {
        projetil->render(this->window);
    }

    this->inimigo->render(this->window);

    this->window->display();


}


