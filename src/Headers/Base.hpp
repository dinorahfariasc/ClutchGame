#ifndef BASE_HPP
#define BASE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Base{
    private:
        Sprite sprite;
        Texture texture;
        int vida;

    // --------------------------------- FUNCOES PRIVADAS ------------------------------------
        void initVariables();
        void initTexture();
        void initSprite();

    public:
        Base();
        virtual ~Base();

        //Accesor
        const Vector2f& getPos() const;
        const FloatRect getBounds() const;

        // --------------------------------- FUNCOES Publicas------------------------------------
        void takeDamage(int dano);
        void render(RenderTarget* target);
        int getVida();
        Sprite& getSprite();
};

#endif // BASE_HPP