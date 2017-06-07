#ifndef SORTEDLIST_H_INCLUDED
#define SORTEDLIST_H_INCLUDED

#include "Konto.h"

struct SortedList {
    private:
        struct Node {
            Konto k;
            Node* next;

            Node(Konto _k, Node* _next=NULL) {
                k = _k;
                next = _next;
            }
        };

        Node* head;
        unsigned int size;
    public:
        SortedList();
        void insert(Konto& k);
        Konto pop();
        void print() const;
        bool isEmpty() const;
};

#endif // SORTEDLIST_H_INCLUDED
