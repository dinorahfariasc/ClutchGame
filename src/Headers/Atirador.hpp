#ifndef ATIRADOR_HPP
#define ATIRADOR_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Atirador{
    private:
        Sprite sprite;
        Texture texture;

        // --------------------------------- FUNCOES PRIVADAS ------------------------------------
        void initTexture();
        void initSprite();
   
    public: 
        Atirador();
        virtual ~Atirador();

        // --------------------------------- FUNCOES Publicas------------------------------------
        void update();
        void render(RenderTarget* target);


};

#endif // ATIRADOR_HPP