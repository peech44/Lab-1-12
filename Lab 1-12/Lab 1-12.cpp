// Lab 1-12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>


using namespace std;

class student {
public:
	student() {
		studentid = 0;
		studentname = "ken cosh";
	}
	student(int newid, string newname) {
		studentid = newid;
		studentname = newname;
	}
	int getid() {
		return studentid;
	}
	string getname() {
		return studentname;
	}


private:
	int studentid;
	string studentname;


};
void hashid(int hashid) {


}

void main() {

	student s1;
	cout << "get structor = " << s1.getname() << " ---- " << s1.getid() << endl;
	student s2(10, "kk");
	cout << "get structor = " << s2.getname() << " ---- " << s2.getid() << endl;


	/*list<student>s3[50];
	s3[hash].push_back(s2.getid);
	s3.push_back(s2.getname);
	int searchid;
	cout << "search hash" << endl;
	cin >> searchid;
	cout << "get structor = " << s2.getname() << " ---- " << s2.getid() << endl;*/




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
