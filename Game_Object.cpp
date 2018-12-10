#include <iostream>
#include "Game_Object.h"
using namespace std;
//a constructor for game object
Game_Object::Game_Object(char in_code, int in_id)
{
	display_code = in_code;
	id_num = in_id;
	location = Cart_Point();
	cout << "Game_Object default constructed."<< endl;
}

Game_Object::Game_Object(char in_code,int in_id, Cart_Point in_loc)
{
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	cout << "Game_Object constructed."<<endl;
}
Cart_Point Game_Object::get_location()
{
	return location;
}
int Game_Object::get_id()
{
	return id_num;
}
bool Game_Object::is_alive()
{
	return true;
}
void Game_Object::show_status()
{
	cout << display_code << id_num << " at " << location ;
}
void Game_Object::drawself(char* ptr)
{
	ptr[0] = display_code;
	ptr[1] = char(id_num+48);

}
Game_Object::~Game_Object()
{
	cout << "Game_Object destructed." << endl;
}
