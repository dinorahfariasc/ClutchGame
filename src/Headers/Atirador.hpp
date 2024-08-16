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
        int vida;
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
        const FloatRect getBounds() const;

        // --------------------------------- FUNCOES Publicas------------------------------------
        void move(const float dirX, const float dirY);
        bool canAttack();
        void updateAttack();
        void updateRotation(const Vector2f& mousePos); //atualizar a rotação
        void takeDamage(int dano);
        void update();
        void render(RenderTarget* target);
        int getVida();

};

#endif // ATIRADOR_HPP