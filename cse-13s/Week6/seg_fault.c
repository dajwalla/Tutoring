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

void free_ll(node *ll){
	
	while(ll){
		
		free(ll);
		ll = ll->next;

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
