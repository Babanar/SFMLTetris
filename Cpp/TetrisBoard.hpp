#ifndef TETRISBOARD_H
#define TETRISBOARD_H

#include "headers.hpp"

#include "Tetromino.hpp"
#include "fn_random.hpp"
#include "Collision.hpp"
#include "ExplosionManager.hpp"
#include "OpenGL_Manager.hpp"
using namespace std;
using namespace sf;


class TetrisBoard : public sf::Drawable
{
    public:

        TetrisBoard(sf::Vector2i * window_size,OpenGL_Manager * oGL);
        virtual ~TetrisBoard();


        bool newPiece(Tetromino & p); // place la nouvelle pièce en haut
        Tetromino & getPieceCourrante();

        void clearBoard();

        int HardDrop();

        bool MoveDown();
        bool moveLeft();
        bool moveRight();
        bool rotateLeft();
        bool rotateRight();

        bool mouseLeftRight(sf::Event event);


        void fixPiece();
        void dessinePieceCourrante(bool drawGhost);
        void effacePieceCourrante();


        int fullLinesClear(ExplosionManager * explosions);

        bool pieceIsActive();

        int getBoardData(int x, int y);
        void setBoardData(int x, int y, int data);



    private:
        OpenGL_Manager * _oGL;
        // element graphique
        sf::RectangleShape boardShape; // le rectangle principal
        vector<sf::RectangleShape> shapeMatrix; // les rectangles de chaque cases

        sf::Vector2i * _window_size;

        bool verifierPlacementPiece(sf::Vector2i pos, int o);

        Tetromino pieceCourrante;
        bool pieceCouranteActive;
        int area[BOARD_WIDTH][BOARD_HEIGHT];
        /*
            Valeurs des cases possibles
            0 : vide (les cases de 1 à 9 peuvent être considéré comme vide (pour faciliter les conditions))
            10-16 : les cases fixes
            20-26 : les cases de la pièce en mouvement
            30-36 : les cases du fantôme de la pièce en mouvement
        */
        int areasup[BOARD_WIDTH][2];
        // contient les valeurs des cases cachés au dessus

        // sf::Drawable
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // TETRISBOARD_H
