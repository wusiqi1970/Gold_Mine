#include <iostream>
using namespace std;
#include "View.h"
View::View()
{
	size = 11;
	scale = 2;
	origin = Cart_Point();
}
View::~View()
{
	cout << "  " << endl; 
}
bool View::get_subscripts(int &ix, int&iy, Cart_Point location)
{
	ix = (location.x - origin.x) / scale;
	iy = (location.y - origin.y) / scale;
	if ( ix > view_maxsize or iy > view_maxsize)
	{
		cout << "An object is outside the display." << endl; // outside the grid
		return false;
	}
	else
		return true;
}
void View::clear()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			grid[i][j][0] = '.'; // DOT 
			grid[i][j][1] = ' '; // EMPTY SPACE FOR THE NEXT
		}// for int j
	} // for int i
}
void View::plot(Game_Object* ptr)
{
	int ix = 0;
	int iy = 0; // create integer to store get subscripts
	if (get_subscripts(ix, iy, ptr->get_location()) == true) // gives us the accurate x and y coordinates
	{
		if (grid[iy][ix][0] == '.' && grid[iy][ix][1] == ' ')
		{


			ptr->drawself(grid[iy][ix]);
		}// row is the y index, column is the x index

		else
		{
			grid[iy][ix][0] = '*';  // if two objects overlap it will be a *
			grid[iy][ix][1] = ' ';  
		}
	}//if get sub_scripts
}
void View::draw()
{
	int plotter = int(size * scale); // how many grid to draw
	for (int i = size - 1 ; i >= 0; i--)
	{
		plotter -= scale;
		if (plotter >= 10 && (plotter == 12 or plotter == 16 or plotter == 20))
		{
			cout << plotter;
		}
		else if (plotter < 10 && (plotter == 0 or plotter == 4 or plotter == 8))
		{
			cout << plotter << " ";
		}
		else if (plotter == 2 or plotter == 6 or plotter == 10 or plotter == 14 or plotter == 18)
		{
			cout << "  " ; // two empty space just to match the previous line
		}
		for (int k = 0; k < size; k++)
		{
			cout << grid[i][k][0];
			cout << grid[i][k][1];
		}
		cout << endl;
	}
	cout << "  0   4   8   12  16  20" << endl;// just a last line of number


}
