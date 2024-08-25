#include <SFML/Graphics.hpp>
#include <iostream>
#include "Headers/Base.hpp"
#include <math.h>
#include "Base.hpp"

using namespace sf;
using namespace std;

Base::Base(){
    this->initVariables();
    this->initTexture();
    this->initSprite();
} 

void Base::initVariables()
{
    this->vida = 100;
}


void Base::initTexture()
{
    if (!this->texture.loadFromFile("Assests/Base/base.png"))
    {
        cout << "ERRO: Nao foi possivel carregar a textura do atirador" << endl;
    }

}

void Base::initSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(300.f, 450.f);
}


Base::~Base()
{
}

const FloatRect Base::getBounds() const
{
    return this->sprite.getGlobalBounds();
}

// --------------------------------------- FUNCOES ---------------------------------------
void Base::takeDamage(int dano)
{
    this->vida -= dano;
    if (this->vida <= 0)
    {
        this->vida = 0;
    }
}

void Base::render(RenderTarget* target)
{
    target->draw(this->sprite);
}

int Base::getVida() const
{
    return this->vida;
}

Sprite& Base::getSprite() {
    return this->sprite;
}