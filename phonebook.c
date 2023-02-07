#include <stdio.h>
#include <stdlib.h>
#include "header.h"


	


int main() {
	
	
	PhoneBook* pb = init(10);
	

	
	bool insert_check = insert(pb,"Azar","715-968-3589");
	if(insert_check==false) {
		printf("Your phonebook is full! - can't enter new entry\n");
	}
	insert_check = insert(pb,"Leo","937-484-6483");
	if(insert_check==false) {
		printf("Your phonebook is full! - can't enter new entry\n");
	}
	insert_check = insert(pb,"Neymar","815-285-0355");
	if(insert_check==false) {
		printf("Your phonebook is full! - can't enter new entry\n");
	}
	insert_check = insert(pb,"Suarez","727-570-0699");
	if(insert_check==false) {
		printf("Your phonebook is full! - can't enter new entry\n");
	}
	insert_check = insert(pb,"Alvarez","503-870-0579");
	if(insert_check==false) {
		printf("Your phonebook is full! - can't enter new entry\n");
	}
	
	printf("Print all the entries: \n\n");
	print(pb);
	
	printf("\n\n");
	
	char *numberAzar = get(pb,"Azar");
	printf("Print Azar's phonenumber: \n");
	if(numberAzar==NULL) {
		printf("There is no entry for Azar");
	}
	else {
		printf("%s",numberAzar);
	}
	
	// write entries to text file
	dump(pb,"entries.txt");
	
	// deallocate memory
	destroy(pb);
	
	return 0;
}
