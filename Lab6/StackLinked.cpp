
#include "StackLinked.h"

template <typename DataType>
StackLinked<DataType>::StackLinked (int maxNumber){
	top = NULL;
}

template <typename DataType>
StackLinked<DataType>::StackLinked(const StackLinked& other){
	/*if (this != &other) {//check for ref to same stack
		clear();  //clear existing stack
                      //set top node to other's top node
		top = new StackNode(other.top->dataItem, 0);
		StackNode* nodeBeforeTop = top;   //name a node "under" the top
		StackNode* currOther = other.top;
		while (currOther->next != 0) {
				top = new StackNode(other.top->dataItem, other.top->next);
		}

		
	}
	*/
}

template <typename DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other){
/*
	// not yet implemented
	*/
}

template <typename DataType>
StackLinked<DataType>::~StackLinked()
{
	clear();
}

template <typename DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error){
	if (isFull())
		throw logic_error("Stack is full.");
	StackNode* t = new StackNode ( newDataItem, top);
	top = t;
}

template <typename DataType>
DataType StackLinked<DataType>::pop() throw (logic_error){
	if (isEmpty())
		throw logic_error("Empty stack.");
	else {
		DataType d = top->dataItem;
		StackNode* t = top;
		top = top->next;
		delete t;
		return d;
	}
}

template <typename DataType>
void StackLinked<DataType>::clear(){
	StackNode* t;
	while ( top != NULL)
	{
		t = top;
		top = top->next;
		delete t;
	}
}

template <typename DataType>
bool StackLinked<DataType>::isEmpty() const{
	return (top == NULL);
}

template <typename DataType>
bool StackLinked<DataType>::isFull() const{
	return false;  //max size given as var, but unused
}

template <typename DataType>
void StackLinked<DataType>::showStructure() const{
    if( isEmpty() )
    {
	cout << "Empty stack" << endl;
    }
    else
    {
        cout << "Top\t";
	for (StackNode* temp = top; temp != 0; temp = temp->next) {
	    if( temp == top ) {
		cout << "[" << temp->dataItem << "]\t";
	    }
	    else {
		cout << temp->dataItem << "\t";
	    }
	}
        cout << "Bottom" << endl;
    }

}