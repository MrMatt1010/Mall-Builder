// Mall-Builder.cpp 

#include <iostream>
#include <cmath>
using namespace std;

//Parent Class
class Shapes {
protected:
	double base;
	double height;
	double result;


public:
// Constructor for the parent class
	Shapes(double b, double h) : base(b), height(h), result(0.0) {}

// Function to get input data
	void getData() {
		cout << "Enter base and height: ";
		cin >> base >> height;
	}


//Function to calculate the area (to be overridden by the child classes)
	virtual void calculateArea() {}

//Function to calculate the perimeter (to be overridden by the child classes)
	virtual void calculatePerimeter() {}

//Function to display the results
	void giveResult() {
		cout << "area: " << result << endl;
	}
};

//Child Class Square
class Square : public Shapes {
public:
//Constructor the the Square class
	Square(double side); Shapes(side, side) {}

//Function to calculate the area for the square
	void calculateArea() override {
		result = base * base;
	}

//Function to calculate the perimeter of the square
	void calculatePerimeter() {
		result = 4 * base;
	}
};

//Child Class Rectangle
class Rectangle : public Shapes {
public:
	//Constructor for the rectangle class
	Rectangle(double l, double w) : Shapes(l, w) {}

//Function to calculate the area for a Rectangle
	void calculateArea() override {
		result =  base + height;
	}

//Function to calculate the perimeter for the Rectangle
	void calculatePerimeter() override {
		result = 2 * base + height;
	}
};

int main()
{
   
}


