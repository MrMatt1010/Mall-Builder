// Mall-Builder.cpp 
#define _USE_MATH_DEFINES
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

	// Draw the shape using asterisks
	virtual void draw() {
		std::cout << "Drawing the shape..." << std::endl;
	}
};

//Child Class Square
class Square : public Shapes {
public:
//Constructor the the Square class
	Square(double side) : Shapes(side, side) {}

//Function to calculate the area for the square
	void calculateArea() override {
		result = base * base;
	}

//Function to calculate the perimeter of the square
	void calculatePerimeter() {
		result = 4 * base;
	}


	// Draw the square using asterisks
	void draw() override {
		std::cout << "Drawing a square:" << std::endl;
		for (int i = 0; i < base; i++) {
			for (int j = 0; j < base; j++) {
				std::cout << "* ";
			}
			std::cout << std::endl;
		}
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


	// Draw the rectangle using asterisks
	void draw() override {
		std::cout << "Drawing a rectangle:" << std::endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < base; j++) {
				std::cout << "* ";
			}
			std::cout << std::endl;
		}
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


	// Draw the triangle using asterisks
	void draw() override {
		std::cout << "Drawing a triangle:" << std::endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j <= i; j++) {
				std::cout << "* ";
			}
			std::cout << std::endl;
		}
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


	// Draw the circle using asterisks
	void draw() override {
		std::cout << "Drawing a circle (approximated):" << std::endl;
		int radius = static_cast<int>(base);
		int centerX = radius;
		int centerY = radius;

		for (int i = 0; i <= 2 * radius; i++) {
			for (int j = 0; j <= 2 * radius; j++) {
				int dx = i - centerX;
				int dy = j - centerY;
				if (dx * dx + dy * dy <= radius * radius) {
					std::cout << "* ";
				}
				else {
					std::cout << "  ";
				}
			}
			std::cout << std::endl;
		}
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
		cout << "5. Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;
		
		Shapes* shape = nullptr;

		switch (choice) {
		case 1:
			cout << "Enter the side length of the square: ";
			cin >> data1;
			shape = new Square(data1);
			break;
		case 2:
			cout << "Enter the length and width of the rectangle: ";
			cin >> data1 >> data2;
			shape = new Rectangle(data1, data2);
			break;
		case 3:
			cout << "Enter the base and height of the triangle: ";
			cin >> data1 >> data2;
			shape = new Triangle(data1, data2);
			break;
		case 4:
			cout << "Enter the radius of the circle: ";
			cin >> data1;
			shape = new Circle(data1);
			break;
		case 5:
			cout << "Goodbye!" << endl;
		default:
			cout << "Invalid choice, Please try again." << endl;
			break;
		}

		if (shape) {
			shape->calculateArea();
			shape->calculatePerimeter();
			shape->giveResult();
			shape->draw(); // This will display the shape in the console
			delete shape;
	}
	} while (choice != 5);

	return 0;
}


