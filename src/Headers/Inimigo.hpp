#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Inimigo
{
private:
    sf::CircleShape shape;
    int type;
    float speed;
    int hp;
    int hpMax;
    int damage;
    int points;
    sf::Vector2f direction;

    void initShape();
    void initVariable();


public:
    Inimigo(float pos_x, float pos_y, Vector2f atiradorPos);
    virtual ~Inimigo();

    //Accessors
    const sf::FloatRect getBounds() const;

    //Funções
    void update(sf::Vector2f atiradorPos);
    void render(sf::RenderTarget *target);
    void takeDamage(int dano);
    int getDamage();
    int getHp();
};

#endif // INIMIGO_HPP