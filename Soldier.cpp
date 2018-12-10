#include <iostream>
#include "Soldier.h"
using namespace std;
Soldier::Soldier(): Person('S')
{
	attack_strength = 2;
	state = 's';
	range = 2.0;
	cout << "Soldier constructed." << endl;
}
Soldier::Soldier(int in_id , Cart_Point in_loc): Person('S', in_id, in_loc)
{
	attack_strength = 2;
	state = 's';
	range = 2.0;
	cout << "Soldier constructed." << endl;

}
void Soldier::start_attack(Person *in_target)
{
	//target = in_target;
	if (state != 'x') // if soldier is alive then attack the target
	{
		if (cart_distance(this->get_location(), in_target->get_location()) <= range)
		{
			cout << display_code << get_id() << ": Clang!" << endl;
			target = in_target;// save the target
			state = 'a'; // into attack mode

		}
		else
		{
			cout << "Target is out of range." << endl;
		}

	}
	else
	{
		cout << display_code << get_id() << ": I am dead, you cannot command a zombie to attack." << endl;
	}
}
bool Soldier::update()
{
	if(get_health()<=3)
		display_code = 's';
	switch (state)
	{
	case 'x':
	{
		return false;
		break;
	}
	case 's':
	{
		return false;
		break;
	}
	case 'm':
	{
		if (update_location() == true) // if arrived
		{
			state = 's'; // stop
			return true;
		}
		else  // if not arrived
		{
			state = 'm';
			return false;
		}
		break;
	}
	case 'a':
	{
		double dis = cart_distance(this->get_location(), target->get_location()); // the distance between soldier and target
		if (is_alive()) {
			if (dis <= range)
			{
				if (target->is_alive() == false)
				{
					cout << display_code << get_id() <<  ": I triumph! " << endl;
					state = 's';
					return true;
					break;
				}
				else
				{
					target->take_hit(attack_strength); // hit the target
					cout << display_code << get_id() << ": take that!" << endl;
					//state = 'a'; // stay in the state
					return false;
					break;
				}

			}
			else if (dis > range)
			{
				state = 's';
				return true;
			}
		}
			else if (!is_alive())
			{
				state = 'x';
				return true;
			}



			break;//else
		}// case a

	}// switch
	return false;
}
void Soldier::show_status()
	{
		cout << "Soldier status: " ;
		Person::show_status();
		//cout << "what is the state now? x? a?" << state << endl;
		if (state == 'a')
			cout << " is attacking " << "with health " << get_health() << "."<< endl;
		else if (state == 's')
		{
			cout << " is stopped " << "with health " << get_health()<< "." << endl;

		}
		else if (state == 'm')
		{
			//cout << " moving at speed of " << get_speed() << " towards " << get_destination() << " at each step of " << get_delta()  << endl;
			cout <<" with health " << get_health() << "." << endl;

		}
		else if (state == 'x')
		{
			cout << " is dead." << endl;
		}



	}
Soldier::~Soldier()
{
	cout << "Soldier destructed." << endl;
}