
#include "Headers/Jogo.hpp"
#include "Headers/GameOver.hpp"
#include "Headers/Inimigo.hpp"
#include <math.h>

#include <SFML/Graphics.hpp>

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

    this->texture["PROJETIL2"] = new Texture();
    this->texture["PROJETIL2"]->loadFromFile("Assests/Projetil/projetil2.png");

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

    // Delete textures
    for (auto& texturePair : this->texture)
    {
        delete texturePair.second;
    }

    // Delete Projeteis
    for (auto* projetil : this->projetil)
    {
        delete projetil;
    }
    this->projetil.clear(); // Limpa o vetor após deletar

    // Delete Inimigos
    for (auto* inimigo : this->inimigos)
    {
        delete inimigo;
    }
    this->inimigos.clear(); // Limpa o vetor após deletar
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
                                              atiradorPos.x , //posição do projetil
                                              atiradorPos.y , 
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

void Jogo::updateInimigoeCombate()
{
    this->spawnTimer += 0.5f;
    if (this->spawnTimer >= this->spawnTimerMax)
    {
        // Gera uma posição aleatória para o inimigo em uma das quatro bordas
        float x = 0.f;
        float y = 0.f;
        int edge = rand() % 4; // 0: superior, 1: inferior, 2: esquerda, 3: direita
        switch (edge)
        {
            case 0: // Superior
                x = rand() % this->window->getSize().x;
                y = -50.f; // Posição acima da tela
                break;
            case 1: // Inferior
                x = rand() % this->window->getSize().x;
                y = this->window->getSize().y + 50.f; // Posição abaixo da tela
                break;
            case 2: // Esquerda
                x = -50.f; // Posição à esquerda da tela
                y = rand() % this->window->getSize().y;
                break;
            case 3: // Direita
                x = this->window->getSize().x + 50.f; // Posição à direita da tela
                y = rand() % this->window->getSize().y;
                break;
        }

        // Adiciona o inimigo à lista com a nova posição
        this->inimigos.push_back(new Inimigo(x, y, this->texture["PROJETIL2"],this->atirador->getPos()));
        this->spawnTimer = 0.f;
    }

    // todo remover inimigos apenas se forem atingindos ! 
    for (size_t i = 0; i < this->inimigos.size(); ++i)
    {
        this->inimigos[i]->update(this->atirador->getPos());

        // Checar se o projetil do atirador atinge o inimigo e diminuir a vida do inimigo
        for (size_t k = 0; k < this->projetil.size(); ++k)
        {
            if (this->projetil[k]->getBounds().intersects(this->inimigos[i]->getBounds()))
            {
                this->inimigos[i]->takeDamage(this->projetil[k]->getDano());
                this->projetil.erase(this->projetil.begin() + k);
                
                // se a vida do inimigo for 0, apague o inimigo
                if (this->inimigos[i]->getHp() <= 0)
                {
                    this->inimigos.erase(this->inimigos.begin() + i);
                }

            }
        }
        
        // se o inimigo atingir o atirador, apague o inimigo e diminua a vida do atirador
        if (this->inimigos[i]->getBounds().intersects(this->atirador->getBounds()))
        {
            delete this->inimigos[i];
            this->inimigos.erase(this->inimigos.begin() + i);
            this->atirador->takeDamage(this->inimigos[i]->getDamage());
            // matar o jogador
            if (this->atirador->getVida() <= 0)
            {
                this->window->close();
                // Game Over
                GameOver gameover;
                gameover.runGameOver();
                
            }
        }

    }
}



void Jogo::update()
{
   this->updatePollEvents();

   this->updateInput();

   Vector2f mousePos = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));

   this->atirador->updateRotation(mousePos);

   this->atirador->update();

   this->updateProjetil();

   this->updateInimigoeCombate();
}


void Jogo::render()
{
    this->window->clear(Color::Black);
    
    this->window->draw(this->background);

    // Renderizar todas as coisas
    this->atirador->render(this->window);

    for (auto* projetil : this->projetil)
    {
        projetil->render(this->window);
    }

    for (auto* inimigo : this->inimigos)
    {
        inimigo->render(this->window);
    }

    this->window->display();
}


