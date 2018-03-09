# Introduction #
in c programming, struct is one of its structural  types.for one whole,it may consist of much data which is different from others,such as one student,it include name(char*),student number(int or unsigned int) and etc.
under the circumstance,struct can solve the problem faultlessly.


# Definition #
the element of struct,which was called "member" usually.
The general definition type:

	struct structName{
		member1 definition;
		member2 definition;
	}name,*pointerName;
 example:
		
	struct students{
		char* name;
		unsigned int stuNumber;
	}stu,*st;
Within it,"stu" and "*stu" are  onmissible.Among the struct,stu is a practical object(`struct students stu;`).`*st` was a null pointer.

The general tpye:

   ` struct students stu1;`

Certainly,in your struct,the element is another struct is feasible.Etc:

    struct birthday{
		int month;
		int day;	
	};
	
	struct student{
		char  *name;
		int	stuNum;
		struct birthday birth;
	};

# Access 
To visit the struct, we can use member access operator(**.**).
such as:
we can use  `stu1.stuNumber = 2233;`.In the same way,if we want to get stu's birthday,we can use`stu1.birth.day = 223;`

# Initialization #
There are three way to initialize the struct;

**①after your definition**:
   
	struct students stu1;
	strcpy(stu1.name,"erhuo");
	stu1.stuNumber = 1022;

**or**
  
	struct students stu2;
	stu1 = {"erhuo",1022};

**②when you ctreat the struct,you can also initialize it:**

    struct student{
		char *name;
		int stuNum;
		int eng;
	} stu ={"erhuo",1022,32}; //name(erhuo),stuNum(1022),eng(32)
 
**③you can use another struct to initialize the struct:**

    struct student stu1 = {"erhuo",22,33};
	struct student stu2 = stu1;

about the significance of pragma pack,you can visit [**csdn bolg**](http://blog.csdn.net/yanggangclcsdn/article/details/49718131).

# Code #

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
    
    int main()
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
    }