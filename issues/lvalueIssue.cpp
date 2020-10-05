#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct mystruct
{
char *ptr;
char* getPtr() {return ptr;}
};
int main()
{
	string s;

	char *cp=new char[10];
	&cp;

	vector<mystruct> vec;
	vec.push_back(mystruct());

	&vec[0].getPtr();


    //Returns first address pointer to char[20], because always returns the first address
	return 0;
}
