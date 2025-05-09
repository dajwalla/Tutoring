#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char *data;
	struct node *next;
} node;


node *new_node(char *data){
	node *out = calloc(1, sizeof(node));
	out->data = strdup(data);
	out->next = NULL;
	return out;
}


node *add_node(char *data, node *in){
	node *new = new_node(data);
	new->next = in;
	return new;
	
}

//Changed from trying to free linked list iteratively to recursively
//freeing both the data and the node itself
//This is to illustrate Valgrind output and how we can use it 
//to pinpoint where we are creating a seg_fault or leaking memory
void free_ll(node *ll){

	if(ll){
		free(ll->data);
		free_ll(ll->next);
		free(ll);

	}
}

int main(void){

	int i = 10;

	int *p = &i;

	node *ll;
	ll = new_node("Hello");
	ll = add_node("There", ll);
	ll = add_node("There", ll);

	free_ll(ll);
	
	return 0;
}
