#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_pal(char *s){

	char *in = strdup(s);

	char *se = (in + (strlen(in) - 1));

	char[strlen(in)];

	for(int i = 0; i < (int)((strlen(s) / 2) + 1); i++){
		if(*(s + i) != *(se - i)){
			
			free(in);

			return false;
		}
	}

	free(in);

	return true;
}

int main(void){

	char *s = "race car";

	//[]<- ...[][][][][]...->[]
	
	if(is_pal(s)){

		printf("this is a palindrome\n");
	} else {

		printf("not a palindrome\n");
	}	

}
