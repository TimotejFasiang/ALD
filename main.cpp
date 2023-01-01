/* Creates a randomly generated board of "pipe like" objects that are interconnected.
 * Saves a photo of final result to program location.
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GamePiece.h"

using namespace std;

void boardSet(int i, int j, GamePiece piece, sf::Sprite sPiece, sf::RenderWindow * window, GamePiece board[21][21]) {
    board[i][j] = piece;
    int xL = i * 38;
    int yL = j * 38;
    sPiece.setPosition(sf::Vector2f(xL, yL));
    window->draw(sPiece);
}

int main() {

    float xL = 0;
    float yL = 0;

    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");

    sf::Texture tEmpty;
    sf::Sprite sEmpty;
    sEmpty.setTexture(tEmpty);
    sEmpty.scale(sf::Vector2f(.1f, .1f));

    // SINGLE DIRECTION
    sf::Texture tU;
    tU.loadFromFile("..\\images\\U.png");
    sf::Sprite sU;
    sU.setTexture(tU);
    sU.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tR;
    tR.loadFromFile("..\\images\\R.png");
    sf::Sprite sR;
    sR.setTexture(tR);
    sR.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tD;
    tD.loadFromFile("..\\images\\D.png");
    sf::Sprite sD;
    sD.setTexture(tD);
    sD.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tL;
    tL.loadFromFile("..\\images\\L.png");
    sf::Sprite sL;
    sL.setTexture(tL);
    sL.scale(sf::Vector2f(.1f, .1f));

    //DOUBLE DIRECTION
    sf::Texture tUR;
    tUR.loadFromFile("..\\images\\UR.png");
    sf::Sprite sUR;
    sUR.setTexture(tUR);
    sUR.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tRD;
    tRD.loadFromFile("..\\images\\RD.png");
    sf::Sprite sRD;
    sRD.setTexture(tRD);
    sRD.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tDL;
    tDL.loadFromFile("..\\images\\DL.png");
    sf::Sprite sDL;
    sDL.setTexture(tDL);
    sDL.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tLU;
    tLU.loadFromFile("..\\images\\LU.png");
    sf::Sprite sLU;
    sLU.setTexture(tLU);
    sLU.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tUD;
    tUD.loadFromFile("..\\images\\UD.png");
    sf::Sprite sUD;
    sUD.setTexture(tUD);
    sUD.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tRL;
    tRL.loadFromFile("..\\images\\RL.png");
    sf::Sprite sRL;
    sRL.setTexture(tRL);
    sRL.scale(sf::Vector2f(.1f, .1f));

    // TRIPLE DIRECTION
    sf::Texture tURD;
    tURD.loadFromFile("..\\images\\URD.png");
    sf::Sprite sURD;
    sURD.setTexture(tURD);
    sURD.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tRDL;
    tRDL.loadFromFile("..\\images\\RDL.png");
    sf::Sprite sRDL;
    sRDL.setTexture(tRDL);
    sRDL.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tDLU;
    tDLU.loadFromFile("..\\images\\DLU.png");
    sf::Sprite sDLU;
    sDLU.setTexture(tDLU);
    sDLU.scale(sf::Vector2f(.1f, .1f));

    sf::Texture tLUR;
    tLUR.loadFromFile("..\\images\\LUR.png");
    sf::Sprite sLUR;
    sLUR.setTexture(tLUR);
    sLUR.scale(sf::Vector2f(.1f, .1f));

    // QUADRUPLE DIRECTION
    sf::Texture tURDL;
    tURDL.loadFromFile("..\\images\\URDL.png");
    sf::Sprite sURDL;
    sURDL.setTexture(tURDL);
    sURDL.scale(sf::Vector2f(.1f, .1f));


    GamePiece board[21][21];
    bool mustUp = false;
    bool mustLeft = false;
    bool canRight = false;
    bool canDown = false;
    int selection;

    GamePiece empty;

    GamePiece URDL;
    URDL.up = true;
    URDL.right = true;
    URDL.down = true;
    URDL.left = true;

    GamePiece URD, RDL, UDL, URL;
    URD.up = true;
    URD.right = true;
    URD.down = true;
    RDL.right = true;
    RDL.down = true;
    RDL.left = true;
    UDL.up = true;
    UDL.down = true;
    UDL.left = true;
    URL.up = true;
    URL.right = true;
    URL.left = true;

    GamePiece UD, RL;
    UD.up = true;
    UD.down = true;
    RL.right = true;
    RL.left = true;

    GamePiece UL, UR, RD, DL;
    UL.up = true;
    UL.left = true;
    UR.up = true;
    UR.right = true;
    RD.right = true;
    RD.down = true;
    DL.down = true;
    DL.left = true;

    GamePiece R, D, L, U;
    R.right = true;
    D.down = true;
    L.left = true;
    U.up = true;

    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 21; ++j) {
            mustLeft = false;
            mustUp = false;
            canRight = true;
            canDown = true;

            if (i != 0 && board[i - 1][j].right) { // Tile must connect left
                mustLeft = true;
            }
            if (j != 0 && board[i][j - 1].down) { // Tile must connect up
                mustUp = true;
            }
            if (i == 20) { // Tile cannot connect right (last column)
                canRight = false;
            }
            if (j == 20) { // Tile cannot connect down (bottom row)
                canDown = false;
            }
            ////////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////// Decide which blocks can go //////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////
            if (mustUp && mustLeft) { // Tile can connect in any direction
                if (!canRight && !canDown) {
                    board[i][j] = UL;
                    xL = i * 38;
                    yL = j * 38;
                    sLU.setPosition(sf::Vector2f(xL, yL));
                    window.draw(sLU);
                    break;
                }
                else if (!canRight) { // Tile cannot connect right (last column)
                    selection = randomNum(2);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,UDL,sDLU,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,UL,sLU,&window,board);
                            break;
                    }
                }
                else if (!canDown) { // Tile cannot connect down (lowest row)
                    selection = randomNum(2);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,URL,sLUR,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,UL,sLU,&window,board);
                            break;
                    }
                }
                else {
                    selection = randomNum(4);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,URDL,sURDL,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,UDL,sDLU,&window,board);
                            break;
                        case 3:
                            boardSet(i,j,URL,sLUR,&window,board);
                            break;
                        case 4:
                            boardSet(i,j,UL,sLU,&window,board);
                            break;
                    }
                }
            }
            else if (mustUp) { // Tile cannot connect left, must up
                if (!canRight && !canDown) { // Tile cannot connect down or right (bottom row, right column)
                    boardSet(i,j,U,sU,&window,board);
                    break;
                }
                else if (!canRight) { // Tile cannot connect right (last column)
                    selection = randomNum(2);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,U,sU,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,UL,sLU,&window,board);
                            break;
                    }
                }
                else if (!canDown) { // Tile cannot connect down (lowest row)
                    selection = randomNum(2);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,UR,sUR,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,U,sU,&window,board);
                            break;
                    }
                }
                else {
                    selection = randomNum(4);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,URD,sURD,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,UD,sUD,&window,board);
                            break;
                        case 3:
                            boardSet(i,j,UR,sUR,&window,board);
                            break;
                        case 4:
                            boardSet(i,j,U,sU,&window,board);
                            break;
                    }
                }
            }
            else if (mustLeft) { // Tile cannot connect up, must left
                if (!canRight && !canDown) { // Tile cannot connect down or right (bottom row, right column)
                    boardSet(i,j,L,sL,&window,board);
                    break;
                }
                else if (!canRight) { // Tile cannot connect right (last column)
                    selection = randomNum(2);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,DL,sDL,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,L,sL,&window,board);
                            break;
                    }
                }
                else if (!canDown) { // Tile cannot connect down (bottom row)
                    selection = randomNum(2);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,RL,sRL,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,L,sL,&window,board);
                            break;
                    }
                }
                else {
                    selection = randomNum(4);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,RDL,sRDL,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,DL,sDL,&window,board);
                            break;
                        case 3:
                            boardSet(i,j,RL,sRL,&window,board);
                            break;
                        case 4:
                            boardSet(i,j,L,sL,&window,board);
                            break;
                    }
                }
            }
            else { // Can't connect up or left
                if (!canRight && !canDown) {
                    boardSet(i,j,empty,sEmpty,&window,board);
                }
                else if (!canRight) { // Tile cannot connect right (last column)
                    selection = randomNum(2);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,D,sD,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,empty,sEmpty,&window,board);
                            break;
                    }
                }
                else if (!canDown) { // Tile cannot connect down (bottom row)
                    selection = randomNum(2);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,R,sR,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,empty,sEmpty,&window,board);
                            break;
                    }
                }
                else {
                    selection = randomNum(4);
                    switch (selection) {
                        case 1:
                            boardSet(i,j,RD,sRD,&window,board);
                            break;
                        case 2:
                            boardSet(i,j,R,sR,&window,board);
                            break;
                        case 3:
                            boardSet(i,j,D,sD,&window,board);
                            break;
                        case 4:
                            boardSet(i,j,empty,sEmpty,&window,board);
                            break;
                    }
                }
            }
        }
    }

    sf::Texture renderTexture;
    renderTexture.create(window.getSize().x, window.getSize().y);
    renderTexture.update(window);
    if (renderTexture.copyToImage().saveToFile("..\\renderImage.png")) {
        cout << "screenshot saved to " << "..\\renderImage.png" << std::endl;
    }

    return 0;
}