#include "pch.h"
#include <stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int  a, b, c, max;
	printf("please  input the a b c:\n");
	scanf_s("%d %d %d", &a, &b, &c);
	max = a;
	if (max <= b)
		max = b;
	if (max <= c)
		max = c;
	printf("the max is %d", max);
}

