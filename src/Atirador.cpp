#include "Headers/Atirador.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;


Atirador::Atirador() 
{
    this->initTexture();
    this->initSprite();
}


void Atirador::initTexture()
{
    if (!this->texture.loadFromFile("Assets/Personagem/handgun.png"))
    {
        cout << "ERRO: Nao foi possivel carregar a textura do atirador" << endl;
    }
}

void Atirador::initSprite()
{

}


Atirador::~Atirador()
{
    
}

// --------------------------------------- FUNCOES ---------------------------------------
void Atirador::update()
{


}

void Atirador::render(RenderTarget* target)
{
    target->draw(this->sprite);
}
