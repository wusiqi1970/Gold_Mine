#include <iostream>
#include <cmath>
using namespace std;
#include "Person.h"
Person::Person(char in_code): Game_Object(in_code, 1)
{
	health = 5;
	destination = Cart_Point();
	delta = Cart_Vector();
	speed = 5;
	cout << "Person default constructed." << endl;

}
Person::Person(char in_code, int in_id, Cart_Point in_loc): Game_Object(in_code, in_id, in_loc)
{
	health = 5;
	speed = 5;
	destination = Cart_Point();
	delta = Cart_Vector();
	cout << "Person constructed." << endl;
}
bool Person::is_alive()
{
	if ( state == 'x')
		return false; // return false if it is dead
	else
		return true; // return true if it is still alive 
}
void Person::take_hit(int attack_strength)
{
	health = health - attack_strength; // take hit
	
	if (health <= 0 && state != 'x')
	{
		state = 'x' ;
		cout << display_code << get_id() << ": Arrggh I am dying!" << endl;
	}
	else if( health > 0)
	{
		
		cout << display_code << get_id() << ": Ouch!" << endl;
	}


	
}
void Person::start_attack (Person *target)
{
	if (is_alive() == true){
		cout << display_code << get_id() << "I can't attack." << endl;
	}
	else
		cout << display_code << get_id() << "I can't attack. I am also dead." << endl;
}
void Person::start_moving(Cart_Point dest)
{
	if (is_alive() == true) {
		setup_destination(dest);
		state = 'm';

		cout << "Moving " << this->get_id() << " to " << dest << endl;
		if (dest.x == this->get_location().x && dest.y == this->get_location().y)
		{
			cout << this->display_code << this->get_id() << ": I'm already there. see?" << endl;
			state = 's';
		}
		else {
			cout << "" << this->display_code << this->get_id() << " : On my way." << endl;

		}// else 

	}
	else if (is_alive() == false)
	{
		cout << display_code << get_id() << ": I am dead. You cannot see me. " << endl;
	}


}
void Person::stop()
{
	state = 's';
	//cout << "Stopping " << this->get_id() << endl;
	cout << "" << this->display_code << this->get_id() << ": Stopped." << endl;
}
void Person::show_status()
{
	Game_Object::show_status();

	if (state == 'm')
		cout << " moving at a speed of " << speed << " towards " << destination << " at each step of " << delta;
	else if (state == 'o' or state == 'i' or state == 'g' or state == 'd')
		cout << " moving at a speed of " << speed << " towards " << destination << " at each step of " << delta ;//cout <<" moving at a speed of " << speed <<" towards " << get_location() <<" at each step of "<< Cart_Vector() << "." << endl;
}
bool Person::update_location()// return true if person arriaved at destination
{
	//check to see if the person is within one step of destination
	if ((fabs(destination.x - get_location().x) <= fabs(delta.x)) && (fabs(destination.y - get_location().y) <= fabs(delta.y)))
	{
		location = destination;
		cout << this->display_code << this->get_id() << " : I'm there! " << endl;
		return true;
	}
	else//if not just move one step advance
	{
		location = location + delta;
		//cout << "does the program run here?" << endl;
		cout << "" << this->display_code << this->get_id() << ": step..." << endl;
		return false;
	}

}
void Person::setup_destination(Cart_Point dest)
// set up destination for person in order to go to that dest
{
	this->destination = dest;
	if (cart_distance(destination, get_location()) == 0)
	{
		delta.x = 0.0;
		delta.y = 0.0;

	}
	else
		this->delta = (destination - get_location()) * (speed / cart_distance(destination, get_location()));
}
double Person::get_speed()
{
	return speed;
}
Cart_Vector Person::get_delta()
{
	return delta;
}
Cart_Point Person::get_destination()
{
	return destination;
}
Person::~Person()
{
	cout << "Person destructed." << endl;
}
int Person::get_health()
{
	return health;
}
void Person::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
{
	if(is_alive())
	{
		cout << display_code << get_id() << ": Sorry, I can't work a mine." << endl;
	}
	else	
		cout << display_code << get_id() << ": Sorry, I can't work a mine. I am also dead." << endl;
}
/*void Person::start_inspecting(Model* model){
	cout << display_code << get_id() << ": Sorry, I can't inspect."<< endl;
}*/