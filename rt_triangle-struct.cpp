#include <iostream>
#include <math.h>
using std::cout;
using std::endl;

struct triangle {
	float side1;
	float side2;
	float side3;
	float angle1;
	float angle2;
	float angle3 = 90.;
};
	
int hypot(triangle &meow);
int angle_1(triangle &meow);
int angle_2(triangle &meow);
int triangle_operation(triangle &meow, int i);

int main() {
	triangle cat1;
	cat1.side1 = 3.;
	cat1.side2 = 4.;
	triangle_operation(cat1,1);	
	
	triangle cat2;
	cat2.side1 = 5.;
	cat2.side2 = 12.;
	triangle_operation(cat2,2);	
	
	return 0;
}

int hypot(triangle &meow) {
	meow.side3 = sqrt(pow(meow.side1,2)+pow(meow.side2,2));
	return 0;
}

int angle_1(triangle &meow) {
	meow.angle1 = asin(meow.side1/meow.side3)*180./M_PI;
	return 0;
}


int angle_2(triangle &meow) {
	meow.angle2 = asin(meow.side2/meow.side3)*180./M_PI;
	return 0;
}
	
int triangle_operation(triangle &meow, int i) {
	hypot(meow);	
	angle_1(meow);
	angle_2(meow);
	cout << "Triangle " << i << endl;
	cout << "Lengths of each side are " << meow.side1 << ", " << meow.side2 << ", " << meow.side3 << endl;
	cout << "The angles are " << meow.angle1 << ", " << meow.angle2 << ", " << meow.angle3 << endl << endl;
}
