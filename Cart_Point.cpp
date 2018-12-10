//
//  Cart_Point.cpp
//  PA3
//
//  Created by David wu on 16/11/4.
//  Copyright © 2016 David wu. All rights reserved.
//

#include "Cart_Point.h"
#include <iostream>
#include <cmath>
using namespace std;
//default constructor
Cart_Point::Cart_Point()
{
    x = 0.0;
    y = 0.0;

}
//Constructor
Cart_Point::Cart_Point(double inputx, double inputy)
{
    x = inputx;
    y = inputy;
}
// Non member function to take the distance between two cart points
double cart_distance(Cart_Point p1, Cart_Point p2)
{
    double distance = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return distance;

}
// overloading  << operator

ostream& operator << (ostream& output, const Cart_Point p1)
{
    output << "(" << p1.x << "," << p1.y << ")";
    return output;
}
//overload the + operator
Cart_Point& operator+(Cart_Point p1, Cart_Vector v1)
{
    double x = p1.x + v1.x;
    double y = p1.y + v1.y;
    Cart_Point *p2 = new Cart_Point(x, y);
    return *p2;
}
// overload the - operator
Cart_Vector& operator-(Cart_Point p1, Cart_Point p2)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    Cart_Vector *p3 = new Cart_Vector(x, y);
    return *p3;

}

