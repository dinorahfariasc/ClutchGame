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

        float attackCooldown;
        float attackCooldownMax;

        // --------------------------------- FUNCOES PRIVADAS ------------------------------------
        void initVariables();
        void initTexture();
        void initSprite();
   
    public: 
        Atirador();
        virtual ~Atirador();

        //Accesor
        const Vector2f& getPos() const;
        
        // --------------------------------- FUNCOES Publicas------------------------------------
        void move(const float dirX, const float dirY);
        bool canAttack();

        void updateAttack();
        void update();
        void render(RenderTarget* target);


};

#endif // ATIRADOR_HPP