#include "LinkedList.h"


LinkedList::LinkedList(){
	head = NULL;
	length = 0;
}

LinkedList::~LinkedList(){
	node *trav;
	node *prev = head;
	if(!head){
		return;
	}
	while(trav){
		trav = prev->next;
		delete prev;
		prev = trav;
	}
}

LinkedList::LinkedList(int length, string *value){
	this->length = length;
	node *newnode;
	node *trav = head;
	for(int i  = 0; i < length; i++){
		newnode = new node();

		newnode->name = value[i];
		newnode->next = NULL;

		if(i==0){
			head = newnode;
			trav = head;
		}
		else{
			trav->next = newnode;
			trav = trav->next;
		}
	}
}

void LinkedList::display(){
	if(head == NULL)
		return;
	node *trav  = head;
	while(trav){
		cout<<trav->name<<" ";
		trav  = trav->next;
	}
	cout<<endl;
}


LinkedList* LinkedList::combine(LinkedList* two){

/*Implement this function.*/
	if(head==NULL && two->head==NULL)
		return NULL;
	
	
	LinkedList *com = new LinkedList(*this);
	node *trav = com->head;
	
	if(trav != NULL)
		while(trav->next)
			trav = trav->next;

	LinkedList *test = new LinkedList(*two);
	if(trav != NULL)
		trav->next = test->head;
	else
		com->head = test->head;
	
	com->length = com->length + two->length;
	
	// SORT NOW
	if(com->head == NULL || com->length == 1)
		return com;
	
	trav = com->head;
	
	while(trav) {
		
		node *tr = trav;
		while(tr) {
			
			if(tr->name < trav->name) {	// swop if less than
				string temp;
				temp = trav->name;
				trav->name = tr->name;
				tr->name = temp;
			}
			
			tr = tr->next;
		}
		
		trav = trav->next;
	}
	return com;
}