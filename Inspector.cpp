#include "Inspector.h"
#include <iostream>
using namespace std;
Inspector::Inspector():Person('I')
{
	Gold_Mine* mine = NULL;
	cout << "Inspector constructed." <<endl;
}
Inspector::Inspector(int in_id, Cart_Point in_loc):Person('I',in_id,in_loc)
{
	Gold_Mine* mine = NULL;
	cout << "Inspector constructed." << endl;
}

void Inspector::start_inspecting(Model* model)
{
	not_inspected = model->get_Gold_Mine_list();
	state = 'o';
	cout << display_code << get_id() << "starting to inspect." << endl;
}

bool Inspector::update()
{
	Cart_Point des;
	double distance = 100.0;
	double tempt;
	bool checker;
	switch(state)
	{
		case's':
		{
			return false;
			break;
		}
		case'c': //complete trip
		{
			state = 's';
			return true;
			break;

		}
			
		case 'o':
		{
			for (list<Gold_Mine *>::iterator j = not_inspected.begin();j!=not_inspected.end();j++)
			{
				des = (*j)->get_location();
				tempt = cart_distance(des,location); // the distance between the inspector and gold mine
				if(tempt<distance)
				{
					distance = tempt;
					mine = *j;
				}
			}
			setup_destination(mine->get_location());
			distance = 100.0;
			if(update_location())
			{
				been_inspected.push(mine);
				not_inspected.remove(mine);
				cout << "Number of been_inspcted now: " << been_inspected.size() << endl;
				state = 'g';
				return true;
			}
			else
				return false;
			break;


		}
		case'g':
		{
			cout << display_code << get_id() << "This mine contains " << mine->get_gold_amount() << " of gold." << endl;
			if(not_inspected.empty() == false)
			{
				cout << "Goint to next mine." << endl;
				state = 'o';
				return true;
			}
			else
			{
				cout << "Going back." << endl;
				state = 'i';
				return true;
			}
		break;
		}
		case 'i':
		{
			mine = been_inspected.top();
			setup_destination(mine->get_location());
			if(update_location())// if arrived
			{
				been_inspected.pop();
				state = 'd';
				return true;
			}
			else
				return false;
		break;
		}
		case'd':
		{
			cout << display_code << get_id() << ": This mine contains " << mine->get_gold_amount() << " of gold." << endl;
			if(been_inspected.empty() == false)
				state = 'i';
			else
				state = 'c';
			return true;
			break;
		}
		case'x':
		return false;
		break;



	}
	return false;
}



void Inspector::show_status()
{
	cout << "Inspector status: ";
	Person::show_status();
	if(state == 's')
	{
		cout << " is stopped. " << endl;

	}
	else if( state == 'c')
	{
		cout << " inspection complete." << endl;
	}
	else if (state == 'o')
	{
		cout << " starts outbound inspecting. " << endl;
	}
	else if( state =='g')
	{
		cout <<" outbound inspection. " << endl;
	}
	else if (state == 'd')
	{
		cout << " inbound inspetion." << endl;
	}
	else if (state == 'i')
	{
		cout << " starts inbound inspecting.  " << endl;
	}
	else if (state == 'x')
	{
		cout << " is dead." << endl;
	}


}