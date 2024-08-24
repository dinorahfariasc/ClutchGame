#include "Headers/Atirador.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Atirador.hpp"
#include <math.h>

using namespace sf;
using namespace std;


Atirador::Atirador() 
{
    this->initVariables();
    this->initTexture();
    this->initSprite();
    
}

void Atirador::initVariables()
{
    this->movementSpeed = 5.f;
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;
    this->vida = 20;
    this->projeteisDisponiveis = 20;
}

void Atirador::initTexture()
{
    if (!this->texture.loadFromFile("Assests/Personagem/player.png"))
    {
        cout << "ERRO: Nao foi possivel carregar a textura do atirador" << endl;
    }

}

void Atirador::initSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(400.f, 300.f);
}


Atirador::~Atirador()
{
    
}

const Vector2f &Atirador::getPos() const
{
    return this->sprite.getPosition();
}

const FloatRect Atirador::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

    // TODO: inserir instrução return aqui
// --------------------------------------- FUNCOES ---------------------------------------

void Atirador::move(const float dirX, const float dirY)
{
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

bool Atirador::canAttack() 
{
    if (this->attackCooldown >= this->attackCooldownMax)
    {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Atirador::updateAttack()
{
    if(this->attackCooldown < this->attackCooldownMax)
        this->attackCooldown += 0.5f;
}

void Atirador::updateRotation(const Vector2f &mousePos)
{
    Vector2f atiradorPos = this->sprite.getPosition();

    float deltaX = mousePos.x - atiradorPos.x;
    float deltaY = mousePos.y - atiradorPos.y;

    float angle = std::atan2(deltaY, deltaX) * 180.f / 3.14159f;

    this->sprite.setRotation(angle - 75.f ); 
}
void Atirador::takeDamage(int dano)
{
    this->vida -= dano;
    if (this->vida <= 0)
    {
        this->vida = 0;
    }
}

void Atirador::update()
{
    this->updateAttack();
}

void Atirador::render(RenderTarget* target)
{
    target->draw(this->sprite);
}

int Atirador::getVida() const
{
    return this->vida;
}

void Atirador::dispararProjetil()
{
    if (this->projeteisDisponiveis > 0)
    {
        this->projeteisDisponiveis--; 
        
    }
    else
    {
       //jogador tentar disparar sem projéteis
        std::cout << "Sem projéteis!" << std::endl;
    }
}

int Atirador::getProjeteisDisponiveis() const
{
    return this->projeteisDisponiveis;
}

void Atirador::addProjeteis()
{
    this->projeteisDisponiveis += 15;
}


void Atirador::addRecarga(sf::Texture *texture)
{
    // Inicializa o sprite de recarga se ele não tiver sido inicializado antes
    this->reloadItem.setTexture(*texture);
    this->reloadItem.setPosition(sf::Vector2f(300.f, 100.f)); // Posição inicial do sprite
}

void Atirador::updateRecarga()
{
    // Verifica a colisão entre o atirador e o item de recarga
    if (this->reloadItem.getGlobalBounds().intersects(this->sprite.getGlobalBounds()))
    {
        this->addProjeteis(); // Adiciona projéteis ao atirador

        // Remove o item de recarga da tela, movendo-o para fora da área visível
        this->reloadItem.setPosition(sf::Vector2f(-1000.f, -1000.f));
    }
}

void Atirador::renderRecarga(sf::RenderTarget* target)
{
    // Renderiza o item de recarga
    target->draw(this->reloadItem);
}
