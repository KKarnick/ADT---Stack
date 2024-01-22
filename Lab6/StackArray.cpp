
#include "StackArray.h"

template <typename DataType>
StackArray<DataType>::StackArray(int maxNumber){
	maxSize = maxNumber;
	top = -1;
	dataItems = new DataType[maxSize];
}

template <typename DataType>
StackArray<DataType>::StackArray(const StackArray& other){
	maxSize = other.maxSize;
	top = other.top;
	dataItems = new DataType[maxSize];
	for (int i = 0; i < top; i++)
		dataItems[i] = other.dataItems[i];
}

template <typename DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other){
	    //ensure not same stack reference
	if (this != &other) {
		if (maxSize < other.maxSize) {  //reallocate size if too small
			clear();  //first delete dataItems of calling stack
			dataItems = new DataType[other.maxSize];  //use other's max size as init.
		}
		maxSize = other.maxSize;  //shrink max if larger
		top = other.top;  //set variables equal
		for (int i = 0; i < top; i++)
			dataItems[i] = other.dataItems[i];
	}
	return *this;
}

template <typename DataType>
StackArray<DataType>::~StackArray(){
	delete[] dataItems;
}

template <typename DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error){
	if (isFull())
		throw logic_error("Stack full, no room.");
	else {
		dataItems[top + 1] = newDataItem;  //add to "top" of top of stack
		top++;   //denote new item as top
	}
}

template <typename DataType>
DataType StackArray<DataType>::pop() throw (logic_error){
	if (isEmpty())
		throw logic_error("Empty stack.");
	else {
		DataType temp = dataItems[top];  //set temp marker to top item
		dataItems[top] = 0;  //denote top item as 1 over top
		top--;
		return temp;  //return the "old" top element
	}
}

template <typename DataType>
void StackArray<DataType>::clear(){
	top = -1;  //sets all items as able to be written over
}

template <typename DataType>
bool StackArray<DataType>::isEmpty() const{
	if (top == -1)
		return true;
	else
		return false;
}

template <typename DataType>
bool StackArray<DataType>::isFull() const{
	if (top == (maxSize - 1)) //location is max position
		return true;
	else
		return false;
}

template <typename DataType>
void StackArray<DataType>::showStructure() const 

// Array implementation. Outputs the data items in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.

{
    if( isEmpty() ) {
	cout << "Empty stack." << endl;
    }
    else {
	int j;
	cout << "Top = " << top << endl;
	for ( j = 0 ; j < maxSize ; j++ )
	    cout << j << "\t";
	cout << endl;
	for ( j = 0 ; j <= top  ; j++ )
	{
	    if( j == top )
	    {
	        cout << '[' << dataItems[j] << ']'<< "\t"; // Identify top
	    }
	    else
	    {
		cout << dataItems[j] << "\t";
	    }
	}
	cout << endl;
    }
    cout << endl;
}