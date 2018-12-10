#include <iostream>
using namespace std;
#include "Miner.h"
#include <iomanip>
Miner::Miner(): Person('M')
{
	//display_code = 'M';
	amount = 0;
	mine = NULL;
	home = NULL;
	state = 's';
	cout << "Miner default constructed." << endl;
}
Miner::Miner(int in_id, Cart_Point in_loc): Person('M', in_id, in_loc)
{
	amount = 0;
	state = 's';
	//display_code = 'M';
	mine = NULL;
	home = NULL;
	cout << "Miner constructed." << endl;
}
bool Miner::update()
{
	bool checker = true;
	if(get_health()<=3)
		display_code = 'm';
	switch (state)
	{
	case's':
	{
		return false;
		break;
	}
	case 'm':
	{
		//cout << "does the program run here?" << endl;
		checker = update_location();
		//cout << "does the program run here?" << endl;
		if (checker == true)//that means it reaches destination
		{
			state = 's';//that means object has arrived at destination
			return true;
		}
		else
		{
			state = 'm';
			return false;
		}
		break;

	}
	case 'o':
	{
		//cout << "does the program run here?" << endl;
		checker = update_location();
		if (checker == true)
		{
			state = 'g';
			return true;
		}
		else
		{
			state = 'o';
			return false;
		}
		break;
	}
	case 'g':
	{
		//cout << "does the program run here?" << endl;
		//double amount1 = mine->get_amount();// the amount of gold before digging
		//double amount2 = mine->get_amount();// the amount of gold after digging
		amount += mine->dig_gold();// the amount that the miner actually dig
		cout << this->display_code << this->get_id() << ": Got " << this->amount << " gold." << endl;
		setup_destination(home->get_location());
		state = 'i';
		return true;
		break;

	}
	case 'i':
	{
		//cout << "does the program run here?" << endl;
		checker = update_location();// call update location to see if it arrives
		if (checker == true)
		{
			state = 'd';
			return true;
		}
		else
			return false;
		break;
	}
	case 'd':
	{
		cout << this->display_code << this->get_id() << ": Deposit " << this->amount << " of gold. " << endl;
		home->deposit_gold(amount);
		amount = 0;
		if (mine->is_empty())
		{
			state = 's';
			cout << "" << this->display_code << this->get_id() << ": More work?" << endl;
			return true;
		}
		else// if the gold mine is not empty keep going
		{
			setup_destination(mine->get_location());
			state = 'o';
			cout << "" << this->display_code << this->get_id() << ": Going back for more." << endl;
			return true;
		}
		break;


	}//case 'd'
	case 'x':
	{
		return false;
		break;
	}
	}//stwich
	return false;
}

void Miner::start_mining(Gold_Mine *inputMine, Town_Hall* inputHome)
{
	if(state != 'x')
	{
		mine = inputMine;
		home = inputHome;
		setup_destination(mine->get_location());//to set up the destination to mine to dig gold
		state = 'o'; //state that represents outbound
		cout << "Miner " << this->get_id() << " mining at Gold_Mine " << mine->get_id() << " and depositing at Town_Hall " << home->get_id() << "." << endl;
		cout << this->display_code << this->get_id() << ": Yes, my lord." << endl;
	}
	else
	{
		cout << display_code << get_id() << " You do not ask a zombie to work bro." << endl;
	}



}
Cart_Point Miner::get_location()
{
	return location;
}
void Miner::show_status()
{
	cout << "Miner status: ";
	Person::show_status();

	if (state == 's')
	{
		cout << " is stopped " << "with health " << get_health() << "." <<endl;

	}
	else if (state == 'm')
	{
		//cout << " moving at speed of " << get_speed() << " towards " << get_destination() << " at each step of " << get_delta()  << endl;
		cout << endl;

	}
	else if (state == 'o')
	{
		cout << " is outbound to a mine " <<"with health " << get_health() << "."<< endl;

	}
	else if (state == 'g')
	{
		cout << " is getting gold from mine " <<"with health " << get_health() << "."<< endl;

	}
	else if (state == 'i')
	{
		cout << " is inbound to home with load: " << this->amount << " with health " << get_health()<< "." <<endl;

	}
	else if ( state == 'd')
	{
		cout << " is depositing gold " <<"with health " << get_health()<< "." << endl;
	}
	else if (state == 'x')
	{
		cout << " is dead. " << endl;
	}
}
Miner::~Miner()
{
	cout << "Miner destructed." <<endl;
}