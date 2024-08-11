#include "Projetil.hpp"


Projetil::Projetil()
{
}


Projetil::Projetil(Texture & texture, float dir_x, float dir_y, float movement_speed)
{
    this->shape.setTexture(texture);


    this->direction.x = dir_x;
    this->direction.y = dir_y;
    this->movementSpeed = movement_speed;


}


Projetil::~Projetil()
{
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




