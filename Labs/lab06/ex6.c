#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void half_print(const char * filename){
	FILE * file =fopen(filename,"r");
	char *line = NULL;
	size_t len = 0;
	int i = 0;

	
	if(!file)
		printf("Error ");
		return ;
	
	while ((getline(&line, &len, file)) != EOF) {
    for(i =0;i<strlen(line)/2;i++)
       printf("%c",line[i]);
    printf("\n");
	}
 fclose(file);
 free(line);
}

char * longest_line(const char * filename){
	FILE * file =fopen(filename,"r");
	char *line = NULL;
	size_t len = 0;
	char *big = 0;
	int i = 0;
  int size_big = 0;
	
	if(!file)
		printf("Error ");
		return ;
	
	while ((getline(&line, &len, file)) != EOF) {
        if(strlen(line) > size_big){
          size_big = strlen(line);
          free(big);
          big = strdup(line);
        }
    
	}
  fclose(file);
  free(line);
  return big;

}


int main(int argc, char *argv[]){
  half_print(argv[1]);
  char *big = longest_line(argv[1]); 
  printf("%s",big);
  free(big);
  
}
