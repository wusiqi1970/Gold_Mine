#include <iostream>
using namespace std;
#ifndef MINER_H
#define MINER_H
#include "Game_Object.h"
#include "Person.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Cart_Vector.h"
#include "Cart_Point.h"
class Miner : public Person
{
public:
	Miner();
	Miner(int in_id, Cart_Point in_loc);
	bool update();
	void start_mining(Gold_Mine *inputMine, Town_Hall *inputhome);
	Cart_Point get_location();
	void show_status();
	~Miner();
private:
	//char display_code;
	//int id_num;
	//char state;
	double amount;
	Cart_Point location;
	Gold_Mine *mine;
	Town_Hall *home;
};









#endif