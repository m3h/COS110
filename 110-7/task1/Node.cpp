#include "Node.h"

Node::Node(){
	head = NULL;
}

Node::~Node(){
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

Node::Node(int length, string *value){

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

void Node::display(){
	node *trav = head;
	while(trav){
		cout << trav->name << " ";
		trav = trav->next;
	}
	cout<<endl;
}

//NOTE
// Do NOT change any code above this line
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	
void Node::reverse(){

	int size = 0;
	
	node *trav = head;
	while(trav){
		size++;
		trav = trav->next;
	}
	
	string rev[size];
	
	trav = head;
	for(int i = size - 1; i >= 0; --i) {
		rev[i] = trav->name;
		trav = trav->next;
	}
	
	trav = head;
	for(int i = 0; i < size; ++i) {
		trav->name = rev[i];
		trav = trav->next;
	}
}
