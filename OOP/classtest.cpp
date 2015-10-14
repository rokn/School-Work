#include<stdio.h>

class dog
{

	int age;
	char* name;
	char* breed;
	
public:
	
	dog(char* dName)
	{
		//printf("A dog has been created\n");
		name = dName;
		
	}
	
	char* getName()
	{
		return name;
	}
};

int main()
{
	dog myDog1("dogfe");
	dog meDoge3("koch");
	
	printf("The dog's name is %s\n", meDoge3.getName());
	
	/*printf("input dog age: ");
	scanf("%d", &myDog1.age);
	
	printf("input doge breed: ");
	scanf("%s", meDoge3.breed);
	
	printf("input doge age: ");
	scanf("%d", &meDoge3.age);
	dog meDoge4;
	printf("Dog 1's age is %d\n", myDog1.age);
	printf("Doge's age is %d\n", meDoge3.age);*/
	
	return 0;
	
	
}

