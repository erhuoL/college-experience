# **Synopsis** #
This is my first code project. Which is on the basis of [《C程序设计》](https://www.amazon.cn/dp/B003TQM6L8),the course of my college.The manage is based on linked list.
Through,most of it I was copyed from data datum.

# Code Detail #
First,we need to create a struct named student which include student fundamental information,such as name,student number and etc.

	struct student{
		char *name;
		unsigned int stuNum;
		unsigned int chi;
		unsigned int eng;
	};
Then,we ctreat one linked list to storage all student.

    