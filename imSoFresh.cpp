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
	//A private member variable called dynamicArray that references a dynamic array of type string.
	string * dynamicArray;
	//A private member variable called size that holds the number of entries in the array.
	int size;
	public:
		DynamicStringArray(void);
		DynamicStringArray(const DynamicStringArray& org);
		~DynamicStringArray(void);
		int getSize(void) const {return size;};
		void addEntry(string newStr);
		bool deleteEntry(string findThis);
		string getEntry(const int index) const;
		void operator = (const DynamicStringArray& org);
};


//A default constructor that sets the dynamic array to NULL and sets size to 0
DynamicStringArray::DynamicStringArray(void){
	size = 0;
	dynamicArray = NULL;
}

//A copy constructor that makes a copy of the input object’s dynamic array.
DynamicStringArray::DynamicStringArray(const DynamicStringArray& org) {
	size = org.getSize();
	dynamicArray = new string[size];
	for(int i = 0; i < size; i++){
		dynamicArray[i] = org.getEntry(i);
	}
}
//Overload the assignment operator so that the dynamic array is properly copied to the target object
void DynamicStringArray::operator = (const DynamicStringArray& org){
	DynamicStringArray temp(org);
	if(this->size !=0)
		delete[] this->dynamicArray;

	this->size = org.getSize();
	this->dynamicArray = new string[this->size];
	for(int i = 0; i < this->size; i++)
		this->dynamicArray[i] = org.getEntry(i);
}

//A destructor that frees up the memory allocated to the dynamic array
DynamicStringArray::~DynamicStringArray(void){
	delete[] dynamicArray;
}
/*
//A function that returns size.
int& DynamicStringArray::getSize(void) const{
	return size;
}
*/
/*
A function named addEntry that takes a string as input. The function should create a new dynamic array
one element larger than dynamicArray, copy all elements from dynamicArray into the new array, add the
new string onto the end of the new array, increment size, delete the old dynamicArray, and then set
dynamicArray to the new array
*/
void DynamicStringArray::addEntry(string newStr){
	//keep track of the old array
	string * tempPtr = dynamicArray;

	//create a new array
	dynamicArray = new string[size + 1];
	dynamicArray[size].assign(newStr);

	//copy all the old values
	for( int i = 0; i < size; i++){
		dynamicArray[i] = tempPtr[i];
	}

	//dont try to delete the nullprt if this is the first string
	if(size>0){
		delete[] tempPtr;
	}
	size++;
}

/*
A function named deleteEntry that takes a string as input. The function should search dynamicArray for
the string. If not found, it returns false. If found, it creates a new dynamic array one element smaller than
dynamicArray. It should copy all elements except the input string into the new array, delete dynamicArray,
decrement size, and return true
   */
bool DynamicStringArray::deleteEntry(string findThis){
	bool found = false;
	//see if the string is in the array
	int i;
	for(i = 0; i < size; i++){
		if(findThis==dynamicArray[i]){
			found = true;
			break;
		}
	}
	if(found == true){
		//need to copy all entries other than the 'i'th entry
		string * temp = dynamicArray;
		dynamicArray = new string[size - 1];
		for(int j; j < size; j++){
			if(j < i){
				dynamicArray[j] = temp[j];
			}else if(j > i){
				dynamicArray[j - 1] = temp[j];
			}
		}
		size--;
	}

	return found;
}

/*
A function named getEntry that takes an integer as input and returns the string at that index in
dynamicArray. It should return NULL if the index is out of dynamicArray’s bounds.
   */

string DynamicStringArray::getEntry(const int index) const{
	if(index >= size){
		return NULL;
	}else{
		return dynamicArray[index];
	}
}

void printTest(void){
	DynamicStringArray bookShelf;
	bookShelf.addEntry("Success!\n");
	bookShelf.addEntry("failure\n");

	int strNum = bookShelf.getSize();

	for(int i = 0; i < strNum; i++)
		cout << bookShelf.getEntry(i);

	DynamicStringArray newShelf(bookShelf);

	bookShelf.deleteEntry("failure\n");

	strNum = bookShelf.getSize();
	for(int i = 0; i < strNum; i++)
		cout << bookShelf.getEntry(i);

	cout << endl;

	strNum = newShelf.getSize();
	for(int i = 0; i < strNum; i++)
		cout << newShelf.getEntry(i);

	cout << endl;
	newShelf = bookShelf;
	strNum = newShelf.getSize();
	for(int i = 0; i < strNum; i++)
		cout << newShelf.getEntry(i);


}

int main(){

	printTest();
	return 0;
}

