#ifndef _MENU_HPP_
#define _MENU_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Bouton.hpp"
#include "ScreenElement.hpp"

using namespace std;
using namespace sf;



class Menu : public ScreenElement
{
    protected:
        vector<Bouton> menuElements;

        sf::Vector2i _window_size;
        char *_state;
        // sf::Drawable
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    public:




        Menu(sf::Vector2i window_size,char *state);
        virtual ~Menu();

        virtual void onEvent(sf::Event & event);
        virtual void onMouseMove(sf::Event & event);
        virtual void onMouseDown(sf::Event & event);
        virtual void onMouseUp(sf::Event & event);
        virtual void update();



};

#endif // _MENU_HPP_