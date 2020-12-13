#include <stdio.h>

#define N 26

char my_toupper(char ch)
{
	if(ch>=97&&ch<=122)
	{
		ch -= 32;
	}
	return ch;
}

int main()
{
	int arr [N] = {0}, i = 0; 
	char c = 10;
	printf("enter text :");
	while((c = getchar())!=10)
	{
		c = my_toupper(c);
		if(c>=65&&c<=90)
			arr[c%65] +=1;
	}
	for(i =0;i<N;i++)
	{
		printf("%c\t",65+i);
		printf("%d\n",arr[i]);
	}
	system("pause");
}
