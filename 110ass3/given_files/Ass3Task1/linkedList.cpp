//Provide the implementation for the LinkedList class in this file.

#include <string>

template<class T>
ostream& operator<<(ostream& os, LinkedList<T>& ll) {
	return ll.print(os);
}

/*
The constructor initializes all relevant member variables.
*/
template<class T>
LinkedList<T>::LinkedList(){
	head = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other){
	
	Node<T> *nodePtr;
	Node<T> *curNodePtr;

	nodePtr = other.head;
	
	if(other.head) {
		head = new Node<T>(other.head->data, other.head->next);
		nodePtr = nodePtr->next;

		curNodePtr = head;
		while(nodePtr)
		{	
			curNodePtr->next = new Node<T>(nodePtr->data, nodePtr->next);
			curNodePtr = curNodePtr->next;
			nodePtr = nodePtr->next;
		}
	} else {
		head = NULL;
	}

	
	
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other){

	this->clear();
	
	Node<T> *nodePtr;
	Node<T> *curNodePtr;
	
	nodePtr = other.head;
	
	if(other.head) {
		head = new Node<T>(other.head->data, other.head->next);
		nodePtr = nodePtr->next;
		
		curNodePtr = head;
		while(nodePtr)
		{	
			curNodePtr->next = new Node<T>(nodePtr->data, nodePtr->next);
			curNodePtr = curNodePtr->next;
			nodePtr = nodePtr->next;
		}
	} else {
		head = NULL;
	}
}

/*
Creates a dynamically allocated deep copy of the object and returns
a pointer to it
*/
template<class T>
LinkedList<T>* LinkedList<T>::clone() {
	
	LinkedList<T> *listPtr = new LinkedList<T>(*this);
	
	return listPtr;
}

template<class T>
LinkedList<T>::~LinkedList(){
	this->clear();
}

/*
Inserts an element at the given index.  The following holds 
for this function:

1.) It is valid to insert at index 0 of an empty list.

2.) It is valid to insert at the index returned by size().  Simply
    append the element to the back of the list.

3.) Only indices between 0 and size() are valid. (0 <= index <= size())

4.) For an invalid index, throw an exception message "invalid index"
hint: inserting a value at a specified index causes all nodes after that index
to shift backwards.
e.g.: index  0 1 2 3
	  data  [1,2,3,5]
	  insert 4 at index 3
	  result: [1,2,3,4,5]
*/
template<class T>
void LinkedList<T>::insert(int index, T data){
	
	if(index < 0)
		throw "invalid index";
	
	Node<T> *newNode;
	Node<T> *nodePtr;
	Node<T> *previousNode = NULL;
	
	newNode = new Node<T>(data);
	
	if(!head)
	{
		head = newNode;
		newNode->next = NULL;
	} else {
		nodePtr = head;
		previousNode = NULL;
		
		int i;
		for(i = 0; nodePtr != NULL && i < index; i++)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if(previousNode == NULL)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else if( i == index )
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		} else
		{
			throw "invalid index";
		}
	}
}

/*
Removes and returns the element at the index passed in 
as a parameter. If an invalid delete is attempted
throw an appropriate string error.
hint: different errors if invalid index or empty list
*/
template<class T>
T LinkedList<T>::remove(int index){
	
	if(this->head == NULL)
		throw "empty structure";
	if(index < 0 || index >= this->size())
		throw "invalid index";
	
	Node<T> *nodePtr;
	Node<T> *previousNode;
	T delVal;
	
	if( index == 0 )
	{
		delVal = head->data;
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		for(int i = 0; nodePtr != NULL && i != index; i++)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if(nodePtr)
		{
			previousNode->next = nodePtr->next;
			delVal = nodePtr->data;
			delete nodePtr;
		}
	}
	
	return delVal;
}

/*
Returns the element at the index passed in 
as a parameter. The element is not removed from the data structure.
If an invalid index is given, throw an appropriate string error.
hint: different errors if invalid index or empty list
*/
template<class T>
T LinkedList<T>::get(int index) const {
	Node<T> *nodePtr;
	Node<T> *nextPtr;

	
	if(!head)
		throw "empty structure";
	if(index<0)
		throw "invalid index";
	
	nodePtr = head;
	nextPtr = nodePtr->next;
	
	
	int i;
	for(i = 0; nodePtr->next != NULL && i != index; i++)
	{
		nodePtr = nextPtr;
		nextPtr = nodePtr->next;
	}
	//nodePtr = nextPtr;
	
	if( nodePtr != NULL && i == index ) {
		return nodePtr->data;
	} else {
		throw "invalid index";
	}
}

template<class T>
bool LinkedList<T>::isEmpty(){
	if(!head)
		return true;
	else
		return false;
}

/*
Removes all of the nodes from the list.  After this function has
been called on a LinkedList object, the list must be empty.
hint: becareful of memory leaks
*/
template<class T>
void LinkedList<T>::clear(){
	Node<T> *nodePtr;
	Node<T> *nextNode;
	
	nodePtr = head;
	
	while(nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	head = NULL;
}

/*
Returns the head, not the element at the head.
*/
template<class T>
Node<T>* LinkedList<T>::getLeader() const{
	return head;
}

/*The overloaded stream operator for the List class.  If
a List object is printed and contains the elements a,c,b and m, with
element 'a' at index 0 and element 'm' at index 3 (first to last), the 
output MUST be in the following format:
[a,c,b,m]
with no white space or new lines.

NOTE: if the list is empty, output empty square brackets:
[]
*/

template<class T>
ostream& LinkedList<T>::print(ostream& os){
	Node<T> *nodePtr;
	
	nodePtr = head;
	
	os << "[";
	while(nodePtr)
	{
		os << nodePtr->data;
		if(nodePtr->next != NULL)
			os << ",";
		
		nodePtr = nodePtr->next;
	}
	os << "]";
}

template<class T>
int LinkedList<T>::size() const {
	
	Node<T> *nodePtr;
	
	nodePtr = head;
	int i;
	
	for(i = 0; nodePtr; i++)
		nodePtr = nodePtr->next;
	
	return i;
}

template<class T>
T LinkedList<T>::operator[](int index){

		return this->get(index);
}

/*
Appends a list.B to the end of another list.A and returns
the resulting list.
e.g listA = {1,2,3,4,5}, listB = {2,4,6,8};
result = {1,2,3,4,5,2,4,6,8};
hint: be careful of shallow copy
*/

template<class T>
LinkedList<T>& LinkedList<T>::operator+(const LinkedList<T>& other){
	
	LinkedList<T> *newList = this->clone();
	if(!other.head)
		return *newList;
	
	Node<T> *nodePtr;
	Node<T> *otherPtr;
	
	if( newList->head ) {
		// go to the end of newList

		nodePtr = newList->getLeader();
		
		while(nodePtr->next)
			nodePtr = nodePtr->next;
	
	

	
		otherPtr = other.getLeader();
		nodePtr->next = new Node<T>(otherPtr->data, otherPtr->next);
		nodePtr = nodePtr->next;
	} else {
		
		*newList = other;
		return *newList;
	}
	
	if(nodePtr->next) {
		
		while(otherPtr->next) {
			//cout << "h" << endl;
			otherPtr = otherPtr->next;
			nodePtr->next = new Node<T>(otherPtr->data, otherPtr->next);
			nodePtr = nodePtr->next;
		}
		
		nodePtr->next = NULL;
	}
	
	return *newList;
}
