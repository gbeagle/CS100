#include "contact.h" 
/////////////////////////////////////////////////////////////////////////////////////////////
Contact* addContact(Contact *myContacts, char *contactName) {
	Contact *newContact = malloc( sizeof(Contact) );
	newContact->name = malloc(strlen(contactName) +1);
	strcpy(newContact->name, contactName);
	newContact->information = NULL;
	if(myContacts == NULL){
		return newContact;
	}

	Contact *startNode = myContacts;
	while(myContacts){
		if(strcmp(myContacts->name, contactName) == 0){
			printf("ERROR: Contact already exists\n");
			free(newContact);
			return startNode;
		}
		myContacts = myContacts->next;
	}
	newContact->next = startNode;
	return newContact;
}


/////////////////////////////////////////////////////////////////////////////////////////////
void addInformation(Contact *myContacts, char *contactName, char *infoName, char *infoValue) {
	Info *newterm = malloc( sizeof(Info) );
	newterm->name = malloc(strlen(infoName) + 1 );
	strcpy(newterm->name, infoName);
	newterm->value = malloc(strlen(infoValue) + 1 );
	strcpy(newterm->value, infoValue);
	newterm->next = NULL;

	if(myContacts == NULL){
		printf("ERROR: Contact not found\n");
		return;
	}

	while(myContacts){
		if(strcmp(myContacts->name, contactName) == 0){
			if(myContacts->information == NULL){
				myContacts->information = newterm;
				return;
			}

			else{
				Info *head = myContacts->information;
				while(head){
					if(strcmp(head->name, infoName) == 0){
						free(head->value);
						head->value = malloc( strlen(infoValue) + 1);
						strcpy(head->value, infoValue);
						return;
					}

					if(head->next == NULL){
						head->next = newterm;
						return;
					}
					head = head->next;
				}

			}
		}
		myContacts = myContacts->next;
	}
	printf("ERROR: Contact not found\n");
	free(newterm);
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
void printContact(Contact *myContacts, char *contactName) {
	while(myContacts){
		if(strcmp(myContacts->name, contactName) == 0){
			printf("%s\n", myContacts->name);
			Info *information = myContacts->information;
			while(information){
				printf("\t<%s|%s>\n", information->name, information->value);
				information = information->next;
			}
			return;
		}
		myContacts = myContacts->next;
	}
	printf("ERROR: Contact not found\n");
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
int count(Contact *myContacts){
	if(myContacts == NULL){
		return 0;
	}
	int count = 0;
	while(myContacts){
		count = count + 1;
		myContacts = myContacts->next;
	}
	return count;
}


/////////////////////////////////////////////////////////////////////////////////////////////
void print(Contact *myContacts) {
	if(myContacts == NULL){
		return;
	}
	while(myContacts){
		printf("%s\n", myContacts->name);
		Info *information = myContacts->information;
		while(information){
			printf("\t<%s|%s>\n", information->name, information->value);
			information = information->next;
		}
		myContacts = myContacts->next;
	}
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
Contact *addContactOrdered(Contact *myContacts, char *contactName) {

	Contact *newContact = malloc( sizeof(Contact) );
	newContact->name = malloc( strlen(contactName) + 1 );
	strcpy(newContact->name, contactName);
	newContact->information = NULL;
	newContact->next = NULL;

	if (myContacts == NULL){
		return newContact;
	}

	if (strcmp(contactName, myContacts->name) < 0){ 
		newContact->next = myContacts; 
		return newContact; 
	}

	Contact *prev = myContacts;
	Contact *curr = myContacts->next;
	while(curr && (strcmp(curr->name, contactName) < 0) ){ 
		if(curr->next == NULL){
			curr->next = newContact;
			return myContacts;
		}
		prev = curr;
		curr = curr->next;
		if(strcmp(curr->name, contactName) == 0){
			printf("ERROR: Contact already exists\n");
			return myContacts;
		}	
	}
	prev->next = newContact;
	newContact->next = curr;
	return myContacts;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////
void addInformationOrdered(Contact *myContacts, char *contactName, char *infoName, char *infoValue) {
	Info *newInfo = malloc( sizeof(Info) );
	newInfo->name = malloc( strlen(infoName) + 1 );
	strcpy(newInfo->name, infoName);
	newInfo->value = malloc( strlen(infoValue) + 1);
	strcpy(newInfo->value, infoValue);
	newInfo->next = NULL;

	if (myContacts == NULL){
		printf("ERROR: Contact not found\n");
	}

	while(myContacts){
		if(strcmp(contactName, myContacts->name) == 0){
			Info *infohead = myContacts->information;
			if(infohead == NULL){
				myContacts->information = newInfo;
				return;
			}
			if (strcmp(infoName, infohead->name) < 0){
				newInfo->next = infohead;
				printf("\n");
				return;
			}

			Info *prev = infohead;
			Info *curr = infohead->next;
			while(curr && (strcmp(curr->name, infoName) < 0) ){
				if(curr->next == NULL){
					curr->next = newInfo;
					return;
				}
				prev = curr;
				curr = curr->next;
				if(strcmp(curr->name, infoName) == 0){
					free(curr->value);
					curr->value = malloc( strlen(infoValue) + 1);
					strcpy(curr->value, infoValue);
					return;
				}
			}
			prev->next = newInfo;
			newInfo->next = curr;
			return;
		}
		myContacts = myContacts->next;
	}
	printf("ERROR: Contact not found");
	return;
}


/////////////////////////////////////////////////////////////////////////////////////////////
void removeInformation(Contact *myContacts, char *contactName, char *infoName) {
	if(myContacts == NULL){
		printf("ERROR: Contact not found\n");
		return;
	}

	while(myContacts){
		if(strcmp(myContacts->name, contactName) == 0){
			Info *head = myContacts->information;
			if(head == NULL){
				printf("\n");
				return;
			}
			if(strcmp(head->name, infoName) == 0){
				Info *temp = head->next;
				free(head);
				myContacts->information = temp;
				return;
			}

			Info *prev = head;
			Info *curr = head->next;
			while( curr && (strcmp(curr->name, infoName) != 0) ){
				if( curr->next == NULL){
					printf("ERROR: Item not found\n");
					return;
				}
				prev = curr;
				curr = curr->next;
			}

			prev->next = curr->next;
			free(curr);
			myContacts->information = head;
			return;
		}
		myContacts = myContacts->next;
	}
	printf("ERROR: Contact does not exist\n\n\n");
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////
Contact *removeContact(Contact *myContacts, char *contactName) {
	if(myContacts == NULL){
		printf("ERROR: Contact not found\n");
		return myContacts;
	}

	if (strcmp(myContacts->name, contactName) == 0) {
		Contact *temp = myContacts->next;
		free (myContacts);
		printf("\n\n\n");
		return temp;
	}

	Contact *head = myContacts;
	Contact *prev = myContacts;
	Contact *curr = myContacts->next;
	while ( curr && (strcmp(curr->name, contactName) != 0) ) {
		if ( curr->next == NULL ){ 
			printf("ERROR: Contact does not exist\n");	
			return head;
		}
		prev = curr;
		curr = curr->next;
	}	
	// remove the item by pointing the previous item to the removed item's next field
	prev->next = curr->next;
	free(curr->information);
	free(curr);
	return head;
}
