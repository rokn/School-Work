#include<stdio.h>


struct dog
{
	int age;
	char name[20];
	char breed[20];
	
};


int main()
{
	struct dog myDog1;
	struct dog meDoge3;
	
	printf("input dog age: ");
	scanf("%d", &myDog1.age);
	
	printf("input doge breed: ");
	scanf("%s", meDoge3.breed);
	
	printf("input doge age: ");
	scanf("%d", &meDoge3.age);
	
	printf("Dog 1's age is %d\n", myDog1.age);
	printf("Doge's age is %d\n", meDoge3.age);
	
	return 0;
	
	
}

