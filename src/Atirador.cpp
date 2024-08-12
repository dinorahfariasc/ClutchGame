#include "Headers/Atirador.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Atirador.hpp"

using namespace sf;
using namespace std;


Atirador::Atirador() 
{
    this->movementSpeed = 5.f;
    this->initTexture();
    this->initSprite();
}


void Atirador::initTexture()
{
    if (!this->texture.loadFromFile("Assests/Personagem/handgun.png"))
    {
        cout << "ERRO: Nao foi possivel carregar a textura do atirador" << endl;
    }

}

void Atirador::initSprite()
{
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(400.f, 300.f);
}


Atirador::~Atirador()
{
    
}

const Vector2f &Atirador::getPos() const
{
    return this->sprite.getPosition();
}

    // TODO: inserir instrução return aqui
// --------------------------------------- FUNCOES ---------------------------------------

void Atirador::move(const float dirX, const float dirY)
{
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
} 
 

void Atirador::update()
{


}

void Atirador::render(RenderTarget* target)
{
    target->draw(this->sprite);
}
