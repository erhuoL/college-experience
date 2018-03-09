#include "stdafx.h"

struct student {
	char *name;
	unsigned int stuNum;
	int eng;
};

struct node
{
	struct student stu;
	struct node *next;
};

