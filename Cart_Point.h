//
//  Cart_Point.h
//  PA3
//
//  Created by David wu on 16/11/4.
//  Copyright © 2016年 David wu. All rights reserved.
//

#include <iostream>


using namespace std;

#ifndef CART_POINT_H
#define CART_POINT_H
#include "Cart_Vector.h"

class Cart_Point
{
public:
	double x;
	double y;
	Cart_Point();
	Cart_Point(double, double);

};
double cart_distance(Cart_Point, Cart_Point);

ostream& operator<<(ostream& , const Cart_Point);

Cart_Point& operator + (Cart_Point, Cart_Vector);

Cart_Vector& operator - (Cart_Point, Cart_Point);

#endif /* Cart_Point_h */
