#include "Inimigo.hpp"
#include <math.h>

using namespace sf;

void Inimigo::initShape()
{
    this->shape.setRadius(rand() % 20 +20);
    this->shape.setPointCount(rand() % 20 + 3);
    this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
}

void Inimigo::initVariable()
{
   this->type     = 0;
   this->speed    = 5.f;
   this->hpMax    = 10;
   this->hp       = 0;
   this->damage   = 1;
   this->points   = 5;
}


Inimigo::Inimigo(float pos_x, float pos_y, Vector2f atiradorPos)
{
    this->initShape();
    this->initVariable();
    this->shape.setPosition(pos_x, pos_y);
    Vector2f dir = atiradorPos - this->shape.getPosition();
    float magnitude = sqrt(dir.x * dir.x + dir.y * dir.y);
    this->direction = dir / magnitude;

}

Inimigo::~Inimigo()
{
}
const sf::FloatRect Inimigo::getBounds() const
{
    return this->shape.getGlobalBounds();
}

// Funções
void Inimigo::update(sf::Vector2f atiradorPos)
{
    // Recalcula a direção para a posição atual do atirador
    sf::Vector2f dir = atiradorPos - this->shape.getPosition();
    float magnitude = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    this->direction = dir / magnitude;

    // Atualiza a posição do inimigo
    this->shape.move(this->direction * this->speed);
}

void Inimigo::render(sf::RenderTarget * target)
{
    target->draw(this->shape);
}

void Inimigo::takeDamage(int dano)
{
    this->hp -= dano;
    if (this->hp <= 0)
    {
        this->hp = 0;
    }
}


int Inimigo::getDamage()
{
    return this->damage;
}


int Inimigo::getHp()
{
    return this->hp;
}