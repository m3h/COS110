#include <iostream>

#include "xAxis.h"

xAxis::xAxis()
{
    head = NULL;
}

xAxis::xAxis(int length, string* n, double* v)
{

    head = NULL;

    for(int i = 0; i < length; ++i) {
        extend( v[i], n[i]);
    }
}

xAxis::~xAxis()
{
    node *nodePtr;
    node *nextNode;

    nodePtr = head;

    while(nodePtr != NULL) {

        nextNode = nodePtr->next;

        delete nodePtr;

        nodePtr = nextNode;
    }
}

void xAxis::extend(double v, string n)
{
    node *newNode;
    node *nodePtr;

    
    newNode = new node;

    v > 0 ? newNode->value = v: newNode->value = 0;
    newNode->label = n;
    newNode->next = NULL;

    if(!head)
        head = newNode;
    else {
        nodePtr = head;

        while(nodePtr->next)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }

}

void xAxis::shorten()
{
    node *nodePtr;

    if(!head)
        return;
    else {
        nodePtr = head;

<<<<<<< HEAD
=======
        if(!head->next) // delete head
        {
          delete head;
          head = NULL;
          return;
        }
>>>>>>> 5b26b6ac896b8192a8bb08c50a64ba3bc7f83776
        while(nodePtr->next->next)
            nodePtr = nodePtr->next;

        delete nodePtr->next->next;
        nodePtr->next = NULL;
    }
}

void xAxis::deleteNode(string n)
{
    node *nodePtr;
    node *previousNode;

    if(!head)
        return;

    if( head->label == n) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {

        nodePtr = head;

        while(nodePtr != NULL && nodePtr->label != n) {

            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(nodePtr) {

            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }

}

void xAxis::increaseValueBy(string n,double val)
{
    node *nodePtr;

    if(!head)
        return;

    if( head->label == n)
        head->value += val;
    else {

        nodePtr = head;

        while(nodePtr != NULL) {
            if( nodePtr->label == n)
                nodePtr->value += val;
            nodePtr = nodePtr->next;
        }
    }
}

void xAxis::decreaseValueBy(string n,double val)
{
    node *nodePtr;

    if(!head)
        return;

    if( head->label == n)
        head->value > val ? head->value -= val: head->value = 0;
    else {

        nodePtr = head;

        while(nodePtr != NULL) {
            if( nodePtr ->label == n)
                nodePtr->value > val ? nodePtr->value -= val: nodePtr->value = 0;
            nodePtr = nodePtr->next;

        }
    }
}

void xAxis::changeLabel(string o,string n)
{
    node *nodePtr;

    if(!head)
        return;

    if( head->label == o)
        head->label = n;
    else {

        nodePtr = head;

        while( nodePtr != NULL) {
            if( nodePtr->label == o)
                nodePtr->label = n;
            nodePtr = nodePtr->next;
        }
    }
}

void xAxis::display()
{
    node *nodePtr;

    nodePtr = head;

    while( nodePtr ) {

        cout << nodePtr->label << "\t" << nodePtr->value << endl;

        nodePtr = nodePtr->next;

    }
}
