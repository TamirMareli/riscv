#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORDS 5
#define MAX_WORD_LENGTH 10
typedef struct Command {
	char add[10];
	char name[10];
	char wereTo[3];
	char from1[3];
	char from2[3];
	char jamp[10];
	char print[50];
	struct Command* next;
}command;
command* constructor(const char* str, command* temp);
void main() {

	FILE* pFile1;
	FILE* pFile2;
	char buffer[80];
	command* h = NULL;
	pFile1 = fopen("trace1.txt", "r");
	pFile2 = fopen("trace2.txt", "r");
	if (pFile1 == NULL)
		fprintf(stdout, "Error opening file\n");//screen
	else
		while (!feof(pFile1)) {
			if (fgets(buffer, 80, pFile1) != NULL) {
				fprintf(stdout, "%s", buffer);
				command* temp = (command*)malloc(sizeof(command));
				constructor(buffer, temp);
				temp->next = h;
				h = temp;
			}
		}
		

}
command* constructor(const char* str,command* temp) {
	char words[MAX_WORDS][MAX_WORD_LENGTH];
	int wordCount = 0;

	// Split the sentence into words
	char* token = strtok(str, " ");
	while (token != NULL && wordCount < MAX_WORDS) {
		strcpy(words[wordCount], token);
		wordCount++;
		token = strtok(NULL, " ");
	}
	strcpy(temp->add, words[0]);
	strcpy(temp->name, words[1]);
	if (!strcmp(temp->name, "lw")) {
		strcpy(temp->wereTo, words[2]);
		strcpy(temp->jamp, words[3]);
		strcpy(temp->from1, words[4]);
		strcpy(temp->print, temp->name);
		strcat(temp->print, " ");
		strcat(temp->print,temp->wereTo);
		strcat(temp->print, " ");
		strcat(temp->print, temp->jamp);
		strcat(temp->print, " ");
		strcat(temp->print, temp->from1);
		strcat(temp->print, " ");
	}
	else if (!strcmp(temp->name, "sw")) {
		strcpy(temp->from1, words[2]);
		strcpy(temp->jamp, words[3]);
		strcpy(temp->wereTo, words[4]);
		strcpy(temp->print, temp->name);
		strcat(temp->print, " ");
		strcat(temp->print, temp->wereTo);
		strcat(temp->print, " ");
		strcat(temp->print, temp->jamp);
		strcat(temp->print, " ");
		strcat(temp->print, temp->from1);
		strcat(temp->print, " ");
	}
	else if (!strcmp(temp->name, "add")||!strcmp(temp->name, "sub")|| !strcmp(temp->name, "or")|| !strcmp(temp->name, "and")) {
		strcpy(temp->wereTo, words[2]);
		strcpy(temp->from1, words[3]);
		strcpy(temp->from2, words[4]);
		strcpy(temp->print, temp->name);
		strcat(temp->print, " ");
		strcat(temp->print, temp->wereTo);
		strcat(temp->print, " ");
		strcat(temp->print, temp->from1);
		strcat(temp->print, " ");
		strcat(temp->print, temp->from2);
		strcat(temp->print, " ");
	}
	else if (!strcmp(temp->name, "addi") || !strcmp(temp->name, "subi") || !strcmp(temp->name, "ori") || !strcmp(temp->name, "andi")) {
		strcpy(temp->wereTo, words[2]);
		strcpy(temp->from1, words[3]);
		strcpy(temp->jamp, words[4]);
		strcpy(temp->print, temp->name);
		strcat(temp->print, " ");
		strcat(temp->print, temp->wereTo);
		strcat(temp->print, " ");
		strcat(temp->print, temp->from1);
		strcat(temp->print, " ");
		strcat(temp->print, temp->jamp);
		strcat(temp->print, " ");
	}
	else if (!strcmp(temp->name, "j")) {
		strcpy(temp->jamp, words[2]);
		strcpy(temp->print, temp->name);
		strcat(temp->print, " ");
		strcat(temp->print, temp->jamp);
		strcat(temp->print, " ");
	}
	else if (!strcmp(temp->name, "beq")|| !strcmp(temp->name, "bneq")) {
		strcpy(temp->from1, words[2]);
		strcpy(temp->from2, words[3]);
		strcpy(temp->jamp, words[4]);
		strcpy(temp->print, temp->name);
		strcat(temp->print, " ");
		strcat(temp->print, temp->from1);
		strcat(temp->print, " ");
		strcat(temp->print, temp->from2);
		strcat(temp->print, " ");
		strcat(temp->print, temp->jamp);
		strcat(temp->print, " ");
	}
}