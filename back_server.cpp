#include <ctime>
#include <iostream>
#include <conio.h>
#include "snake.hpp"
using namespace std;


void print_all(vector<vector<char>>&);
char print_game_over(Snake&);
char c;
int speed = 200;
void delay(int time) {
	clock_t now = clock();
	while (clock() - now < time) {
		if (_kbhit()) {
			c = _getch();
		}
		print_all(vvc);
	}
}

char run(Snake& snake, Food& food) {
	auto beg = snake.gethead();
	auto end = snake.gettail();
	while (snake.size() < max_size && snake.live()) {
		vvc[beg.first][beg.second] = body_smb;
		while (vvc[food.x][food.y] == body_smb || food.eated())
			food.reset();
		vvc[food.x][food.y] = food_smb;
		print_all(vvc);
		int temp = speed - snake.size() * 10;
		delay(temp > 100 ? temp : 100);
		snake.setstatus(c);
		snake.eat(food);
		beg = snake.gethead();
		if (end != snake.gettail()) {
			vvc[end.first][end.second] = ' ';
			end = snake.gettail();
		}
	}
	return print_game_over(snake);
}