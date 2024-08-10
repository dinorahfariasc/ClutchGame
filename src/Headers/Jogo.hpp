#ifndef JOGO_HPP
#define JOGO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Atirador.hpp>

using namespace sf;

class Jogo
{
    private: 
    RenderWindow* window;
    Atirador* atirador;

    // --------------------------------- FUNCOES PRIVADAS ------------------------------------
    void initWindow();
    void initAtirador();



    public:
        Jogo();
        virtual ~Jogo();
    // --------------------------------------- FUNCOES ---------------------------------------
        void run();
        void update();
        void render();

};

#endif // JOGO_HPP