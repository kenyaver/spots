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

int game::move(Direction dir){
    int col = index % size;
    int row = index / size;

    int move_index = -1;
	if (dir == Direction::Left && col < (size - 1)){
        move_index = index + 1;
    }
	if (dir == Direction::Right && col > 0){
        move_index = index - 1;
    }
	if (dir == Direction::Up && row < (size - 1)){
        move_index = index + size;
    }
	if (dir == Direction::Down && row > 0){
        move_index = index - size;
    }

    if (empty_index >= 0 && move_index >= 0)
	{
		int tmp = elements[index];
		elements[index] = elements[move_index];
		elements[move_index] = tmp;
		index = move_index;
	}
	solve = Check();
}

