#include <iostream>
using namespace std;
#ifndef PERSON_H
#define PERSON_H
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"


class Person: public Game_Object
{
public:
	//Person();
	Person(char in_code);
	Person(char in_code, int in_id, Cart_Point in_loc);
	void start_moving(Cart_Point dest);
	void stop();
	void show_status();
	Cart_Vector get_delta();
	double get_speed();
	Cart_Point get_destination();
	bool is_alive();
	void take_hit(int attack_strength);
	virtual void start_attack(Person *target);
	virtual ~Person();
	virtual void start_mining(Gold_Mine* inputMine,Town_Hall* inputHome);
protected:
	bool update_location();
	void setup_destination(Cart_Point dest);
	int get_health();
private:
	int health;
	double speed;
	Cart_Point destination;
	Cart_Vector delta;



};






#endif 