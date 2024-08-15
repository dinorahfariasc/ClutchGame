#include "Headers/Jogo.hpp"
#include "Jogo.hpp"
#include "Headers/Inimigo.hpp"
#include <math.h>

using namespace sf;
using namespace std;

// --------------------------------- FUNCOES PRIVADAS ------------------------------------
void Jogo::initWindow(){
    this->window = new RenderWindow(VideoMode(800, 800), "Shoothemup", Style::Close | Style::Titlebar);
    this->window->setFramerateLimit(60);
    this->window->setVerticalSyncEnabled(false);


}

void Jogo::initTextures()
{
    this->texture["PROJETIL"] = new Texture();
    this->texture["PROJETIL"]->loadFromFile("Assests/Projetil/projetil.png");

    this->texture["BACKGROUND"] = new Texture();
    this->texture["BACKGROUND"]->loadFromFile("Assests/BG/BackGround.png");
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
    this->background.setTexture(*this->texture["BACKGROUND"]);
   
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
        // Gerar uma posição aleatória na borda
        int border = rand() % 4;
        float posX, posY;
        if (border == 0) { // Topo
            posX = rand() % this->window->getSize().x;
            posY = 0.f;
        } else if (border == 1) { // Inferior
            posX = rand() % this->window->getSize().x;
            posY = this->window->getSize().y - 20.f;
        } else if (border == 2) { // Esquerda
            posX = 0.f;
            posY = rand() % this->window->getSize().y;
        } else { // Direita
            posX = this->window->getSize().x - 20.f;
            posY = rand() % this->window->getSize().y;
        }

        // Criar inimigo na borda com a posição inicial do atirador
        sf::Vector2f atiradorPos = this->atirador->getPos();
        this->inimigos.push_back(new Inimigo(posX, posY, atiradorPos));

        this->spawnTimer = 0.f;
    }
    
    for (int i = 0; i < this->inimigos.size(); ++i)
    {
        // Atualizar a direção do inimigo para a posição atual do atirador
        sf::Vector2f atiradorPos = this->atirador->getPos();
        this->inimigos[i]->update(atiradorPos);

        // Remove os inimigos fora da tela (ajuste se necessário)
        if (this->inimigos[i]->getBounds().top > this->window->getSize().y ||
            this->inimigos[i]->getBounds().left > this->window->getSize().x ||
            this->inimigos[i]->getBounds().left + this->inimigos[i]->getBounds().width < 0 ||
            this->inimigos[i]->getBounds().top + this->inimigos[i]->getBounds().height < 0)
        {
            this->inimigos.erase(this->inimigos.begin() + i);
        }
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
    
    this->window->draw(this->background);

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


