#include "Headers/ProjetilInimigo.hpp"

using namespace sf;

ProjetilInimigo::ProjetilInimigo(Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float speed)
    : direction(dir_x, dir_y), speed(speed)
{
    this->sprite.setTexture(*texture);
    this->sprite.setPosition(pos_x, pos_y);
}

ProjetilInimigo::~ProjetilInimigo()
{
}

const sf::FloatRect ProjetilInimigo::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

void ProjetilInimigo::update()
{
    this->sprite.move(this->direction * this->speed);
}

void ProjetilInimigo::render(sf::RenderTarget* target)
{
    target->draw(this->sprite);
}
