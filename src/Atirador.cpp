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
}

void Atirador::initTexture()
{
    if (!this->texture.loadFromFile("Assests/Personagem/handgun.png"))
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

    this->sprite.setRotation(angle + 90.f); //+90.f para alinhar o sprite corretamente 
}

void Atirador::update()
{
    this->updateAttack();
}

void Atirador::render(RenderTarget* target)
{
    target->draw(this->sprite);
}
