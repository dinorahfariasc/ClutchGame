#ifndef ATIRADOR_HPP
#define ATIRADOR_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Atirador{
    private:
        Sprite sprite;
        Texture texture;
        float movementSpeed;

        // --------------------------------- FUNCOES PRIVADAS ------------------------------------
        void initTexture();
        void initSprite();
   
    public: 
        Atirador();
        virtual ~Atirador();

        // --------------------------------- FUNCOES Publicas------------------------------------
        void move(const float dirX, const float dirY);
        
        void update();
        void render(RenderTarget* target);


};

#endif // ATIRADOR_HPP