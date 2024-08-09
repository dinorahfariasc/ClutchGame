#ifndef JOGO_HPP
#define JOGO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Jogo
{
    private: 
    RenderWindow* window;

    // --------------------------------- FUNCOES PRIVADAS ------------------------------------
    void initWindow();



    public:
        Jogo();
        virtual ~Jogo();
    // --------------------------------------- FUNCOES ---------------------------------------
        void run();
        void update();
        void render();

};

#endif // JOGO_HPP