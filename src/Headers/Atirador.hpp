// Arquivo: Atirador.hpp

#ifndef ATIRADOR_HPP
#define ATIRADOR_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Atirador{
    private:
        Sprite sprite;
        Texture texture;
        Sprite reloadItem;  // Sprite para o item de recarga
        float movementSpeed;
        int vida;
        float attackCooldown;
        float attackCooldownMax;
        int projeteisDisponiveis;

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
        int getVida() const;
        void dispararProjetil(); 
        int getProjeteisDisponiveis() const; 
        void addProjeteis();
        void addRecarga(sf::Texture *texture);
        void updateRecarga();
        void renderRecarga(sf::RenderTarget* target);
};

#endif // ATIRADOR_HPP
