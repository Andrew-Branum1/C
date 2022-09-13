#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct Node {
	char *firstName;
	char *lastName;
	int empId;
	int age;
	int lucky;
	struct Node *next;
	struct Node *prev;
	};
	
struct List {
	struct Node *head;
	struct Node *tail;
	};

struct Node *create_node(int age, int lucky, int empId, char *firstName, char *lastName) {
	struct Node *node = malloc(sizeof(struct Node));
	if (node == NULL) {
		fprintf (stderr, "%s: Couldn't create memory for the 		node; %s\n", "linkedlist", strerror(errno));
    		exit(-1);
		}
		node->firstName = strdup(firstName);
		node->lastName = strdup(lastName);
		node->empId = empId;
		node->age = age;
		node->lucky = lucky;
		node->next = NULL;
		node->prev = NULL;
		return node;
		}
struct List *create_list() {
  struct List *list = malloc(sizeof(struct List));
  if (list == NULL) {
    fprintf (stderr, "%s: Couldn't create memory for the list; %s\n", "linkedlist", strerror (errno));
    exit(-1);
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void insert(struct Node *node, struct List *list){

	struct Node *ptr = malloc(sizeof(struct Node));
	
	if(list->head==NULL 
	|| (list->head->age < node->age)
	|| (list->head->age == node->age && list->head->lucky > node->lucky) //1-Lucky > 2-Lucky 
	|| (list->head->age == node->age && list->head->lucky == node->lucky && list->head->empId < node->empId)){ //1-ID < 2-ID
	
		node->next = list->head;
		list->head = node;
		//free(ptr);
		
		}	
	else{
		ptr = list->head;
	while((ptr->next != NULL && ptr->next->age > node->age) 
	|| (ptr->next != NULL && ptr->next->age >= node->age && ptr->next->lucky < node->lucky)
	|| (ptr->next != NULL && ptr->next->age >= node->age && ptr->next->lucky <= node->lucky && ptr->next->empId > node->empId) 
	){
		ptr = ptr->next;
	}
		node->next = ptr->next;
		ptr->next = node;
		//free(ptr);
	}
	//free(ptr);
	}
	
void print_list(struct List *list, FILE *outfile) {
  struct Node *ptr = list->head; 
   
  while (ptr != NULL) {
    fprintf(outfile, "%d,%d,%d,%s,%s\n", ptr->age, ptr->lucky, ptr->empId, ptr->firstName, ptr->lastName);
    ptr = ptr->next;
  }
}

void destroy_list(struct List *list) {
  struct Node *ptr = list->head;
  struct Node *tmp;  
  while (ptr != NULL) {
    free(ptr->firstName);
    free(ptr->lastName);
    tmp = ptr;
    ptr = ptr->next;
    free(tmp);
  }
  free(list);
}

int main(int argc, char *argv[]) {

	FILE *ptr = fopen(argv[1], "r");
	FILE *outfile;
  	outfile = fopen(argv[2], "w");
  	printf("Printing to %s\n", argv[2]);
    	
	if (ptr == NULL) {
		fprintf(stderr, "%s: Couldn't open the file %s\n", argv[1], strerror(errno));
        	exit(-1);
		}	
	int age, id, num;
	char *first, *last = NULL;
	
	//initialize strings and intergers and reolace test with them
	
	struct List *list = create_list();
  	struct Node *tmp = NULL;
  	
	while(fscanf(ptr, "%d %ms %ms %d %d\n", &id,&first,&last,&age,&num) != EOF){
	//printf("%d,%s,%s,%d,%d\n", id, first, last, age, num);
	tmp = create_node(age, num, id, first, last);
	insert(tmp, list);
	free(first);
	free(last);
	}
	print_list(list, outfile);
	fclose(ptr);
    	fclose(outfile);
	destroy_list(list);
	return 0;
}
