#include <ctime>
#include <iostream>
#include <conio.h>
#include "snake.hpp"
using namespace std;


void print_all(vector<vector<char>>&);
char print_game_over(Snake&);
void set_cursor(int x, int y, char c);
char c;
unsigned int speed = width*30;
int limit_spped = 250;
void delay(int time) {
	clock_t now = clock();
	while (clock() - now < time) {
		if (_kbhit()) {
			c = _getch();
		}
	}
}

char run(Snake& snake, Food& food) {
	auto beg = snake.gethead();
	auto end = snake.gettail();
	print_all(vvc);
	while (snake.size() < max_size && snake.live()) {
		vvc[beg.first][beg.second] = head_smb;
		set_cursor(beg.first, beg.second, head_smb);
		while (vvc[food.x][food.y] == body_smb||
			vvc[food.x][food.y] ==head_smb|| food.eated())
			food.reset();
		vvc[food.x][food.y] = food_smb;
		set_cursor(food.x, food.y, food_smb);
		int temp = speed - snake.size() * width;
		delay(temp> limit_spped ?temp: limit_spped);
		snake.setstatus(c);
		snake.eat(food);
		beg = snake.gethead();
		if (end != snake.gettail()) {
			vvc[end.first][end.second] = base_smb;
			set_cursor(end.first, end.second, base_smb);
			end = snake.gettail();
		}
	}
	return print_game_over(snake);
}