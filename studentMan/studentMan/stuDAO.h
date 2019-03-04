#include "pch.h"
#include "student.h"

class stuDAO {
public:
	void	Add(vector<student> &stu);
	void	_delete();
	void	change(vector<student> &stu);
	void	find(vector<student> &stu);
	void	write(vector<student> &stu);
	void	read(vector<student> &stu);
	
private:
	student inputInformation();
	void	deleteByName(vector<student>  &stuSys);
	void	deleteByStuNum(vector<student> &stuSys);
};