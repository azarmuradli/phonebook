#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifndef PHONEBOOK
#define PHONEBOOK

#define MAX_LENGTH 30

typedef struct PhoneBookEntry {
	char name[MAX_LENGTH+1];
	char phonenumber[MAX_LENGTH+1];
}PhoneBookEntry;
	
typedef struct PhoneBook {
	struct PhoneBookEntry* entries;
	int numEntries;
	int size;
}PhoneBook;

PhoneBook* init(int size);

void destroy(PhoneBook* pb);

bool insert(PhoneBook* pb, char* name,char* phonenumber);

char* get(PhoneBook* pb,char *name);

void print(PhoneBook* pb);

void dump(PhoneBook* pb, char *filename);

#endif
