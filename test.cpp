#include"snake.hpp"
char run(Snake&, Food&);
char print_base();

extern std::default_random_engine dre;


int main() {
	Snake snake;
	Food food;
	char mod = print_base();
	while ( mod != 'q') {
		mod=run(snake, food);
		dre = std::default_random_engine();
		snake.reset();
		food.reset();
	}
	return 0;
}
