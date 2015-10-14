#include <iostream>
#include <stack>
#define ARRAY_SIZE 100
using namespace std;

int main()
{
	stack<char> myStack;
	int i = 0;
	bool wrong = false;
	char ch[ARRAY_SIZE];
	cin >> ch;
	
	while(ch[i] != '\0')
	{
		if(ch[i] == '(')
		{
			myStack.push(ch[i]);
		}
		else if(ch[i] == ')')
		{
			if(!myStack.empty())
			{
				if(myStack.top() != ch[i])
				{
					wrong = true;
					break;
				}
				else
				{
					myStack.pop();
				}
			}
			else
			{
				wrong = true;
				break;
			}
		}
		
		i++;
	}
	
	if(!wrong)
	{
		cout << "GJ" << endl;
	}
	else
	{
		cout << "Wrong input of SKOBI" << endl;
	}	
	return 0;
	
}
