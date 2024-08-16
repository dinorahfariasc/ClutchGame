#include "ProjetInimigo.hpp"
#include <cmath>

using namespace sf;

ProjetInimigo::ProjetInimigo(sf::Texture* texture, float x, float y, float dirX, float dirY, float speed)
    : speed(speed)
{
    this->shape.setTexture(*texture);
    this->shape.setPosition(x, y);
    this->direction = sf::Vector2f(dirX, dirY);

    // Normaliza a direção para garantir que o movimento seja consistente
    float magnitude = std::sqrt(dirX * dirX + dirY * dirY);
    this->direction /= magnitude;
}

void ProjetInimigo::update()
{
    // Move o projétil na direção especificada pela velocidade
    this->shape.move(this->direction * this->speed);
}

const sf::FloatRect ProjetInimigo::getBounds() const
{
    return this->shape.getGlobalBounds();
}

void ProjetInimigo::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}
