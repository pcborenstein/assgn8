/***********
 * DynamicStringArray defines and demonstrates the class DynamicStringArray
 * This class creates a dynamic array of std::strings
 *
 * written by petEEy
 */

#include <DynamicStringArray.h>

//A default constructor that sets the dynamic array to NULL and sets size to 0
DynamicStringArray::DynamicStringArray(void){
	size = 0;
	dynamicArray = NULL;
}

//A copy constructor that makes a copy of the input object’s dynamic array.
DynamicStringArray::DynamicStringArray(const DynamicStringArray& org) {
	size = org.getSize();
	dynamicArray = new std::string[size];
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
	this->dynamicArray = new std::string[this->size];
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
A function named addEntry that takes a std::string as input. The function should create a new dynamic array
one element larger than dynamicArray, copy all elements from dynamicArray into the new array, add the
new std::string onto the end of the new array, increment size, delete the old dynamicArray, and then set
dynamicArray to the new array
*/
void DynamicStringArray::addEntry(std::string newStr){
	//keep track of the old array
	std::string * tempPtr = dynamicArray;

	//create a new array
	dynamicArray = new std::string[size + 1];
	dynamicArray[size].assign(newStr);

	//copy all the old values
	for( int i = 0; i < size; i++){
		dynamicArray[i] = tempPtr[i];
	}

	//dont try to delete the nullprt if this is the first std::string
	if(size>0){
		delete[] tempPtr;
	}
	size++;
}

/*
A function named deleteEntry that takes a std::string as input. The function should search dynamicArray for
the std::string. If not found, it returns false. If found, it creates a new dynamic array one element smaller than
dynamicArray. It should copy all elements except the input std::string into the new array, delete dynamicArray,
decrement size, and return true
   */
bool DynamicStringArray::deleteEntry(std::string findThis){
	bool found = false;
	//see if the std::string is in the array
	int i;
	for(i = 0; i < size; i++){
		if(findThis==dynamicArray[i]){
			found = true;
			break;
		}
	}
	if(found == true){
		//need to copy all entries other than the 'i'th entry
		std::string * temp = dynamicArray;
		dynamicArray = new std::string[size - 1];
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
A function named getEntry that takes an integer as input and returns the std::string at that index in
dynamicArray. It should return NULL if the index is out of dynamicArray’s bounds.
   */

std::string DynamicStringArray::getEntry(const int index) const{
	if(index >= size){
		return NULL;
	}else{
		return dynamicArray[index];
	}
}
