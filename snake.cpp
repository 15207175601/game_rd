#include "snake.hpp"
/*using std::vector;
using std::pair;
inline char get_vvc(vector<vector<char>>& vvc, const pair<int, int>& p) {
	return vvc[p.first][p.second];
}
inline void set_vvc(vector<vector<char>>& vvc, const pair<int, int>& p, const char& c) {
	vvc[p.first][p.second] = c;
}*/
void set_cursor(int x, int y, char c);

std::pair<int, int> Snake::next() const {
	auto temp = gethead();
	switch (getstatus()) {
	case Status::up:
		return{ temp.first - 1,temp.second  };
	case Status::down:
		return{ temp.first + 1,temp.second  };
	case Status::right:
		return{ temp.first ,temp.second + 1 };
	case Status::left:
		return{ temp.first ,temp.second - 1 };
	default:
		return temp;
	}
}
bool Snake::check(std::pair<int, int>& p) const {
	if (p.first < 0 || p.first > norm_size-1 || p.second < 0 || p.second>norm_size-1 ||
		vvc[p.first][p.second] == body_smb)
		return false;
	return true;
}

void Snake::eat(Food& food) {
	auto temp = next();
	while (temp == body.front())
		temp = next();
	if (check(temp)) {
		set_cursor(body.front().first, body.front().second, body_smb);
		body.push_front(temp);
		if (temp.first == food.x && temp.second == food.y)
			food.flag = false;
		else
			body.pop_back();
	}
	else {
		alive = false;
		return;
	}
}

void Snake::setstatus(char c) {
	switch (c)
	{
	case 72:
		if(getstatus()!= Status::down)
			this->stat = Status::up;
		break;
	case 80:
		if (getstatus() != Status::up)
			this->stat = Status::down;
		break;
	case 75:
		if (getstatus() != Status::right)
			this->stat = Status::left;
		break;
	case 77:
		if (getstatus() != Status::left)
			this->stat = Status::right;
		break;
	default:
		break;
	}
}
void Snake::reset() {
	while (!this->body.empty()) {
		vvc[this->body.front().first][this->body.front().second] = ' ';
		this->body.pop_front();
	}
	body = { std::pair<int, int>(birth, birth) };
	stat = Status::up;
	alive = true;
}
