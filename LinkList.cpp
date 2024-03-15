#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node{
	Node *next;
	Node *prev;
	char name[15];
	char num[100];
	
	Node(){
		next = NULL;
		prev = NULL;
		strcpy(name, "");
		strcpy(num, "");
	}
	
	Node(char *NewName, char *NewNum){
		next = NULL;
		prev = NULL;
		strcpy(name, NewName);
		strcpy(num, NewNum);
	}
};

struct LinkList{
	Node *head;
	
	LinkList(){
		head = NULL;
	}
	
	void insert(char *name, char*num){
		if(head == NULL){
			head = new Node(name, num);
			return;
		}
		
		Node *curNode = head;
		while(curNode->next != NULL){
			curNode = curNode->next;
		}
		curNode->next = new Node(name, num);
		curNode->next->prev = curNode;
		return;
	}
	
	void remove(char *name){
		if(head == NULL){
			printf("array is emty\n");
			return;
		}
		
		Node *curNode = head;
		if(strcmp(curNode  -> name, name) == 0){
			Node *tempNode = head;
			if(tempNode -> next == NULL){
				head = NULL;
				delete(tempNode);
				return;
			}
			
			head = tempNode->next;
			head->prev = NULL;
			delete(tempNode);
			return;
		}
		while(curNode -> next != NULL && strcmp(curNode -> next -> name, name) != 0 ){
			curNode = curNode->next;
		}
		
		if(curNode -> next == NULL){
			printf("Name not found\n");
		}else{
			Node *tempNode = curNode->next;
			curNode->next = tempNode->next;
			tempNode->next->prev = tempNode->prev;
			delete(tempNode);
		}
	}
	
	void debug(){
		if(head == NULL){
			printf("array is empty\n");
			return;
		}
		
		Node *curNode = head;
		while(curNode ->next != NULL){
			printf("%s, %s\n", curNode->name, curNode->num);
			curNode = curNode ->next;
		}
		printf("%s, %s\n", curNode->name, curNode->num);	
	}
};



void insertContact(LinkList &list) {
    char name[20], number[20];
    int isValidNumber;

    printf("Enter Name (3-15 characters): ");
    scanf("%19s", name);

    while(strlen(name) < 3 || strlen(name) > 15) {
        printf("Name must be between 3-15 characters.\n");
        printf("Enter Name: ");
        scanf("%19s", name);
    }

    do {
        isValidNumber = 1;
        printf("Enter Phone Number (digits only): ");
        scanf("%19s", number);

        for (int i = 0; number[i] != '\0'; i++) {
            if (number[i] < '0' || number[i] > '9') {
                isValidNumber = 0;
                printf("Invalid input. Phone number must consist of digits 0-9.\n");
                break; // Exit for-loop
            }
        }
    } while (!isValidNumber);

    list.insert(name, number);
}


void deleteContact(LinkList &list) {
    char name[20];
    printf("Enter the name of the contact to delete: ");
    scanf("%19s", name);
    list.remove(name);
}


void displayContacts(LinkList &list) {
    list.debug();
}


int main() {
    LinkList list;
    int choice;

    do {
        printf("\nContact Management System:\n");
        printf("1. Insert new contact\n");
        printf("2. Delete existing contact\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        while (getchar() != '\n'); 

        system("cls");

        switch (choice) {
            case 1:
                insertContact(list);
                break;
            case 2:
                deleteContact(list);
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice, please enter 1, 2, or 3.\n");
        }

        system("pause"); 
        system("cls"); 
        displayContacts(list); 
    } while (choice != 3);

    return 0;
}















