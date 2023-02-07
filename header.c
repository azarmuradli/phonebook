#include "header.h"

PhoneBook* init(int size) {
	PhoneBook* pb = malloc(sizeof(PhoneBook));
	if (pb == NULL) return NULL;
	
	pb->entries = malloc(size*sizeof(PhoneBookEntry));
	if(pb->entries==NULL) {
		free(pb);
		return NULL;
	}
	pb->numEntries = 0;
	pb->size = size;
	
	
	return pb;
};

void destroy(PhoneBook* pb) {
  if (pb == NULL) return; 

  free(pb->entries);
  pb->entries= NULL;

  free(pb);
  pb = NULL;
}

bool insert(PhoneBook* pb, char* name,char* phonenumber) {
	if (pb == NULL || name == NULL || phonenumber == NULL) return false;
	
	int index = -1;
	for(int i=0;i< pb->size;i++) {
		if(strcmp(pb->entries[i].name,name) == 0) {
			index = i;
			strncpy(pb->entries[index].phonenumber, phonenumber, MAX_LENGTH);
			pb->entries[index].phonenumber[MAX_LENGTH] = '\0';
			return true;
		}
	}
	if(index == -1) {
		if(pb->numEntries < pb->size) {
			strncpy(pb->entries[pb->numEntries].name, name, MAX_LENGTH);
			pb->entries[pb->numEntries].name[MAX_LENGTH] = '\0';
			strncpy(pb->entries[pb->numEntries].phonenumber, phonenumber, MAX_LENGTH);
			pb->entries[pb->numEntries].phonenumber[MAX_LENGTH] = '\0';	
			pb->numEntries+=1;
			return true;
		}
		else {
			return false;
		}
	}
	
	
}

char* get(PhoneBook* pb,char *name) {
	int index = -1;
	for(int i=0;i< pb->numEntries;i++) {
		if(strcmp(pb->entries[i].name,name) == 0) {
			index = i;
		}
	}
	if(index==-1) {
			return NULL;
	}
	else {
		return pb->entries[index].phonenumber;
	}
}

void print(PhoneBook* pb) {
	for(int i=0;i< pb->numEntries;i++) {
		
		printf("%s -  %s\n", pb->entries[i].name,pb->entries[i].phonenumber);
			
	}
	
	
}

void dump(PhoneBook* pb, char *filename) {
	
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		return;
	}
  
	for (int i = 0; i < pb->numEntries; i++) {
		fprintf(file, "%s -  %s\n", pb->entries[i].name,pb->entries[i].phonenumber);
	}
  
	fclose(file);
}
