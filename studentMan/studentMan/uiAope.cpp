#include "pch.h"
#include "uiAope.h"
#include <string>
#include <iostream>

using std::cin;
using std::cout;

double readDou(string subject)
{
	double temp;
	print("please input the student's " + subject + " score\n");
	cin >> temp;
	while(temp != -1){
		if (temp <= maxScore && temp >= minSocre)
			return temp;
		cin >> temp;
	}
	return  -1;
}

void print(string str)
{
	cout << str << std::endl;
}

string readStr(string subject)
{
	print("please input the student's " + subject + " \n");
	std::string temp;
	cin >> temp;
	return temp;
}
