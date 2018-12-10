#ifndef INSPECTOR_H
#define INSPECTOR_H
#include "Person.h"
#include "Gold_Mine.h"
#include "Model.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <iostream>
#include <list>
#include <stack>
using namespace std;
class Inspector:public Person
{
public:
	Inspector();
	Inspector(int in_id, Cart_Point in_loc);
	void start_inspecting(Model* model);
	bool update();
	void show_status();
private:
	Gold_Mine* mine;
	list<Gold_Mine *> not_inspected;
	stack<Gold_Mine *> been_inspected;
	stack<double>amount_list;
};
#endif