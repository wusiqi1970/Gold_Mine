#include <iostream>
using namespace std;
#include "Town_Hall.h"
Town_Hall::Town_Hall(): Game_Object('t', 1)
{
	state = 'o';
	amount = 0;
	cout << "Town_Hall constructed." << endl;

}
Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc): Game_Object('t', inputId, inputLoc)
{
	state = 'o';
	amount = 0;
	cout << "Town_Hall constructed." << endl;
}

void Town_Hall::deposit_gold(double deposit_amount)
{
	amount += deposit_amount;
}
bool Town_Hall::update()
{
	if (amount >= 50 && state!='u')//when the amount is larger than 50 townhall is upgraded and only upgraded once
	{
		state = 'u';
		display_code = 'T';
		cout << display_code << get_id() << " has been upgraded." << endl;
		return true;
	}
	else if (amount >= 50 && state == 'u') {

		//display_code = 't';
		return false;
	}//else return false
	else{


		//cout << " Not yet upgraded." << endl;
		return false;
	}
	
}
void Town_Hall::show_status()
{
	cout << "Town Hall Status: " << display_code << get_id() << " at (" << get_location().x << "," << get_location().y << ") contains " << amount <<" of gold." ; 
	if (state == 'u')
		cout << " Upgraded." << endl;
	else
		cout << " Not yet upgraded." << endl;

}
Town_Hall::~Town_Hall()
{
	cout << "Town_Hall destructed." << endl;
}