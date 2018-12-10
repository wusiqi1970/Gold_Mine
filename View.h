#include <iostream>
using namespace std;
#ifndef VIEW_H
#define VIEW_H
#include "Cart_Point.h"
#include "Game_Object.h"
const int view_maxsize = 20;
class View
{
private:
	int size;
	double scale;
	Cart_Point origin;
	char grid[view_maxsize][view_maxsize][2];
	bool get_subscripts(int &ix, int&iy, Cart_Point location);
public:
	View();
	~View();
	void clear();
	void plot(Game_Object* ptr);
	void draw();

	friend class Model;
	friend void Game_Object::drawself(char* grid);
};
#endif
