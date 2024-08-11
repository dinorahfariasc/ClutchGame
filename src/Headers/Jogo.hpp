#ifndef JOGO_HPP
#define JOGO_HPP


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<map>
#include <Atirador.hpp>


using namespace sf;


class Jogo
{
    private:
    //Window
    RenderWindow* window;


    //Recursos
    std::map<std::string, sf::Texture> texture;


    Atirador* atirador;


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
        void update();
        void render();


};


#endif // JOGO_HPP
