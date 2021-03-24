#include "robots.h"

/**
 * @brief Robots::Robots constructor, hard coded positions (TESTING ONLY)
 */
Robots::Robots() : engine(10, 6)
{
    robots[0].first = 4;
    robots[0].second = 6;
    robots[1].first = 0;
    robots[1].second = 8;
    robots[2].first = 10;
    robots[2].second = 0;
    robots[3].first = 5;
    robots[3].second = 0;
    player.first = 2;
    player.second = 4;
    score = 0;
}

/**
 * @brief Robots::Robots constructor, random positions
 * @param s distingues the two constructors
 */
Robots::Robots(int r, int c) : engine(r, c){
    robots[0].first = rand() % cols;
    robots[0].second = rand() % rows;
    robots[1].first = rand() % cols;
    robots[1].second = rand() % rows;
    robots[2].first = rand() % cols;
    robots[2].second = rand() % rows;
    robots[3].first = rand() % cols;
    robots[3].second = rand() % rows;
    player.first = rand() % cols;
    player.second = rand() % rows;
    score = 0;
}

/**
 * @brief Robots::~Robots destructor
 */
Robots::~Robots() {

}

/**
 * @brief Robots::movePlayer moves player
 * @param movement direction
 */
void Robots::movePlayerW() {
    engine::gameboard[player.first][player.second] = '_';
    player.second -= 1;
}

void Robots::movePlayerE() {
    engine::gameboard[player.first][player.second] = '_';
    player.second += 1;
}

void Robots::movePlayerS() {
    engine::gameboard[player.first][player.second] = '_';
    player.first += 1;
}

void Robots::movePlayerN() {
    engine::gameboard[player.first][player.second] = '_';
    player.first -= 1;
}

void Robots::movePlayerNE() {
    engine::gameboard[player.first][player.second] = '_';
    player.first -= 1;
    player.second -= 1;
}

void Robots::movePlayerNW() {
    engine::gameboard[player.first][player.second] = '_';
    player.first += 1;
    player.second -= 1;
}

void Robots::movePlayerSE() {
    engine::gameboard[player.first][player.second] = '_';
    player.first -= 1;
    player.second += 1;
}

void Robots::movePlayerSW() {
    engine::gameboard[player.first][player.second] = '_';
    player.first += 1;
    player.second += 1;
}

/**
 * @brief Robots::moveRobots based on where the player moved
 */
void Robots::moveRobots() {
    for(int i = 0; i < 4; i++) {
        if(robots[i].first != -1) {
            //check position of robots
            if(player.first > robots[i].first) {
                robots[i].first += 1;
            }
            else if(player.first < robots[i].first) {
                robots[i].first -= 1;
            }
            else if(player.second > robots[i].second) {
                robots[i].second += 1;
            }
            else if(player.second < robots[i].second) {
                robots[i].second -= 1;
            }
            else if(robots[i].first == rows) {
                robots[i].first -= 1;
            }
            else if(robots[i].second == cols) {
                robots[i].second -= 1;
            }
        }

    }
}

/**
 * @brief Robots::randomTeleport teleports player to a random position on the grid
 */
void Robots::randomTeleport() {
    player.first = rand() % cols;
    player.second = rand() % rows;
}

/**
 * @brief Robots::isDead determine if 2 robots collided when moved
 * @return T if 2 robots collided, F if none collided
 */
void Robots::isDead() {
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            if((robots[i].first == robots[j].first) && ((robots[i].second == robots[j].second))) {
                robots[i].first = -1;
                robots[i].second = -1;
                robots[j].first = -1;
                robots[j].second = -1;
                score += 2;
            }
        }

    }
}

/**
 * @brief Robots::win win
 * @return T if win or F is no win
 */
bool Robots::win() {
    for(int i = 0; i < 4; i++) {
        if(robots[i].first != -1 || robots[i].second != -1) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Robots::clearGameBoard
 */
void Robots::clearGameBoard() {
    for(int i = 0; i < getRows(); i++) {
        for(int j = 0; j < getCols(); j++) {
            engine::gameboard[i][j] = '_';
        }
    }
}

/**
 * @brief Robots::updateBoard moves pieces on the board after methods have been called
 */
void Robots::updateBoard() {
    clearGameBoard();
    for(int i = 0; i < 4; i++) {
        engine::gameboard[robots[i].first][robots[i].second] = 'r';
    }
    engine::gameboard[player.first][player.second] = 'h';
}

/**
 * @brief Robots::getRows
 * @return number of rows
 */
int Robots::getRows() {
   return rows;
}

/**
 * @brief Robots::getCols
 * @return number of columns
 */
int Robots::getCols() {
    return cols;
}

/**
 * @brief Robots::playerDead
 * @return state of player
 */
bool Robots::playerDead() {
    for(int i = 0; i < 4; i++) {
        if((robots[i].first == player.first) && ((robots[i].second == player.second))) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Robots::get
 * @param row
 * @param col
 * @return char at that point
 */
char Robots::get(int row, int col) {
    return engine::gameboard[row][col];
}

/**
 * @brief Robots::resetGame
 */
void Robots::resetGame() {
    robots[0].first = 4;
    robots[0].second = 6;
    robots[1].first = 0;
    robots[1].second = 8;
    robots[2].first = 10;
    robots[2].second = 0;
    robots[3].first = 5;
    robots[3].second = 0;
    player.first = 2;
    player.second = 4;
}
