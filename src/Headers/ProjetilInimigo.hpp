#ifndef PROJETIL_INIMIGO_HPP
#define PROJETIL_INIMIGO_HPP

#include <SFML/Graphics.hpp>

class ProjetilInimigo
{
private:
    sf::Sprite sprite;
    sf::Vector2f direction;
    float speed;

public:
    ProjetilInimigo(sf::Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float speed);
    virtual ~ProjetilInimigo();

    const sf::FloatRect getBounds() const;
    void update();
    void render(sf::RenderTarget* target);
};

#endif
