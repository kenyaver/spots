#pragma once

#include <SFML/Graphics.hpp>

const int M = 9; // high
const int N = 6; // weight
const int size = M * N; // size of game

// parametrs:
const int FIELD_SIZE = 500;
const int CELL_SIZE = 120;

// vectors:
enum class Direction {Left, Right, Up, Down};

// logic of game:
class game{
protected:
    int elems[size];
    bool solve;
    int index;
    bool move_elem[size];
    sf::Font font;
public:
    game();
    void init();
    bool check();
    int move(Direction dir);
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};