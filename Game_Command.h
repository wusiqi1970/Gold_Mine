#include <iostream>
using namespace std;
#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H
#include "Model.h"
#include "Input_Handling.h"
#include "Inspector.h"
void do_move_command(Model *model);
void do_work_a_mine_command(Model *model);
void do_stop_command(Model *model);
void do_run_command(Model *model);
void do_go_command(Model *model);
void do_quit_command(Model *model);
void do_list_command(Model *model);
void do_attack_command(Model *model);
void create_new_command(Model *model);
int get_int(int ID);
double get_double(double x);
//void do_inspect_command(Model *model);
#endif