//
//  Cart_Vector.cpp
//  PA3
//
//  Created by David wu on 16/11/4.
//  Copyright © 2016年 David wu. All rights reserved.
//

#include "Cart_Vector.h"
#include <iostream>
using namespace std;
// default constructor
Cart_Vector::Cart_Vector()
{
	x = 0.0;
	y = 0.0;

}
// constructor
Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	x = inputx;
	y = inputy;

}
//overload << operator
ostream& operator<<(ostream& output, const Cart_Vector v1)
{
	output << "<" << v1.x << "," << v1.y << ">";
	return output;
}
//overload * operator
Cart_Vector& operator*(Cart_Vector v1, double d)
{
	double x = v1.x * d;
	double y = v1.y * d;
	Cart_Vector *v2 = new Cart_Vector(x, y);
	return *v2;

}
// overload / operator

Cart_Vector& operator/(Cart_Vector v1, double d)
{
	double x, y;
	if (d == 0) { // check denominator
		x = v1.x;
		y = v1.y;
	}
	else
	{
		x = v1.x / d;
		y = v1.y / d;
	}

	Cart_Vector *v2 = new Cart_Vector(x, y);
	return *v2;
}


