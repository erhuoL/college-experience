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
	unsigned int stuNumber;
	unsigned int chi;
	unsigned int eng;
}stu,*st;

/*int main()
{
	struct  students stu1;
	struct students stu2;
	stu1.name = "erhuo";
	stu2 = { "erhuo", 1022, 22, 33 };
	cout << stu2.chi;
	stu1.chi = 33;
	stu.chi = 22;
	printf("%u %u", stu.chi, stu1.chi);
	st = &stu1;
	(*st).chi++;
	cout << stu1.chi;
    return 0;
}*/

