#ifndef PROJETIL_HPP
#define PROJETIL_HPP


#include <SFML/Graphics.hpp>
#include <Atirador.hpp>


class Projetil
{
private:
    Sprite shape;


    Vector2f direction;
    float movementSpeed;


public:
    Projetil();
    Projetil(Texture* texture, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed);
    virtual ~Projetil();

    //Accessor
    const FloatRect getBounds() const;

    void update();
    void render(RenderTarget* target);
};


#endif
