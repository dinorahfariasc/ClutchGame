#include "Headers/Jogo.hpp"
#include "Jogo.hpp"
#include "Headers/Inimigo.hpp"
#include <math.h>


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

}

void Jogo::initInimigo()
{
    this->spawnTimerMax = 50.f;
    this->spawnTimer = this->spawnTimerMax;
}   



// --------------------------------- CONST/DEST ---------------------------------------
Jogo::Jogo()
{
   
    this->initWindow();
    this->initTextures();
    this->initAtirador();
    this->initInimigo();
   
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
    //Delete Inimigos
    for (auto *i : this->inimigos)
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


void Jogo::updateInput()
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



    // Atirar Projetil
    if (Mouse::isButtonPressed(Mouse::Left) && this->atirador->canAttack())
    {
        // Posição do mouse
        sf::Vector2f mousePos = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));

        // Posição do atirador
        sf::Vector2f atiradorPos = this->atirador->getPos();

        // Direção do projetil
        sf::Vector2f dir = mousePos - atiradorPos;

        // Normalizar a direção
        float magnitude = sqrt(dir.x * dir.x + dir.y * dir.y);
        sf::Vector2f direction = dir / magnitude;

        // Criação do projetil com a direção calculada
        this->projetil.push_back(new Projetil(this->texture["PROJETIL"], 
                                              atiradorPos.x + 55.f - 2.5f, //posição do projetil
                                              atiradorPos.y + 22.f, 
                                              direction.x, direction.y, 5.f));
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

void Jogo::updateInimigo()
{
    this->spawnTimer += 0.5f;
    if (this->spawnTimer >= this->spawnTimerMax)
    {
        this->inimigos.push_back(new Inimigo(rand()%200,rand()%200)); // gerando inimigos em pos aleatorias
        this->spawnTimer = 0.f;
    }
    
    for (auto *inimigo : this->inimigos)
    {
        inimigo->update();
    }
    
}

void Jogo::update()
{
   this->updatePollEvents();

   this->updateInput();

   this->atirador->update();

   this->updateProjetil();

   this->updateInimigo();
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

    for (auto *inimigo : this->inimigos)
    {
        inimigo->render(this->window);
    }


    this->window->display();


}


