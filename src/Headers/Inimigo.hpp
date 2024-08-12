#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include <SFML/Graphics.hpp>

class Inimigo
{
private:
    sf::CircleShape shape;
    int type;
    int hp;
    int hpMax;
    int demage;
    int points;

    void initShape();
    void initVariable();


public:
    Inimigo(float pos_x, float pos_y);
    virtual ~Inimigo();

    //Funções
    void update();
    void render(sf::RenderTarget* target);
};

#endif