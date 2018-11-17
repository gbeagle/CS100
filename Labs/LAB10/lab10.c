#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct person {
	char *name;
	int age;
	struct person *next;
} Person;

void print(Person *);			// prints the entire list
Person *addFront(Person *, char *, int);// adds a new node to the front of the list
Person *addRear(Person *, char *, int);	// adds a new node to the end of the list
void printLegal(Person *);		// prints the names who are 21 or older
int getAge(Person *, char *);		// returns age of the name specified (or -1)

int main(void) {
	char input1[100];
	int input2;
	Person *myList = NULL;
	printf("Enter a person's name (one word) and age : ");
	scanf("%s %d", input1, &input2);
	while (input2 != 0) {
		if (input2 > 20)
			myList = addRear(myList, input1, input2);
		else
			myList = addFront(myList, input1, input2);
		printf("Enter a name (one word) and age, enter 'xxx' and 0 to exit : ");
		scanf("%s %d", input1, &input2);
	}
	printf("\n\n");  print(myList);
	printf("\n\n");  printLegal(myList);
	printf("\n\nEnter the name of a person to look up their age : ");
	scanf("%s", input1);
	while ( strcmp(input1, "xxx") != 0 ) {
		printf("\t%s is %d years old\n", input1, getAge(myList, input1) );
		printf("Enter a name to look up their age or 'xxx' to exit : ");
		scanf("%s", input1);
	}
	return 0;
}
void print(Person *ptr) {
	printf("The list is : ");
	while (ptr) { printf("[%s-%d] ", ptr->name, ptr->age); ptr = ptr->next; }
	printf("\n");
	return;
}
Person *addFront(Person *ptr, char *n, int a) {
	Person *newNode = malloc( sizeof(Person) );
	newNode->name = malloc( strlen(n) + 1 );
	strcpy(newNode->name, n);
	newNode->age = a;
	newNode->next = ptr;
	return newNode;
}
Person *addRear(Person *ptr, char *n, int a) {
	Person *newNode = malloc( sizeof(Person) );
	newNode->name = malloc( strlen(n) + 1);
	strcpy(newNode->name, n);
	newNode->age = a;
	newNode->next = NULL;
	if (ptr == NULL){
		return newNode;
	}
	Person *temp = ptr;
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	return ptr;  
}
void printLegal(Person *ptr) {
	printf("Legal: ");
	while (ptr) { 
		if(ptr->age >= 21){
			printf("[%s-%d] ", ptr->name, ptr->age);
		}
		ptr = ptr->next; 
		}
	printf("\n");
	return;
}

int getAge(Person *ptr, char *search){
	while(ptr){
		if(strcmp(ptr->name, search) == 0){
			return (ptr->age);
		}
		ptr = ptr->next;
	}
	return -1;
}
