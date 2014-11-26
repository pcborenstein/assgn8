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
	//will point to an array of strings
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
	//keep track of the old array
	string * tempPtr = dynamicArry;

	//create a new array
	dynamicArry = new string[size + 1];
	dynamicArry[size].assign(newStr);

	//copy all the old values
	for( int i = 0; i < size; i++)
		dynamicArry[size] = tempPtr[size];

	//dont try to delete the nullprt if this is the first string
	if(size>0){
		delete[] tempPtr;
	}
	size++;
}

bool DynamicStringArray::deleteEntry(string findThis){
	//no fkin clue how to do this yet;
}

string DynamicStringArray::getEntry(int index){
	if(index >= size){
		return nullptr;
	}else{
		return dynamicArry[index];
	}
}

int main(){

	DynamicStringArray bookShelf;
	bookShelf.addEntry("Success!\n");
	cout << bookShelf.getEntry(0);

	return 0;
}
