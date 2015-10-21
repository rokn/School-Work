#include <iostream>

using namespace std;

class Foo
{
	const int bar;
	
public:
	Foo(int new_bar)
	: bar(new_bar + 2)
	{
		//bar = new_bar;
	}
	
	int get_bar() const
	{
		return bar;
	}
};

int main()
{
	Foo f1(42);
	Foo f2(2);
	Foo f3(22);
	Foo f4(32);
	cout << f1.get_bar() << endl;
	cout << f2.get_bar() << endl;
	cout << f3.get_bar() << endl;
	cout << f4.get_bar() << endl;
	
	return 0;
	
}
