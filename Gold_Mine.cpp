#include <iostream>
using namespace std;
#include "Gold_Mine.h"
Gold_Mine::Gold_Mine():Game_Object('G',0)//inherit from game object
{
	state = 'f';
	amount = 100;
	cout << "Gold_Mine constructed. " << endl;
}
Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc):Game_Object('G',inputId,inputLoc)
{
	amount = 100 ;
	state = 'f';
	cout << "Gold_Mine constructed." << endl;
}
bool Gold_Mine::is_empty()//check if the gold mine is empty
{
	if (amount == 0)
		return true;
	else
		return false;
}
double Gold_Mine::dig_gold(double amount_to_dig)
{
	if (amount >= amount_to_dig)
	{
		amount -= amount_to_dig;//subtract the gold taken away from the gold mine
		return amount_to_dig;
	}
	else
	{
		double tempt = amount;
		amount = 0;
		return tempt;
	}
}
bool Gold_Mine::update()
{
	if ((is_empty() && (state != 'e')) == true)// if the gold mine is empty and state is not e
	{
		state = 'e';//so we only set it once 
		display_code = 'g';
		cout << "Gold Mine " << get_id() << " has been depleted." << endl;
		return true;
	}
	else
		return false;
}
double Gold_Mine::get_gold_amount()
{
	return amount;
}
void Gold_Mine::show_status()
{
	cout << "Gold Mine Status: " << display_code << get_id() << " at location (" << get_location().x << "," << get_location().y << ") Contains " << amount << "." << endl;
}
Gold_Mine::~Gold_Mine()
{
	cout << "Gold_Mine destructed." << endl;
}