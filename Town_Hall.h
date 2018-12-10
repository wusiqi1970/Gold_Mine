#include <iostream>
using namespace std;
#ifndef TOWN_HALL_H
#define TOWN_HALL_H
#include "Cart_Point.h"
#include "Game_Object.h"
class Town_Hall : public Game_Object
{
private:
	//char display_code;
	//int id_num;
	//char state;
	double amount;
	//Cart_Point location;
public:
	Town_Hall ();
	Town_Hall(int inputId, Cart_Point inputLoc);
	//Cart_Point get_location();
	//int get_id();
	void deposit_gold(double deposit_amount);
	bool update();
	void show_status();
	~Town_Hall();

};
#endif
