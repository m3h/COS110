//Provide the implementation for the CircularList class in this file.

template<class T>
ostream& operator<<(ostream& os, CircularList<T>& ll) {

	return ll.print(os);
}

template<class T>		
CircularList<T>::CircularList(){
	this->head = NULL;
}

template<class T>
CircularList<T>::CircularList(const CircularList<T>& other) {

	Node<T> *nodePtr;
	Node<T> *curNodePtr;
	Node<T> *lost;
	
	nodePtr = other.head;

	if(other.size() == 0) {
		this->head = NULL;
		return;
	}
	if(other.size() == 1) {
		this->head = new Node<T>(other.head->data, other.head->next);
		this->head->next = this->head;
		return;
	}
	
	curNodePtr = new Node<T>(other.head->data, other.head->next);
	this->head = curNodePtr;
	for(int i = 1; i < other.size(); ++i) {
		nodePtr = nodePtr->next;

		curNodePtr->next = new Node<T>(nodePtr->data, nodePtr->next);

		curNodePtr = curNodePtr->next;
	}

	curNodePtr->next = this->head;

}

template<class T>
CircularList<T>& CircularList<T>::operator=(const CircularList<T>& other) {
	
	this->clear();
	
	
	Node<T> *nodePtr;
	Node<T> *curNodePtr;
	Node<T> *lost;
	
	nodePtr = other.head;

	if(other.size() == 0) {
		this->head = NULL;
		return *this;
	}
	if(other.size() == 1) {
		this->head = new Node<T>(other.head->data, other.head->next);
		this->head->next = this->head;
		return *this;
	}
	
	curNodePtr = new Node<T>(other.head->data, other.head->next);
	this->head = curNodePtr;
	for(int i = 1; i < other.size(); ++i) {
		nodePtr = nodePtr->next;

		curNodePtr->next = new Node<T>(nodePtr->data, nodePtr->next);

		curNodePtr = curNodePtr->next;
	}

	curNodePtr->next = this->head;
	return *this;

}


template<class T>
CircularList<T>* CircularList<T>::clone() {
	
	CircularList<T> *listPtr = new CircularList<T>(*this);
	
	return listPtr;
}

template<class T>
CircularList<T>::~CircularList(){
	this->clear();
}
	
template<class T>
void CircularList<T>::insert(int index, T data) {
	
	if(index < 0)
		throw "invalid index";
	if(index > size())
		throw "invalid index";
	
	Node<T> *newNode;
	Node<T> *nodePtr;
	Node<T> *previousNode = NULL;
	
	newNode = new Node<T>(data);
	
	if(!this->head)
	{
		this->head = newNode;
		newNode->next = this->head;
		
	} else if (index == 0) {
		nodePtr = this->head;
		newNode->next = this->head;

		while(nodePtr->next != this->head)
			nodePtr=nodePtr->next;
		
		this->head = newNode;
		nodePtr->next = this->head;
		
	} else if (index == size()) {	// append
		
		nodePtr=this->head;
		
		while(nodePtr->next != this->head)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
		
		newNode->next = this->head;
		
	} else {	// insert in middle

		nodePtr = this->head;
		nodePtr = nodePtr->next;
		if(nodePtr== NULL)
			throw "hello";
		previousNode=this->head;
		int i;
		for(i = 1; i != index; ++i) {
			previousNode=nodePtr;
			nodePtr = nodePtr->next;
		}
		previousNode->next = newNode;
		newNode->next = nodePtr;
	}

}
	
template<class T>
T CircularList<T>::remove(int index){

	
	if(this->head == NULL)
		throw "empty structure";
	if(index < 0 || index >= this->size())
		throw "invalid index";
	
	Node<T> *nodePtr;
	Node<T> *previousNode;
	T delVal;
	
	if( index == 0 && this->size() == 1 ) {
		delVal = this->head->data;
		delete this->head;
		this->head = NULL;
	}
	else if( index == 0 )
	{
		// get last elementl;
		Node<T> *tail = this->head;
		while(tail->next != this->head)
			tail = tail->next;
			
		delVal = this->head->data;
		nodePtr = this->head->next;

		delete this->head;
		this->head = nodePtr;
		tail->next = this->head;
		
		return delVal;
	}
	else
	{
		nodePtr = this->head;
		for(int i = 0; (nodePtr != this->head || i == 0) && i != index; i++)
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
	
template<class T>	
T CircularList<T>::get(int index) const {
	
	Node<T> *nodePtr;
	Node<T> *nextPtr;

	
	if(!this->head)
		throw "empty structure";
	if(index<0)
		throw "invalid index";
	
	nodePtr = this->head;
	nextPtr = nodePtr->next;
	
	
	if( index == 0 )
		return this->head->data;
	
	int i;
	for(i = 0; nodePtr->next != this->head && i != index; i++)
	{
		nodePtr = nextPtr;
		nextPtr = nodePtr->next;
	}
	
	if( nodePtr != this->head && i == index ) {
		return nodePtr->data;
	} else {
		throw "invalid index";
	}
}

template<class T>
bool CircularList<T>::isEmpty() {
	
	return !this->head;
}

template<class T>
void CircularList<T>::clear() {
	
	Node<T> *nodePtr;
	Node<T> *nextNode;
	
	nodePtr = this->head;

	if(!this->head)
		return;
	
	nodePtr = this->head;
	do
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	} while(nodePtr != this->head);

	this->head = NULL;
}

template<class T>
Node<T>* CircularList<T>::getLeader() const{
	return this->head;
}

template<class T>
ostream& CircularList<T>::print(ostream& os){
	
	Node<T> *nodePtr;
	
	nodePtr = this->head;
	
	os << "[";
	
	if(this->head)
		do
		{
			os << nodePtr->data;
			if(nodePtr->next != this->head )
				os << ",";
			
			nodePtr = nodePtr->next;
		} while(nodePtr != this->head);
	os << "]";
}

template<class T>
int CircularList<T>::size() const{
	
	int length = 0;
	
	if(this->head == NULL) {
		return 0;
	}
	
	Node<T> *current = this->head;
	++length;
	current = current->next;
	
	while(current != this->head) {
		++length;
		current = current->next;
	}
	
	return length;
}

template <class T>
CircularList<T>& CircularList<T>::operator+(const CircularList<T>& other){
	
	
	CircularList *temp = new CircularList(*this);
	int count = size();
	int tot = count + other.size();
	
	Node<T> *nodePtr;
	nodePtr = other.head;
	
	try {
	while( count < tot )
	{
		//cout << "count " << count << endl;
		temp->insert(count, nodePtr->data);
		nodePtr = nodePtr->next;
		++count;
	}
} catch ( const char *msg ) {
	cout << msg << endl;
}
	return *temp;

}