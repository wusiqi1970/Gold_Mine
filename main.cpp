#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Soldier.h"
#include "Person.h"
#include "Miner.h"
#include "Model.h"
#include "View.h"
#include "Input_Handling.h"
#include "Game_Command.h"

using namespace std;
void initialize()
{
	cout << "EC327: Programming Assignment 4 -- Fall 2016 " << endl;
}
int main()
{
	initialize();
	Model *model = new Model();
	View *view = new View();
	model->show_status();
	bool not_quit = true;
	

	while (not_quit)
	{
		char command;
		model->display(*view);
		cout << "Enter command: ";
		
		//cin >> command;
		try{
			if(!(cin>>command))
				throw Invalid_Input("Invalid command");

			switch (command)
			{
			case'm':
			{
				do_move_command(model);
				break;
			}
			case 'g':
			{
				do_go_command(model);
				model->show_status();
				break;
			}
			case'r':
			{
				do_run_command(model);
				model->show_status();

				break;
			}
			case'w':
			{
				do_work_a_mine_command(model);
				break;
			}
			case 's':
			{
				do_stop_command(model);
				break;
			}
			case 'a':
			{
				do_attack_command(model);
				break;
			}
			case'n':
			{
				create_new_command(model);
				break;
			}
			case 'q':
			{
				not_quit = false;// sign of quitting the program
				cout << "Terminating program." << endl;
				delete model;
				delete view;
				return 0;
				break;

			}
			/*case'i':
			{
				do_inspect_command(model);
				break;
			}*/
			// case 'q'
			default:
				throw Invalid_Input("Illegal Format. Enter Again.");
				break;
		

		}// switch
	
	
}//try
catch(Invalid_Input& exception)
{
	cout << exception.msg_ptr << endl;
	cin.clear(); // clear the user input 
	cin.ignore();
	
	
}
	
}// while not quit
}// main
