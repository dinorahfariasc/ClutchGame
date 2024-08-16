#ifndef JOGO_HPP
#define JOGO_HPP


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<map>
#include <Atirador.hpp>
#include "Projetil.hpp"
#include "Inimigo.hpp"

using namespace sf;
using namespace std;


class Jogo
{
    private:
    //Window
    RenderWindow* window;


    //Recursos
    map<std::string, sf::Texture*> texture;
    vector<Projetil*> projetil;
    Sprite background;

    //Atirador
    Atirador* atirador;

    //Inimigo
    float spawnTimer;
    float spawnTimerMax;
    vector<Inimigo*> inimigos;

    // --------------------------------- FUNCOES PRIVADAS ------------------------------------
    void initWindow();
    void initTextures();
    void initInimigo();
    void initAtirador();
    



    public:
        Jogo();
        virtual ~Jogo();

    // --------------------------------------- FUNCOES ---------------------------------------
        void run();


        void updatePollEvents();
        void updateInput();
        void updateProjetil();
        void updateInimigoeCombate();
        void update();
        void render();


};


#endif // JOGO_HPP
