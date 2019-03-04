#include "pch.h"
#include <string>
#include <vector>

using	std::vector;
using	std::string;

class  student {
public:
	student() {}
	student(double _eng, double _chinese, double _math, string _name, string _stuNum)
	:eng(_eng), chinese(_chinese), math(_math), name(_name), stuNum(_stuNum){}
	
	void setEng(double _eng) { eng = _eng; }
	double getEng() { return eng; }

	void setChi(double _chinese) { chinese = _chinese; }
	double getChi() { return chinese; }
	
	void setMath(double _math) { math = _math; }
	double getMath() { return math; }

	void setName(string _name) { name = _name; }
	string getName() { return name; }

	void setstuNum(string _stuNum) { stuNum = _stuNum; }
	string getstuNum() { return stuNum; }

	~student() {}
private:
	double	eng;
	double	chinese;
	double	math;
	string  name;
	string	stuNum;
};

vector<student> stuSys;