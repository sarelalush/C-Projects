#include <stdio.h>
#include <stdlib.h>

int main()
{
	int big_num=0,small_num=0,i=0 , num =0;
	while(scanf("%d",&num) == 1)
	{
		if(!i)
			big_num=small_num=num;
		if(num>big_num)
			big_num = num;
		if(num<small_num)
			small_num = num;
		i++;
	}
	printf("the biggest number is : %d and smallest number is :%d",big_num,small_num);
	system("PAUSE");
	return 1;
}
