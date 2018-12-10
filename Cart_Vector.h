//
//  Cart_Vector.h
//  PA3
//
//  Created by David wu on 16/11/4.
//  Copyright © 2016年 David wu. All rights reserved.
//
#include <iostream>
using namespace std;

#ifndef CART_VECTOR_H
#define CART_VECTOR_H

class Cart_Vector
{
public:
	double x;
	double y;
	Cart_Vector();
	Cart_Vector(double, double);


};
Cart_Vector& operator* (Cart_Vector, double);
Cart_Vector& operator/(Cart_Vector, double);
ostream& operator<<(ostream& , const Cart_Vector);


#endif /* Cart_Vector_h */
