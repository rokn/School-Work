#include <iostream>

using namespace std;

class Point {
	double x, y;
public:
	Point()
	{
		x = 0.0;
		y = 0.0;
	}
	
	double get_x() const 
	{
		return x;
	}
	
	double get_y() const 
	{
		return y;
	}
	
	void set_x(double new_x) 
	{
		x = new_x;
	}
	
	void print() const
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}

};	

int main()
{

	const double pi = 3.14;
	// pi  =22.0/7;
	cout << "pi = " << pi << endl;
	
	const Point origin;
	origin.print();
	origin.get_x();
	
	return 0;
	
}

