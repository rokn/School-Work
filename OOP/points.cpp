#include <iostream>
#include <stdio.h>


class point
{
	float x;
	float y;
	
public:
	point(float c, float d)
	{
		x = c;
		y = d;
	}
	
	float getx()
	{
		return x;
	}
	
	float gety()
	{
		return y;
	}	

};

int main()
{

	point Point1(5.0f, 8.0f);
	
	printf("Point 1 is %f\n", Point1.getx());
	printf("Point 2 is %f\n", Point1.gety());
	
	return 0;
	

}
