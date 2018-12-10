#include <iostream>
using namespace std;
#include "Model.h"
Model::Model()
{
	time = 0; // initialize the simulation time
	person_ptrs.push_back(new Miner(1, Cart_Point(5, 1)));  // create miner on the heap

	person_ptrs.push_back(new Miner(2, Cart_Point(10, 1))); 
	
	person_ptrs.push_back(new Soldier(3, Cart_Point(5,15))); // create a soldier on the heap

	person_ptrs.push_back(new Soldier(4, Cart_Point(10,15)));

	//person_ptrs.push_back(new Inspector(5, Cart_Point(5,5)));// create inspector

	for (list<Person *>::iterator i = person_ptrs.begin(); i !=person_ptrs.end(); i++)
	{
		object_ptrs.push_back(*i);// since the iterator is a pointer to a pointer, we have to dereference once 
	}
	mine_ptrs.push_back(new Gold_Mine(1, Cart_Point(1, 20)));

	mine_ptrs.push_back(new Gold_Mine(2, Cart_Point(10, 20)));

	for (list<Gold_Mine *>::iterator j = mine_ptrs.begin();j!=mine_ptrs.end();j++)
	{
		object_ptrs.push_back(*j);

	}

	hall_ptrs.push_back(new Town_Hall());

	for(list<Town_Hall *>::iterator k = hall_ptrs.begin();k!=hall_ptrs.end();k++)
	{
		object_ptrs.push_back(*k);
	}
	for(list<Game_Object *>::iterator l = object_ptrs.begin(); l!=object_ptrs.end();l++)
	{
		active_ptrs.push_back(*l);  // start with all the object pointers
 	}

	cout << "Model constructed." << endl;
}
Model::~Model()
{
	for(list<Game_Object *>::iterator l = object_ptrs.begin(); l!=object_ptrs.end();l++)
	{
		delete (*l);
 	}
	
	cout << "Model destructed." << endl;
}
Person* Model::get_Person_ptr(int id)
{
	for (list<Person *>::iterator i = person_ptrs.begin(); i !=person_ptrs.end(); i++)
	{
		if((*i)->get_id() == id)
		return(*i);
	}
	return NULL;
}
Gold_Mine* Model::get_Gold_Mine_ptr(int id)
{
	for (list<Gold_Mine *>::iterator j = mine_ptrs.begin();j!=mine_ptrs.end();j++)
	{
		if((*j)->get_id() == id)
			return(*j);
	}
	
	return NULL;
}
Town_Hall* Model::get_Town_Hall_ptr(int id)
{
	for(list<Town_Hall *>::iterator k = hall_ptrs.begin();k!=hall_ptrs.end();k++)
	{
		if((*k)->get_id() == id)
			return(*k);
	}
	
	return NULL;

}
bool Model::update()
{
	bool checker; // check if the object got updated
	int counter = 0; // keep track of how many objects have been updated
	time++; // add one tick of time
	for(list<Game_Object *>::iterator l = active_ptrs.begin(); l!=active_ptrs.end();l++) // scan all the live objects
	{
		if ((*l)->is_alive() == false) // those objects that are not alive
		{
			active_ptrs.erase(l);
			cout << "Dead object removed." << endl;
		}

		 
 	}
 	for(list<Game_Object *>::iterator l = active_ptrs.begin(); l!=active_ptrs.end();l++)	
	{
		checker = (*l)->update();//update every object you called
		if (checker == true)
		{
			counter ++;
		}
	}
	//cout << "Time: " << time << endl;
	if (counter > 0)
		return true;//if any objects update return true
	else
		return false; // if not return false
}

void Model::display(View &view)
{
	//cout << "Time: " << time << endl;
	view.clear();
	for(list<Game_Object *>::iterator l = active_ptrs.begin(); l!=active_ptrs.end();l++)
	
	{
		view.plot(*l);
	}
	view.draw();
}
void Model::handle_new_command(Game_Object* ptr)
{
	// check if it is gold_mine
	if(dynamic_cast<Gold_Mine *>(ptr)!=NULL) // then it is a gold_mine
	{
		mine_ptrs.push_back(dynamic_cast<Gold_Mine *>(ptr)); // add to the gold_mine list
		object_ptrs.push_back(dynamic_cast<Gold_Mine *>(ptr)); // add to the object list
		active_ptrs.push_back(dynamic_cast<Gold_Mine *>(ptr)); // add to the active list

	}
	else if(dynamic_cast<Town_Hall *>(ptr)!=NULL) // then it is a townhall
	{
		hall_ptrs.push_back(dynamic_cast<Town_Hall*>(ptr)); // add to the town_hall list
		object_ptrs.push_back(dynamic_cast<Town_Hall *>(ptr)); // add to the object list
		active_ptrs.push_back(dynamic_cast<Town_Hall *>(ptr)); // add to the active list

	}
	else if(dynamic_cast<Miner *>(ptr)!=NULL ) // then it is a miner O
	{
		person_ptrs.push_back(dynamic_cast<Miner *>(ptr)); // add to the person list
		object_ptrs.push_back(dynamic_cast<Miner *>(ptr)); // add to the object list
		active_ptrs.push_back(dynamic_cast<Miner *>(ptr)); // add to the active list

	}
	else if(dynamic_cast<Soldier *> (ptr)!=NULL)
	{
		person_ptrs.push_back(dynamic_cast<Soldier *> (ptr));
		object_ptrs.push_back(dynamic_cast<Soldier *>(ptr));
		active_ptrs.push_back(dynamic_cast<Soldier *> (ptr));
	}
	/*else if(dynamic_cast<Inspector *>(ptr)!=NULL)
	{
		person_ptrs.push_back(dynamic_cast<Inspector *> (ptr));
		object_ptrs.push_back(dynamic_cast<Inspector *>(ptr));
		active_ptrs.push_back(dynamic_cast<Inspector *> (ptr));
	}*/
	

}
list<Gold_Mine *> Model::get_Gold_Mine_list()
{
	return mine_ptrs;
}
void Model::show_status()
{
	cout << "Time: " << time << endl;
	for(list<Game_Object *>::iterator l = object_ptrs.begin(); l!=object_ptrs.end();l++)

	
	{
		//cout << "model show status: " << i << endl;
		(*l)->show_status();
	}
}
Model::Model(const Model &other)
{

}
