#include <stdio.h>

//q2
void no_dividers(int* s1, unsigned int n1, int* s2, unsigned int n2){
	int i = 0 , j = 0, flag = 0;
	for(i =0;i<n1;i++){
		flag = 1;
		for(j=0;j<n2;j++)
		{
			if(*(s1+i) % *(s2+j) == 0 )
			{
				flag = 0;
				break;
			}				
		}
		if(flag)
			printf("%d ",*(s1+i));
	}
	printf("\n");
}
//q1
void remove_char(char s[],char ch){
	int i = 0,j=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]==ch)
		{
			for (j=i;s[j]!='\0';j++)
			{
				s[j]=s[j+1];
			}
			i--;
		}
	}
}
int main(){
	int s1[] = {1, 10, 5, 4, 21, 49, 24}, s2[] = {2, 3};
	char str []="abracadabra";
	char ch = 'r';	
	
	remove_char(str,ch);//q1
	printf("%s\n",str);//q1
	no_dividers(s1,sizeof(s1)/sizeof(int),s2,sizeof(s2)/sizeof(int));//q2

	system("pause");
}
