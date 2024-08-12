#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Menu{
    int pos;
    bool pressed, theselected;

    RenderWindow* window;
    RectangleShape* winclose;
    Font* font;
    Texture* image;
    Sprite* bg;
    Music* music;
    

    Vector2i posmouse;
    Vector2f coormouse;

    vector<const char *> options;
    vector<Vector2f> coords;
    vector<Text> texts;
    vector<size_t> sizes;

    protected:
       void setValues();
       void loopEvents();
       void drawAll();

    public:
    Menu();
    ~Menu();
    void runMenu();
};