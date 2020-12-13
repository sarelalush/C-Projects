/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MIN 0

int main(){
	int n = 0, i = 0 , even = 0 , odd = 0 , rnd_number = 0;
	printf("Please Enter a Number :");
	scanf("%d",&n);//scanf number
	if (!(n>MIN && n < MAX)) //check if the number between 1 - 100
	{
		printf("Your number not in the range...");
		return 0;
	}
	for (MIN=0;i<n;i++) // run n times
	{
		rnd_number = rand(); // get random
		if(rnd_number % 2 == 0) //check for even to odd
		{
			even++; //inc evev
		}
		else
		{
			odd++; // inc odd
		}
	}
	printf("the numbers of even numbers is %d , and numbers of odd numbers is %d",even,odd);//print ....
	system("pause");
	return 0;
}

