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
    int col = index % N;
    int row = index / M;

    int move_index = -1;
	if (dir == Direction::Left && col < (N - 1)){
        move_index = index + 1;
    }
	if (dir == Direction::Right && col > 0){
        move_index = index - 1;
    }
	if (dir == Direction::Up && row < (M - 1)){
        move_index = index + M;
    }
	if (dir == Direction::Down && row > 0){
        move_index = index - M;
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

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	sf::Color color = sf::Color(200, 100, 150);

	// Рисуем рамку игрового поля
	sf::RectangleShape shape(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
	target.draw(shape, states);

	// Подготавливаем рамку для отрисовки всех плашек
	shape.setSize(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);

	// Подготавливаем текстовую заготовку для отрисовки номеров плашек
	sf::Text text("", font, 52);

	for (unsigned int i = 0; i < ARRAY_SIZE; i++)
	{
		shape.setOutlineColor(color);
		text.setFillColor(color);
		text.setString(std::to_string(elements[i]));
		if (solved)
		{
			// Решенную головоломку выделяем другим цветом
			shape.setOutlineColor(sf::Color::Cyan);
			text.setFillColor(sf::Color::Cyan);
		}
		else if (elems[i] == i + 1)
		{
			// Номера плашек на своих местах выделяем цветом
			text.setFillColor(sf::Color::Green);
		}

		// Рисуем все плашки, кроме пустой
		if (elems[i] > 0)
		{
			// Вычисление позиции плашки для отрисовки
			sf::Vector2f position(i % M * CELL_SIZE + 10.f, i / N * CELL_SIZE + 10.f);
			shape.setPosition(position);
			// Позицию текста подбирал вручную
			text.setPosition(position.x + 30.f + (elems[i] < 10 ? 15.f : 0.f), position.y + 25.f);
			target.draw(shape, states);
			target.draw(text, states);
		}
	}
}