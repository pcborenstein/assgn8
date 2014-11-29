/***********
 * this file is meant to test the capabilities of DynmaicStringArray
 *
 * written by petEEy
 */

#include <iostream>
#include <DynamicStringArray.h>

using namespace std;

void printTest(void){
	DynamicStringArray bookShelf;
	bookShelf.addEntry("The first string\n");

	int strNum = bookShelf.getSize();
	for(int i = 0; i < strNum; i++)
		cout << bookShelf.getEntry(i);

	bookShelf.addEntry("seconds class string\n");

	//create a new dynamic string array before deleting anything
	DynamicStringArray newShelf(bookShelf);

	bookShelf.deleteEntry("The first string\n");
	bookShelf.deleteEntry("this isnt an entry");

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

