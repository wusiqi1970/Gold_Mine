#include <iostream>
using namespace std;
#include "Game_Command.h"
int get_int()
{
	int i;
	if(!(cin>>i))
		throw Invalid_Input("Expect an integer.");
	return i;
}

double get_double()
{
	double i;
	if(!(cin>>i))
		throw Invalid_Input("Expect a double.");
	return i;
}
void do_move_command(Model *model)
{
	int ID;
	double x, y;
	try
	{
		ID = get_int();
		x = get_double();
		y = get_double();
		Cart_Point d = Cart_Point(x,y);
		Person* p = model->get_Person_ptr(ID);
		if(p == (Person*)NULL) // check for valid ID num for person
			throw Invalid_Input("Not a valid id for person.");
		model->get_Person_ptr(ID)->start_moving(Cart_Point(x, y)); // call start moving for every miner that got the m command

	}
	catch(Invalid_Input& exception)
	{
		throw;
		
	}
	return;
	

	
}
void do_work_a_mine_command(Model *model)
{
	int ID1, ID2, ID3;
	try{
	if(!(cin >> ID1))
		throw Invalid_Input("We expect a int for ID1.");
	if(!(cin >> ID2))
		throw Invalid_Input("We expect a int for ID2.");
	if(!(cin >> ID3))
		throw Invalid_Input("We expect a int for ID3.");
	Person* p = model->get_Person_ptr(ID1);
	if(p == (Person*)NULL) // if no id get for person
		throw Invalid_Input("Not a valid id for person.");
	Gold_Mine* g= model->get_Gold_Mine_ptr(ID2);
	if(g == (Gold_Mine*) NULL)
		throw Invalid_Input("Not a valid id for gold mine.");
	Town_Hall* t = model->get_Town_Hall_ptr(ID3);
	if(t == (Town_Hall*) NULL)
		throw Invalid_Input("Not a valid id for town hall.");
	model->get_Person_ptr(ID1)->start_mining(model->get_Gold_Mine_ptr(ID2), model->get_Town_Hall_ptr(ID3)); // call start mining for every miner that got the w command
	
	//model->get_Person_ptr(ID1)->start_mining(model->get_Gold_Mine_ptr(ID2), model->get_Town_Hall_ptr(ID3)); // call start mining for every miner that got the w command
}

catch(Invalid_Input& exception)
	{
		throw;
	}
	return;
}
void do_stop_command(Model *model)
{
	int ID;
	try{
	if(!(cin >> ID))
		throw Invalid_Input("We expect a int for ID");
	Person* p = model->get_Person_ptr(ID);
	if(p==NULL)
		throw Invalid_Input("Not a Valid id for person.");
	model->get_Person_ptr(ID)->stop(); // stop the miner
}
catch(Invalid_Input& exception)
{
	throw;
}
return;
}
void do_go_command(Model *model)
{
	cout << "Advancing one tick." << endl;
	bool updating = model->update(); // just call update
}
void do_run_command (Model *model)
{
	cout << "Advancing to next event." << endl;
	int counter = 0;
	bool updating = false;
	while (counter < 5 && updating == false)
	{
		//cout << "show updating..." << updating << endl;
		updating = model->update();
		counter ++;

	}
}
void do_attack_command(Model *model)
{
	int ID1, ID2;
	try{
		if(!(cin >> ID1))
			throw Invalid_Input("Expect an int for ID1");
		if(!(cin >> ID2))
			throw Invalid_Input("Expect an int for ID2");
		Person* p1 = model->get_Person_ptr(ID1);
		Person* p2 = model->get_Person_ptr(ID2);
		if(p1 == NULL ||p2 == NULL)
			throw Invalid_Input("Not valid id for a person.");
		model->get_Person_ptr(ID1)->start_attack(model->get_Person_ptr(ID2)); // start attack ID2
}
catch(Invalid_Input& exception)
{
	throw;
}
return;
}

void do_list_command(Model *model)
{
	model->show_status(); // list all the status

}

void create_new_command(Model *model)
{
	try{
		char type;
		int ID;
		double x,y;
		Game_Object* ptr;
		if(!(cin>>type))
			throw Invalid_Input("Expect a char for type");
		if(!(cin>>ID))
			throw Invalid_Input("Expect an int for ID");
		switch(type)
		{
			case'g':
			if(model->get_Gold_Mine_ptr(ID) == NULL) // no existing gold mine
			{
				if(!(cin>>x)||!(cin>>y))
					throw Invalid_Input("Coordinates must be double");
				ptr = new Gold_Mine(ID,Cart_Point(x,y)); // create the new type

				model->handle_new_command(ptr); // add new pointer to the model;
			}
			else
			{
				throw Invalid_Input("Duplicate Id.");
			}
			break;

			case't':
			
				if(model->get_Town_Hall_ptr(ID) == NULL)
				{
					if(!(cin>>x)||!(cin>>y))
						throw Invalid_Input("Coordinates must be double");
					ptr = new Town_Hall(ID,Cart_Point(x,y));
					model->handle_new_command(ptr); // add new pointer to the list
				}
				else
				{
					throw Invalid_Input("Duplicate Id.");

				}
				break;
			case'm':
				if(model->get_Person_ptr(ID) == NULL) // there is a miner

				{
					if(!(cin>>x)||!(cin>>y))
						throw Invalid_Input("Coordinates must be double");
					ptr = new Miner(ID,Cart_Point(x,y));
					model->handle_new_command(ptr);
				}
				else
					{
					throw Invalid_Input("Duplicate Id.");

				}
				break;
				case's':
					if(model->get_Person_ptr(ID) == NULL)
					{
						if(!(cin>>x)||!(cin>>y))
						throw Invalid_Input("Coordinates must be double");
						ptr = new Soldier(ID,Cart_Point(x,y));
						model->handle_new_command(ptr);
					}
					else
						{
					throw Invalid_Input("Duplicate Id.");

				}
				break;
				/*case'i':
				{
					if(model->get_Person_ptr(ID) == NULL)
					{
						if(!(cin>>x)||!(cin>>y))
						throw Invalid_Input("Coordinates must be double");
						ptr = new Inspector(ID,Cart_Point(x,y));
						model->handle_new_command(ptr);
					}
					else
						throw Invalid_Input("Duplicate ID.");

				}*/






			

		}//switch type

	} // try
	catch(Invalid_Input& exception)
	{
		throw;
	}
	return;
}
/*void do_inspect_command(Model* model)
{
	int ID;
	cin >> ID;
	model->get_Person_ptr(ID)->start_inspecting(model);
}*/
