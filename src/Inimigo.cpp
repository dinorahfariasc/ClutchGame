#include "Inimigo.hpp"

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
   this->demage   = 1;
   this->points   = 5;
}


Inimigo::Inimigo(float pos_x, float pos_y)
{
    this->initShape();
    this->initVariable();
    
    this->shape.setPosition(pos_x, pos_y);

}

Inimigo::~Inimigo()
{
}
const sf::FloatRect Inimigo::getBounds() const
{
    return sf::FloatRect();
}

//Accessors
const sf::FloatRect Inimigo::getBounds() const
{
    return this->shape.getGlobalBounds();
}

// Funções
void Inimigo::update()
{
    this->shape.move(0.f, this->speed);
}

void Inimigo::render(sf::RenderTarget * target)
{
    target->draw(this->shape);
}
