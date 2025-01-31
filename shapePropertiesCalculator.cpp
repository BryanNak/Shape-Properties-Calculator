#include <iostream>
#include <cmath>

/**
 * This program utilizes class hierarchy by defining an abstract Shape class and concrete classes pertaining to various shapes:
 * Circle, Sphere, Cylinder, Square, Cube, Triangle, and Tetrahedron. With this class hierarchy, different formulas for each
 * shape are used to display information about that particular shape.
 *
 * @author Bryan Nakasone
 * @assignment ICS 212 Assignment 24
 * @date December 5, 2023
 */

#define NUM 7
#define MY_PI 3.14

using namespace std;

class Shape {
	public:
		/** Returns the name of the class. */
		virtual const char* name() const = 0;
		/** Prints the area or surface area, and volume of the object. */
		virtual void printDetails() const = 0;
		/**
		 * Prompts the user to enter a radius, side, and/or height
		 * of the object and set the appropriate data member(s).
		 */
		virtual void inputData() = 0;
		/** Calculates and returns the area or surface area of the object. */
		virtual double area() const = 0;
		/** Calculates and returns the volume of the object. */
		virtual double volume() const {
			return 0.0;
		}     
};   

class Circle : public Shape {
	public:
		// Parameter syntax "datatype variable = value" will give
		// a default value for the variable if one is not supplied as an argument.
		// This constructor can be called with no arguments or one argument
		// Example: shapeArray[0] = new Circle(); 
		// Example: Circle circle1 = new Circle(10);
		Circle (double radiusParam = 1) {
			radius = radiusParam;
		}

		const char* name() const {
			return "Circle";
		}

		void printDetails() const {
			cout << "The " << name() << "'s area = " << area() << endl;
		} 

		void inputData() {
			cout << "Enter the " << name() << "'s radius: ";
			cin >> radius;
		}

		double area() const {
			return MY_PI * radius * radius;
		}

	protected:    
		double radius;
};


/** Add the remaining classes here. */

class Square: public Shape {

	public:
		Square(double sideParam = 1) {
			side = sideParam;
		}

		const char* name() const {
			return "Square";
		}

		void printDetails() const {
			cout << "The " << name() << "'s area = " << area() << endl;
		}

		void inputData() {
			cout << "Enter the Square's side: ";
			cin >> side;
		}

		double area() const {
			return side*side;
		}

	protected:
		double side;
};

class Triangle: public Shape {
	public:
		Triangle(double sideParam = 1) {
			side = sideParam;
		}

		const char* name() const {
			return "Triangle";
		}

		void printDetails() const {
			cout << "The " << name() << "'s area = " << area() << endl;
		}

		void inputData() {
			cout << "Enter the Triangle's side: ";
			cin >> side;
		}

		double area() const {
			return (side*side) * sqrt(3)/4;
		}

	protected:
		double side;

};

class Sphere: public Circle {
	public:
		Sphere(double radiusParam = 1) {
			radius = radiusParam;
		}
		const char* name() const {
			return "Sphere";
		}

		void printDetails() const{
			cout << "The " << name() << "'s surface area = " << area() << endl;
			cout << "The " << name() << "'s volume = " << volume() << endl;
		}

		void inputData() {
			cout << "Enter the Sphere's radius: ";
			cin >> radius;
		}

		double area() const {
			return 4 * MY_PI * (radius * radius);
		}

		double volume() const {
			return (4*MY_PI*(radius*radius*radius) / 3);
		}
};

class Cylinder: public Circle {
	public:
		Cylinder(double radiusParam = 1, double heightParam = 1) {
			radius = radiusParam;
			height = heightParam;
		}

		const char* name() const {
			return "Cylinder";
		}

		void printDetails() const {
			cout << "The " << name() << "'s surface area = " << area() << endl;
			cout << "The " << name() << "'s volume = " << volume() << endl;
		}

		void inputData() {
			cout << "Enter the " << name() << "'s radius: ";
			cin >> radius;
			cout << "Enter the " << name() << "'s height: ";
			cin >> height;
		}

		double area() const {
			return (2 * MY_PI * radius * height) + 2*MY_PI*(radius*radius);
		}

		double volume() const {
			return MY_PI * (radius*radius) * height;
		}

	private:
		double height;
};

class Cube: public Square {
	public:
		Cube(double sideParam = 1) {
			side = sideParam;
		}

		const char* name() const {
			return "Cube";
		}

		void printDetails() const {
			cout << "The " << name() << "'s surface area = " << area() << endl;
			cout << "The " << name() << "'s volume = " << volume() << endl;
		}

		void inputData() {
			cout << "Enter the " << name() << "'s side: ";
			cin >> side;
		}

		double area() const {
			return 6*(side*side);
		}

		double volume() const {
			return side*side*side;
		}
};

class Tetrahedron: public Triangle {
	public:
		Tetrahedron(double sideParam = 1) {
			side = sideParam;
		}

		const char* name() const {
			return "Tetrahedron";
		}

		void printDetails() const {
			cout << "The " << name() << "'s surface area = " << area() << endl;
			cout << "The " << name() << "'s volume = " << volume() << endl;
		}

		void inputData() {
			cout << "Enter the " << name() << "'s side: ";
			cin >> side;
		}

		double area() const {
			return (side * side) * sqrt(3);
		}

		double volume() const {
			return (side * side * side) * sqrt(2)/12;
		}
};

int displayMenu(Shape *[]);

int main() {

	Shape *shapeArray[NUM];
	shapeArray[0] = new Circle();

	// Uncomment the line below when you have completed its corresponding classs for that shape.
	// The shape will be added to the array and the corresponding menu option will be shown.
	shapeArray[1] = new Sphere();
	shapeArray[2] = new Cylinder();
	shapeArray[3] = new Square();
	shapeArray[4] = new Cube();
	shapeArray[5] = new Triangle();
	shapeArray[6] = new Tetrahedron();

	int choice = displayMenu(shapeArray);
	while (choice >= 0 && choice <= 6) {
		shapeArray[choice]->inputData();
		shapeArray[choice]->printDetails();
		cout << endl;
		choice = displayMenu(shapeArray);
		}
		return 0;
}

/**
 * Displays the menu for which shape to perform calculations.
 *
 * @param shapeArrayParam array of shapes that this program supports
 * @return the choice from the user
 */
int displayMenu(Shape *shapeArrayParam[]) {
	int choice = 0;
	cout << "Select an object from the menu (enter 7 to quit)." << endl;
	for (int i = 0; i < NUM; i++) {
		cout << '\t' << i << ". " << shapeArrayParam[i]->name() << endl;
	}
	cin >> choice;
	return choice;
}