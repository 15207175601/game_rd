#include "snake.hpp"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <conio.h>
using std::cout;
using std::endl;
using std::vector;
using std::string;
string path_r = "result.txt";
string path_g = "grade.txt";

std::default_random_engine dre;
std::uniform_int_distribution<int> di(0, 4);
vector<vector<char>> vvc
(width - 2, vector<char>(width - 2, ' '));

void print(vector<char>& vc) {
	string s;
	s += wall_smb;
	for (auto p = vc.begin(); p != vc.end(); ++p) {
		s += ' ';
		s += *p;
	}
	s += ' ';
	s += wall_smb;
	puts(s.c_str());
}

void print_all(vector<vector<char>>& vvc) {
	system("cls");//windows
		//system("printf \"\\033c\"");
	string s(2 * width - 1, wall_smb);
	puts(s.c_str());
	for (int i = 0; i < (width - 2); ++i)
		print(vvc[i]);
	puts(s.c_str());
}
void writer(string path,string res) {
	std::ofstream fout;
	fout.open(path, std::ios::app);
	if (!fout) {
		cout << "error in opening file" << endl;
		return;
	}
	fout << res << endl;
	fout.close();
}
char print_base() {
	system("cls");
	int ans = 0;
	std::ifstream(path_g) >> ans;
	//fin.open("result.txt",)
	cout << "the snake rules." << endl;
	cout << "press four keys \"�������� \" to change the way." << endl;
	cout << "the hightest garde is: " << ans << endl;
	cout << "press a key to start the game.('q' to quit)";
	return _getch();
}

char print_game_over(Snake& snake) {
	string res;
	int grade = snake.size() - 1;
	if (snake.live())
		res="you are the winner,your gardes is:"+ std::to_string(grade);
	else
		res="your grade is:"+ std::to_string(grade);
	cout << res << endl;
	int history;
	std::ifstream(path_g) >> history;
	if (!history||grade > history) {
		std::ofstream(path_g) << grade;
	}
	writer(path_r, res);
	cout << "press a key to start the game.('q' to quit, 'b' to back the menu.)";
	char c = _getch();
	if (c == 'b')
		return print_base();
	else
		return c;
}

