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

//Child Class Triangle
class Triangle : public Shapes {
public:
	//Constructor for the Triangle class
	Triangle(double b, double h) : Shapes(b, h) {}

//Function to calculate the area for a Triangle
	void calculateArea() override {
		result = 0.5 * base * height;
	}

//Function to calculate the perimeter of a Triangle
	void calculatePerimeter() override {
//In the context of this problem, you'd need additional information to calculate the preimeter of a triangle
//Instead I have chosen to put out an error message. 
		cout << "Perimeter cannot be calculated without more information" << endl;
	}
};

//Child Class Circle
class Circle : public Shapes {
public:
	//Constructor for the circle class
	Circle(double radius) : Shapes(radius, 0.0) {}

//Function to calculate the area for a circle
	void calculateArea() override {
		result = 3.14159265359 * base; 
	}
};


int main()
{
	int choice;
	double data1, data2;

	do {
		cout << "*****************" << endl;
		cout << "Shapes Calculator" << endl << endl;
		cout << "*****************" << endl;
		cout << "1. Square" << endl;
		cout << "2. Rectangle" << endl;
		cout << "3. Triangle" << endl;
		cout << "4. Circle" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;
		
		Shapes* shape = nullptr;



	}
}


