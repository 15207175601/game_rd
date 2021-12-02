#pragma once
#ifndef __FOOD
#define __FOOD

#include<random>

extern std::default_random_engine dre;
extern std::uniform_int_distribution<int> di;
extern std::vector<std::vector<char>> vvc;
const char food_smb = 'o';

struct Food {
	//int x = 3, y = 2;
	int x = di(dre);
	int y = di(dre);
	bool flag = 1;
	bool eated() {
		return !flag;
	}
	void reset() {
		if (vvc[x][y] == food_smb) vvc[x][y] = ' ';
		x = di(dre);
		y = di(dre);
		flag = 1;
	}
};

#endif //__FOOD