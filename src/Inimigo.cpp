#include "Inimigo.hpp"

void Inimigo::initShape()
{
    this->shape.setRadius(rand() % 20 +20);
    this->shape.setPointCount(rand() % 20 + 3);

}

void Inimigo::initVariable()
{
   this->type     = 0;
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
 //Funções
void Inimigo::update()
{
}

void Inimigo::render(sf::RenderTarget * target)
{
    target->draw(this->shape);
}
