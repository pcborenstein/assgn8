/***********
 * imsoFresh defines and demonstrates the class DynamicStringArray
 * This class creates a dynamic array of strings
 *
 * written by petEEy
 */

#include <iostream>
#include <string>
#include <new>

using namespace std;


class DynamicStringArray {
	string * dynamicArry;
	int size;
	public:
		DynamicStringArray(void);
		int getSize(void);
		void addEntry(string newStr);
		bool deleteEntry(string findThis);
		string getEntry(int index);
};

DynamicStringArray::DynamicStringArray(void){
	size = 0;
	dynamicArry = nullptr;
}

int DynamicStringArray::getSize(void){
	return size;
}

void DynamicStringArray::addEntry(string newStr){
	string * tempPtr = dynamicArry;
	size++;
	cout << size <<endl;
	dynamicArry = new string[size];
	cout << "something\n" << newStr << endl;
	dynamicArry[size].assign(newStr);
	cout<< "test1"<<endl;
	if(size>0){
		delete[] tempPtr;
	}
	cout<< "test2"<<endl;
	
}

bool DynamicStringArray::deleteEntry(string findThis){
	//no fkin clue how to do this yet;
}

string DynamicStringArray::getEntry(int index){
	if(index > size){
		return nullptr;
	}else{
		return dynamicArry[size];
	}
}

int main(){

	DynamicStringArray bookShelf;
	cout<< "body test 1\n";
//	bookShelf.addEntry("Success!\n");
//	cout << bookShelf.getEntry(0);

	string * myStr;
	myStr = new string;
	(*myStr).assign("hello");
	cout << myStr->c_str() << endl;

	return 0;

}
