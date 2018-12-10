#include <iostream>
using namespace std;
#ifndef SOLDIER_H
#define SOLDIER_H
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
class Soldier:public Person
{
private:
	int attack_strength;
	double range;
	Person *target;
public:
	Soldier();
	Soldier(int in_id, Cart_Point in_loc);
	void start_attack(Person *in_target);
	bool update();
	void show_status();
	~Soldier();
};
#endif