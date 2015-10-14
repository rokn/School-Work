#include <iostream>
#define ARRAY_SIZE 100
using namespace std;

int main()
{
	int count = 0;
	int i = 0;
	char ch[ARRAY_SIZE];
	cin >> ch;
	
	while(ch[i] != '\0')
	{
		if(ch[i] == '(')
		{
			count++;
		}
		else if(ch[i] == ')')
		{
			count--;
		}
		if (count < 0)
		{
			
			break;
		}
		i++;
	}
	
	if(count == 0)
	{
		cout << "GJ   " << count << endl;
	}
	else
	{
		cout << "Wrong input of SKOBI" << endl;
	}	
	return 0;
	
}
