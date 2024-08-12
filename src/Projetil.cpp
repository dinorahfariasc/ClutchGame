#include "Projetil.hpp"


Projetil::Projetil()
{
}

Projetil::Projetil(Texture * texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
    this->shape.setTexture(*texture);

    this->shape.setPosition(pos_x, pos_y);
    this->direction.x = dir_x;
    this->direction.y = dir_y;
    this->movementSpeed = movement_speed;
}


Projetil::~Projetil()
{
}

const FloatRect Projetil::getBounds() const
{
    return this->shape.getGlobalBounds();
}

void Projetil::update()
{
    //Movementoss
    this->shape.move(this->movementSpeed * this->direction);
}


void Projetil::render(RenderTarget *target)
{
    target->draw(this->shape);
}




