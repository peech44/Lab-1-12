// Lab 1-12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Header.h"
#include "Header.cpp"



using namespace std;

class student {
public:
	student() {
		studentid = 1001;
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
	void setid(int newid) {
		studentid = newid;
	}
	void setname(string newname) {
		studentname = newname;
	}

private:
	int studentid;
	string studentname;


};
class Hash {

public:
	//contructor

	Hash() {
		cell = 50;
		table = new List<int>[cell];
		tableName = new List<string>[cell];

	}

	Hash(int c) {

		this->cell = c;

		table = new List<int>[cell];
		tableName = new List<string>[cell];
		
		//List<int> table[7];
	}


	void insert(int ins, string name) {
		cout << "insert" << endl;
		int index = hashFunction(ins);
		cout << endl << "index " << index << endl;
		table[index].tailPush(ins);
		tableName[index].tailPush(name);
	}

	void deleteItem(int del);

	int hashFunction(int ins) {
		return ins % cell;
	}
	void displayHash() {
		cout << "displayHash" << endl;

		for (int i = 0; i < cell; i++) {
			cout << "i = " << i;
			while (table[i].isEmpty() == false) {
				cout << " -------> ";
				table[i].display();
				table[i].headPop();
				cout << " -------> ";
				tableName[i].display();
				tableName[i].headPop();

			}
			
			cout << endl;
		}

	}


private:
	int cell;
	List<int>* table;
	List<string>* tableName;
};


int main() {

	int cell;
	int id;
	string name;
	student stu;
	int numOfstu;

	student s1;
	cout << "get structor = " << s1.getname() << " ---- " << s1.getid() << endl;
	student s2(1002, "kk");
	cout << "get structor = " << s2.getname() << " ---- " << s2.getid() << endl;
	//
	//create sample data
	student s3(1003, "zzzz"); student s4(1004, "xxxxz"); student s5(1005, "trwe"); student s6(1006, "kokkie"); student s7(1007, "ionop");
	student s8(1008, "cvre"); student s9(1009, "vcxd"); student s10(1010, "dfeerd"); student s11(1011, "bretre"); student s12(1012, "nwetre");
	student s13(1013, "mer"); student s14(1014, "maswe"); student s15(1015, "maszer"); student s16(1016, "asdsaa"); student s17(1017, "saewqe");
	student s18(1018, "dewre"); student s19(1019, "ertre"); student s20(1020, "hrewd"); student s21(1021, "gredsa"); student s22(1022, "greewa");
	student s23(1023, "gbeewa"); student s24(1024, "heeras"); student s25(1025, "hooja"); student s26(1026, "hiijoya"); student s27(1027, "joori");
	student s28(1028, "kooire"); student s29(1029, "looiper"); student s30(1030, "laaswer"); student s31(1031, "lasert"); student s32(1032, "lussawe");
	student s33(1033, "lummee"); student s34(1034, "loopuytre"); student s35(1035, "pooiper"); student s36(1036, "paaerwq"); student s37(1037, "peeroper");
	student s38(1038, "pumpoi"); student s39(1039, "poijaa"); student s40(1040, "oopiuy"); student s41(1041, "ooaswe"); student s42(1042, "umpiop");
	student s43(1043, "ump90"); student s44(1044, "weeraqw"); student s45(1045, "yummyui"); student s46(1046, "yaaweer"); student s47(1047, "tummy");
	student s48(1048, "tammyui"); student s49(1049, "reewut"); student s50(1050, "weerat"); 
	
	//
	

	// array that contains keys to be mapped 
	int a[] = { 15, 65, 27, 8, 12 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "n=" << n << endl;
	// insert the keys into the hash table 
	
	//Hash h;
	string num = "s";
	for (int i = 0; i < 5; i++) {
		string numi = to_string(i);

		cout << "num = " << num+numi << endl;
	}
	
	
	cout << "Input number of cell " << endl;
	cin >> cell;
	cout << endl;
	Hash h(cell);

	//insert sample data


	h.insert(s1.getid(), s1.getname()); h.insert(s2.getid(), s2.getname()); h.insert(s3.getid(), s3.getname()); h.insert(s4.getid(), s4.getname());
	h.insert(s5.getid(), s5.getname()); h.insert(s6.getid(), s6.getname()); h.insert(s7.getid(), s7.getname()); h.insert(s8.getid(), s8.getname());
	h.insert(s9.getid(), s9.getname()); h.insert(s10.getid(), s10.getname()); h.insert(s11.getid(), s11.getname()); h.insert(s12.getid(), s12.getname());
	h.insert(s13.getid(), s13.getname()); h.insert(s14.getid(), s14.getname()); h.insert(s15.getid(), s15.getname()); h.insert(s16.getid(), s16.getname());
	h.insert(s17.getid(), s17.getname()); h.insert(s18.getid(), s18.getname()); h.insert(s19.getid(), s19.getname()); h.insert(s20.getid(), s20.getname());
	h.insert(s22.getid(), s22.getname()); h.insert(s23.getid(), s23.getname()); h.insert(s24.getid(), s24.getname()); h.insert(s25.getid(), s25.getname());
	h.insert(s27.getid(), s27.getname()); h.insert(s28.getid(), s28.getname()); h.insert(s29.getid(), s29.getname()); h.insert(s30.getid(), s30.getname());
	h.insert(s31.getid(), s31.getname()); h.insert(s32.getid(), s32.getname()); h.insert(s33.getid(), s33.getname()); h.insert(s34.getid(), s34.getname());
	h.insert(s35.getid(), s35.getname()); h.insert(s36.getid(), s36.getname()); h.insert(s37.getid(), s37.getname()); h.insert(s38.getid(), s38.getname());
	h.insert(s39.getid(), s39.getname()); h.insert(s40.getid(), s40.getname()); h.insert(s41.getid(), s41.getname()); h.insert(s42.getid(), s42.getname());
	h.insert(s43.getid(), s43.getname()); h.insert(s44.getid(), s44.getname()); h.insert(s45.getid(), s45.getname()); h.insert(s46.getid(), s46.getname());
	h.insert(s47.getid(), s47.getname()); h.insert(s48.getid(), s48.getname()); h.insert(s49.getid(), s49.getname()); h.insert(s50.getid(), s50.getname());
	h.insert(s21.getid(), s21.getname()); h.insert(s26.getid(), s26.getname());



	//

	//
	cout << "Enter Number of student " << endl;
	cin >> numOfstu;

	for (int i = 0; i < numOfstu; i++) {

	
	cout << "Input Student ID " << endl;
	cin >> id;
	cout << endl;
	stu.setid(id);
	//
	cout << "Input Student Name " << endl;
	cin >> name;
	cout << endl;
	stu.setname(name);


	//insert data
	h.insert(stu.getid(), stu.getname());
	//

	}
	

	
	/*
	for (int i = 0; i < n; i++) {
		cout << "i = "<< i << endl;
		cout << "array i = " << a[i] << endl;
		h.insert(a[i]);
		
	}
	*/

	h.displayHash();


	return 0;
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
