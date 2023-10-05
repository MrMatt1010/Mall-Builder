// Mall-Builder.cpp 

#include <iostream>
#include <cmath>
using namespace std;

//Parent Class
class shapes {
protected:
	double base;
	double height;
	double result;


public:
// Constructor for the parent class
	shapes(double b, double h) : base(b), height(h), result(0.0) {}

// Function to get input data
	void getData() {
		cout << "Enter base and height: ";
		cin >> base >> height;
	}


//Function to calculate the area (to be overridden by the child classes)
	virtual void calculateArea() {}

//Function to calculate the preimeter (to be overridden by the child classes)
	virtual void calculatePerimeter() {}

//Function to display the results
	void giveResult() {
		cout << "area: " << result << endl;
	}
};



int main()
{
   
}


