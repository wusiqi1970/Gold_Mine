#include <iostream>
using namespace std;
#ifndef MODEL_H
#define MODEL_H
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Person.h"
#include "Miner.h"
#include "Soldier.h"
#include "View.h"
#include <list>
//#include "Inspector.h"
class Model
{
private:
	int time;
	list<Game_Object *> object_ptrs; // all the object pointers
	list<Game_Object *> active_ptrs; // object that is alive
	list<Person *> person_ptrs;
	list<Town_Hall *> hall_ptrs;
	list<Gold_Mine *> mine_ptrs;
	Model(const Model &other);//copy constructor
public:
	Model();
	~Model();
	void handle_new_command(Game_Object* ptr);
	Person* get_Person_ptr(int id);
	Gold_Mine* get_Gold_Mine_ptr(int id);
	Town_Hall* get_Town_Hall_ptr(int id);
	list<Gold_Mine *> get_Gold_Mine_list();
	bool update();
	void display(View &view);
	void show_status();

};




#endif