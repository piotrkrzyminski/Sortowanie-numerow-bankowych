#include <iostream>
#include <stdlib.h>
#include "sortedList.h"

/**
* Non-parameter constructor. Set head node to NULL and size of structure to 0
*/
SortedList::SortedList() {
    head=NULL;
    size=0;
}

/**
* Add new Konto to list passed in argument in alphanumeric order
*/
void SortedList::insert(Konto& k) {
    Node* pred=NULL;
    Node* succ=head;

    Node* p=new Node(k);

    if(head==NULL) {
        head=p;
    } else {
        while(succ!=NULL && (succ->k.getBankAccuntNumber()<k.getBankAccuntNumber())) {
            pred=succ;
            succ=succ->next;
        }

        if(p==NULL) throw std::runtime_error("Brak miejsca w pamieci.\n");

        if(pred!=NULL) {
            pred->next=p;
            p->next=succ;
        }

        else {
            p->next=head;
            head=p;
        }
    }

    size++;
}

/**
* Delete and return first number in list
*/
Konto SortedList::pop() {
    Konto k;
    if(head!=NULL) {
        k=head->k;
        head=head->next;
    }

    size--;

    return k;
}


/**
* print list content in standard output
*/
void SortedList::print() const {
    if(size==0) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    Node* walker=head;

    while(walker!=NULL) {
        std::cout<<walker->k.getIBANNumber()<<std::endl;
        walker=walker->next;
    }

    std::cout<<std::endl;
}

/**
* returns true when list is empty
*/
bool SortedList::isEmpty() const {
    if(size==0)
        return true;
    return false;
}
