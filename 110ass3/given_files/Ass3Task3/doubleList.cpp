//Provide the implementation for the DoubleList class in this file.

template<class T>
ostream& operator<<(ostream& os, DoubleList<T>& ll) {
	return ll.print(os);
}

template<class T>		
DoubleList<T>::DoubleList(){
	this->dhead = NULL;
}

template<class T>
DoubleList<T>::DoubleList(const DoubleList<T>& other) {
	
	dNode<T> *nodePtr;
	dNode<T> *curNodePtr;

	nodePtr = other.dhead;
	
	if(other.dhead) {
		this->dhead = new dNode<T>(other.dhead->data, other.dhead->next, other.dhead->prev);
		nodePtr = nodePtr->next;

		curNodePtr =this->dhead;
		while(nodePtr)
		{	
			curNodePtr->next = new dNode<T>(nodePtr->data, nodePtr->next, nodePtr->prev);
			curNodePtr = curNodePtr->next;
			nodePtr = nodePtr->next;
		}
	} else {
		dhead = NULL;
	}
}

template<class T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList<T>& other) {

	
	this->clear();
	
	dNode<T> *nodePtr;
	dNode<T> *curNodePtr;
	
	nodePtr = other.dhead;
	
	if(other.dhead) {
		dhead = new dNode<T>(other.dhead->data, other.dhead->next, other.dhead->prev);
		nodePtr = nodePtr->next;
		
		curNodePtr =this->dhead;
		while(nodePtr)
		{	
			curNodePtr->next = new dNode<T>(nodePtr->data, nodePtr->next, nodePtr->prev);
			curNodePtr = curNodePtr->next;
			nodePtr = nodePtr->next;
		}
	} else {
		dhead = NULL;
	}
}

template<class T>
DoubleList<T>* DoubleList<T>::clone() {

	DoubleList<T> *listPtr = new DoubleList<T>(*this);
	
	return listPtr;
}

template<class T>
DoubleList<T>::~DoubleList(){
	this->clear();
	
}

template<class T>
void DoubleList<T>::insert(int index, T data) {

	if(index < 0)
		throw "invalid index";
	
	dNode<T> *newNode;
	dNode<T> *nodePtr;
	dNode<T> *previousNode = NULL;
	
	newNode = new dNode<T>(data);
	
	if(!dhead)
	{
		dhead = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	} else {
		nodePtr =this->dhead;
		previousNode = NULL;
		
		int i;
		for(i = 0; nodePtr != NULL && i < index; i++)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if(previousNode == NULL)
		{
			dhead = newNode;
			newNode->next = nodePtr;
			newNode->prev = NULL;
		}
		else if( i == index == size() )
		{
			previousNode->next = newNode;
			newNode->prev = previousNode;
			newNode->next = NULL;
		}
		else if( i == index )
		{
			previousNode->next = newNode;
			newNode->prev = previousNode;
			newNode->next = nodePtr;
			if(nodePtr != NULL)
				nodePtr->prev = newNode;
		} else
		{
			throw "invalid index";
		}
	}	
}

template<class T>
T DoubleList<T>::remove(int index){

	if(this->dhead == NULL)
		throw "empty structure";
	if(index < 0 || index >= this->size())
		throw "invalid index";
	
	
	dNode<T> *nodePtr;
	dNode<T> *previousNode;
	T delVal;
	
	if(index == 0 && size() == 1)
	{
		delVal = dhead->data;
		delete this->dhead;
		this->dhead = NULL;
		return delVal;
	}
	
	if( index == 0 )
	{
		delVal =this->dhead->data;
		nodePtr =this->dhead->next;
		delete this->dhead;
		dhead = nodePtr;
		nodePtr->prev = NULL;
	} 
	else if( index == 0 && size() == 1 )
	{
		cout << "here";
		delVal = dhead->data;
		delete this->dhead;
		this->dhead = NULL;
		return delVal;
	}
	else
	{
		nodePtr = this->dhead;
		for(int i = 0; nodePtr != NULL && i != index; i++)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if(nodePtr)
		{
			previousNode->next = nodePtr->next;
			if(previousNode->next != NULL)
				previousNode->next->prev = previousNode;
			delVal = nodePtr->data;
			delete nodePtr;
		}
	}
	
	return delVal;
}
	
template<class T>	
T DoubleList<T>::get(int index) const {
	dNode<T> *nodePtr;
	dNode<T> *nextPtr;
	
	
	if(!dhead)
		throw "empty structure";
	if(index<0)
		throw "invalid index";
	
	nodePtr = this->dhead;
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

template <class T>
T DoubleList<T>::operator[](int index){

	return this->get(index);
}

template<class T>
bool DoubleList<T>::isEmpty() {
	
	return !dhead;
}

template<class T>
void DoubleList<T>::clear() {

	dNode<T> *nodePtr;
	dNode<T> *nextNode;
	
	nodePtr = this->dhead;
	
	while(nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	
	this->dhead = NULL;
}

template<class T>
dNode<T>* DoubleList<T>::getHead() const{
	return this->dhead;
}

template<class T>
ostream& DoubleList<T>::print(ostream& os){ 
	dNode<T> *nodePtr;
	
	nodePtr = this->dhead;
	
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
int DoubleList<T>::size() const{

	dNode<T> *nodePtr;
	
	nodePtr = this->dhead;
	int i;
	
	for(i = 0; nodePtr; i++)
		nodePtr = nodePtr->next;
	
	return i;
}

template <class T>
DoubleList<T>& DoubleList<T>::operator+(const DoubleList<T>& other){
	
	DoubleList<T> *newList = this->clone();

	if(!other.dhead)
		return *newList;
	if(!this->dhead) {
		delete newList;
		newList = new DoubleList<T>(other);
		return *newList;
	}
	
	dNode<T> *nodePtr;
	dNode<T> *otherPtr;
	//cout << newList->dhead << endl;
	if( newList->dhead ) {
		// go to the end of newList
	//cout << "here";

		nodePtr = newList->getHead();
		
		while(nodePtr->next)
			nodePtr = nodePtr->next;
	
	

	
		otherPtr = other.getHead();
		nodePtr->next = new dNode<T>(otherPtr->data, otherPtr->next);
		nodePtr->next->prev = nodePtr;
		nodePtr = nodePtr->next;
	} else {

		*newList = other;
		return *newList;
	}
	
	if(nodePtr->next) {
		
		while(otherPtr->next) {
			//cout << "h" << endl;
			otherPtr = otherPtr->next;
			nodePtr->next = new dNode<T>(otherPtr->data, otherPtr->next);
			nodePtr->next->prev = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		nodePtr->next = NULL;
	}
	
	return *newList;
}