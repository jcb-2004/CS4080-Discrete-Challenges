#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char *value;
	struct Node *previous;
	struct Node *next;
} Node;

/*Insert at head*/
Node *insert(Node *head, const char *value){
	Node *n = malloc(sizeof(Node));
	n->value = strdup(value);
	n->previous = NULL;
	n->next = head;
	if(head){
		head->previous = n;
	}
	return n;
}

/*Find item*/
Node *find(Node *head, const char *value){
	for (Node *currentItem = head; currentItem; currentItem = currentItem->next){
		if(strcmp(currentItem->value, value) == 0){
			return currentItem;
		}
	}
	return NULL;
}

/*Delete item*/
Node *del(Node *head, Node *n){
	if (!n){
		return head;
	}
	if(n->previous){
		n->previous->next = n->next;
	} else{
		head = n->next;
	}
	if(n->next){
		n->next->previous = n->previous;
	}
	free(n->value);
	free(n);
	return(head);
}

/*Clean up list*/
void cleanup(Node *head){
	while(head){
		Node *next = head->next;
		free(head->value);
		free(head);
		head = next;
	}
}

/*Print list*/
void printList(Node* head){
	printf("List: ");
	for(Node *currentItem = head; currentItem; currentItem = currentItem->next){
		printf("%s ", currentItem->value);
	}
	printf("\n");
}

void main(void){
	Node *head = NULL;
	head = insert(head, "one");
	head = insert(head, "two");
	head = insert(head, "three");
	printf("Created doubly linked list\n");
	printList(head);
	printf("Inserting item 'four'...\n");
	head = insert(head, "four");
	printList(head);
	printf("Finding item 'two'...\n");
	Node *search = find(head, "two");
	printf("What was found: %s\n", search->value);
	printf("Deleting item 'two'...\n");
	head = del(head, search);
	printList(head);
	cleanup(head);
}
