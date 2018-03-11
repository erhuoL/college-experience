# **Synopsis** #
This is my first code project. Which is on the basis of [《C程序设计》](https://www.amazon.cn/dp/B003TQM6L8),the course of my college.The manage is based on linked list.
Through,most of it I was copyed from data datum.

# Code Detail #
First,we need to create a struct named student which include student fundamental information,such as name,student number and etc.

	struct student{
		char *name;
		char *stuNum;
		double chi;
		double eng;
	};
Then,we ctreat one linked list to storage all student.

    struct node {
		struct student stu;
		struct node *next;
	};

In fact,at times,wo have to operate on the students,such as insert,delete and modify...so,we created these function:
    
    void _deleteOne(int flag, char *string) {}

	void _deleteAll() {}

	void  modify(int flag,char *string) {}

	void insert(int index, struct student &stu) {}

The information of student isn't out of nowwhere,it is inputed by the operator.So,the function is necessary:

	int inputInt() {}

	double inputDouble() {}

	char *inputStr() {}

Also,we are able to run the program hourly,we have to save the information in the disk.yet,read from disk at the beginning of running the program is pre-requisite:

	void save(struct node &head){}
 
	void read() {} 

maybe,wo want to print all of students' information or sort them to find out the first.thus:

	void print(struct node &head) {}

	void sort(struct node &head) {}
**But**,we should make every function do as few thing as possible.wo need many functions to help make it.

	struct node makeNode(struct student &stu) {}

	void printHeader() {}

	//...

And,wo need some macro definition increase our code's readability in "stdafx.h".

	#define ByName 1
	#define ByStuNum 2
	#define printHeader1 "2233"
	#define printHeader2 "2233"
	//...

# Summary #
In conclusion,only we can finish all above function,we can get a relatively good manager.