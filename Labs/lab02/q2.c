#include <stdio.h>
#include <stdlib.h>

int main()
{
	float f = 0;
	printf("Enter a number between(-100,100):");
	while(scanf("%f",&f) == 1)
	{
		if(!(f> -100 && f < 100))
		{
			printf("only between (-100,100) try again please\n");
		}
		else
		{
			if(f<0)
			{
				printf("%07.3f\n",f);
			}
			else
			{
				printf("+%06.3f\n",f);
			}
		}
		printf("Enter a number between(-100,100):");
	}

	system("PAUSE");
	return 1;
}
