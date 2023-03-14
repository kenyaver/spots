#include "game.hpp"

// shrifts and void init
game::game(){

    if(!font.loadFromFile("FreeMonoBold.ttf")){
        font.loadFromFile("arial.ttf");
    }

    init();
}

// all elems = 0 
void game::init(){

    for(int i = 0; i < size - 1; i ++){
        elems[i] = 0;
    }
    solve = true;
}

bool game::check(){
    for(int i = 0; i < N -1; i++){
        if (elems[i] == 1 && move_elem[i] == false){
            return false;
        }
    }
    return true;
}

