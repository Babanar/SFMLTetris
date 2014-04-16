#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <string>

#include "Bouton.hpp"
#include "TetrisBoard.hpp"
#include "Tetromino.hpp"
#include "ScreenElement.hpp"
#include "Application.hpp"
#include "NextTetrominoBoard.hpp"
#include "fn_string.hpp"
#include "fn_time.hpp"


#define POINTS_LEVEL 1000

#define SPEED_LEVEL_COEFF 0.2

#define HARD_DROP_BONUS_COEFF 2
#define SOFT_DROP_BONUS_COEFF 1

#define NB_NEXT_TETROMINO 3

using namespace std;
using namespace sf;


class Game : public ScreenElement
{
    private:
        TetrisBoard matrix;
        Tetromino pieceSuivante;
        vector<NextTetrominoBoard> nextTetromino;

        Bouton scoreInfos;
        Bouton scoreInfosBefore;

        char * _state;

        bool _pause;


        int _score;
        int _nb_line;
        int _nb_manual_down;
        int _nb_tetromino;

        sf::Time timeLastMoveDown;
        sf::Clock gameClock;
        sf::Time totalPauseTime;
        sf::Time lastPauseStartingTime;


        bool nextPiece();

        // sf::Drawable
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    public:
        Game(sf::Vector2i * window_size, char *state);
        virtual ~Game();


        int getLevel();

        void setTimeLastMoveDown();

        sf::Time getGameTime();

        void setPause(bool p);
        bool getPause();

        void restartGame();


        // permet de prendre en compte le lag dans la descente de la pièce
        sf::Time getTimeAutoMoveDown();


        virtual void onEvent(sf::Event & event);


        virtual void update();
};

#endif // GAME_H
