#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num = 0 , rnd=0 ,iter = 0;
	char c = 0;
	srand(time(0)); 
	printf("in: ");
	if(scanf("%*d%c%d",&iter,&c,&num)==2)
	{
		rnd = rand()%num+1;
		printf("output: %c%d ->%d%d" ,c,num,rnd,iter);
	}
	else
	{
		rnd = rand()%num+1;
		printf("output: %c%d ->%d" ,c,num,iter);
	}
	system("PAUSE");
	return 1;
}
