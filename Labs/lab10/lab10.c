#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool check_bit(unsigned int n, unsigned int index){
	return 1&(n>>index-1);
}

int even_bits(unsigned int n){
  int sum_even = 0;
  int i =0;
  for (i=0;i<32;i+=2){
    if(check_bit(n,i))
      sum_even++;
  }
  return sum_even;
}

unsigned int flip_even_bits(unsigned int n)//
{
  int i =0;
  for(i =0;i<32;i+=2)
    n^=(1<<i);
  return n; 
}
//Q4
unsigned int turn_on_high_bits(unsigned int n, unsigned int index)
{
  int tmp_n = -1;
  tmp_n|=1;
  tmp_n<<=index;
  return n|tmp_n;
}
//Q5
unsigned int reverse_bits(unsigned int n)
{
  int tmp_num = n;
  int new_num =0;
  int i = 0;
  for(i =31;i>=0;i--)
  {
    tmp_num>>=i;
    new_num|=(tmp_num<<(31-i));
    tmp_num = n;
  } 
  return new_num;
}
//Q6
bool get_bit(unsigned char *arr, unsigned int index)
{
  int i = index / 8;
  return ((*(arr+i))>>((index%8)))& 1;
}
//Q7
unsigned int create_largest(unsigned int n)
{
  int sum = 0;
  int i =0;
  int new_num =0;
  for (i=0;i<32;i++){
    if(check_bit(n,i))
      sum++;
  }
  if(sum == 32)
    return 0;
  for(i=0;i<sum;i++){
    new_num |= 1<<(31-i);
  }
  return new_num;
}

int main(){
	printf("%d\n",check_bit(100,3));
  printf("%d\n",even_bits(10));
  printf("%x\n",flip_even_bits(0));
  printf("%x\n",turn_on_high_bits(4,2));
  printf("%x\n",reverse_bits(3));
  printf("%x\n",get_bit("A",0));
  printf("%x\n",create_largest(0xffffff0f));
}

