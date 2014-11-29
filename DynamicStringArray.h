/***********
 * DynamicStringArray defines and demonstrates the class DynamicStringArray
 * This class creates a dynamic array of strings
 *
 * written by petEEy
 */

#include <new>
#include <string>

class DynamicStringArray {
	//A private member variable called dynamicArray that references a dynamic array of type string.
	std::string * dynamicArray;
	//A private member variable called size that holds the number of entries in the array.
	int size;
	public:
		DynamicStringArray(void);
		DynamicStringArray(const DynamicStringArray& org);
		~DynamicStringArray(void);
		int getSize(void) const {return size;};
		void addEntry(std::string newStr);
		bool deleteEntry(std::string findThis);
		std::string getEntry(const int index) const;
		void operator = (const DynamicStringArray& org);
};

