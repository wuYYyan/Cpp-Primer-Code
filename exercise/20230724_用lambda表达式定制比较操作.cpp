#include <iostream>
#include <set>
#include <map>
#include <string>

typedef struct Student
{
	std::string name;
	int grade;
} Student;

int main()
{
	
 
	//Lambda设置map排序规则,同样适合于vector,list
	auto func = [](const Student* left, const Student* right)
	{
		return left->grade < right->grade;
	};
 
	//定义map
	std::map<const Student*, std::string, decltype(func)> stuMap(func);
 
	//定义set
	std::set<const Student*, decltype(func)> stuSet(func);
 
	//测试代码
	Student* s1 = new Student{ "s1",12 };
	Student* s2 = new Student{ "s2",84 };
	Student* s3 = new Student{ "s3",99 };
	Student* s4 = new Student{ "s4",33 };
 
	//map
	stuMap.emplace(s1,"otherVals1");
	stuMap.emplace(s2, "otherVals2");
	stuMap.emplace(s3, "otherVals3");
	stuMap.emplace(s4, "otherVals4");
	std::cout << "map:" << '\n';
	for (auto stu : stuMap)
	{
		std::cout << stu.first->grade << " : " << stu.first->name <<" : "<<stu.second<< '\n';
	}
	std::cout << "-------------------------------------------" << '\n';
 
	//set
	stuSet.insert(s1);
	stuSet.insert(s2);
	stuSet.insert(s3);
	stuSet.insert(s4);
	std::cout << "set:" << '\n';
	for (auto stu : stuSet)
	{
		std::cout << stu->grade << " : " << stu->name << '\n';
	}
	std::cout << "-------------------------------------------" << '\n';
 
	delete s1, s2, s3, s4;
	system("Pause");
	return 0;
}