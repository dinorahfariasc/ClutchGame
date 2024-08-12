#ifndef JOGO_HPP
#define JOGO_HPP


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<map>
#include <Atirador.hpp>
#include "Projetil.hpp"
#include "Inimigo.hpp"

using namespace sf;


class Jogo
{
    private:
    //Window
    RenderWindow* window;


    //Recursos
    std::map<std::string, sf::Texture*> texture;
    std::vector<Projetil*> projetil;

    //Atirador
    Atirador* atirador;

    //Inimigo
    Inimigo* inimigo;


    // --------------------------------- FUNCOES PRIVADAS ------------------------------------
    void initWindow();
    void initTextures();
    void initAtirador();






    public:
        Jogo();
        virtual ~Jogo();

    // --------------------------------------- FUNCOES ---------------------------------------
        void run();


        void updatePollEvents();
        void updateImput();
        void updateProjetil();
        void update();
        void render();


};


#endif // JOGO_HPP
