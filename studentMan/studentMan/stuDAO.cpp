#include "pch.h"
#include <iostream>
#include "stuDAO.h"
#include "uiAope.h"
#include <iterator>
#include <fstream>

void stuDAO::Add(vector<student>& stu)
{
	//to do
	stu.push_back(inputInformation());
}

void stuDAO::_delete()
{
	print("1. delete by name	2. delete by stuNum\n");
	char c = getchar();
	switch (c){
	case '1':deleteByName(stuSys); break;
	case '2':deleteByStuNum(stuSys); break;
	default:
		break;	
	}
}

void stuDAO::change(vector<student>& stu){

}

void stuDAO::find(vector<student>& stu)
{
}

void stuDAO::write(vector<student>& stu)
{
	std::ofstream  outFile("stuData.db", _IOSbinary);
	int size = stu.size();
	outFile.write((const char*)&size, 4);
	outFile.write((const char*)&stu[0], size * sizeof(student));
	outFile.close();
}

void stuDAO::read(vector<student>& stu)
{
}

student stuDAO::inputInformation()
{
	student temp;
	temp.setEng(readDou("English"));
	temp.setChi(readDou("Chinese"));
	temp.setMath(readDou("math"));
	temp.setName(readStr("name"));
	temp.setstuNum(readStr("stuNum"));
	return temp;
}

void stuDAO::deleteByName(vector<student> &_stuSys){
	string temp = readStr("name");
	for (auto ite = _stuSys.begin(); ite != _stuSys.end(); ite++) {
		if ((*ite).getName() == temp)
		stuSys.erase(ite);
		return;
	}
	std::cout << "no student" << std::endl;
	return;
}

void stuDAO::deleteByStuNum(vector<student> &_stuSys)
{
	string temp = readStr("stuNum");
	for (auto ite = _stuSys.begin(); ite != _stuSys.end(); ite++) {
		if ((*ite).getstuNum() == temp)
		stuSys.erase(ite);
		return;
	}
	std::cout << "no student" << std::endl;
	return;
}
