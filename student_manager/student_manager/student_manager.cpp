#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct birthday {
	int month;
	int day;
};

struct student {
	char *name;
	int stuNum;
	struct birthday birth;
};

struct students
{
	char *name;
	char *stuNumber;
	unsigned int chi;
	unsigned int eng;
};

struct node {
	struct student stu;
	struct node *next;
}head;

void _deleteOne(int flag, char *string) {}

void _deleteAll() {}

void  modify(int flag,char *string) {}

void insert(int index, struct student &stu) {}

int inputInt() {}

double inputDouble() {}

char *inputStr() {}

void save(struct node &head){}
 
void read() {} 

void print(struct node &head) {}

void sort(struct node &head) {}

struct node makeNode(struct student &stu) {}

void printHeader() {}

//...
