#include <stdio.h>

void increment(int *ptr){
	*ptr+=1;
}

int main(){
	int num = 5;
	increment(&num);
	printf("%d",num);

}
