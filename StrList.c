#include "StrList.h"
#include <stdlib.h>
#include <stdio.h>

// Node & List Data Structures
typedef struct _node {
    char* _data;
    struct _node * _next;
} Node;

struct _StrList {
    Node* _head;
    size_t _size;
};


//------------------------------------------------
// Node implementation
//------------------------------------------------

Node* Node_alloc(char* data, Node* next) {
    Node *p = (Node *) malloc(sizeof(Node));
    if (p != NULL) {
        p->_data = data;
        p->_next = next;
    }
    return p;
}

void Node_free(Node* node) {
    if(node!=NULL) {
        free(node);
    }
}
//------------------------------------------------



//------------------------------------------------
// StrList implementation
//------------------------------------------------

StrList* StrList_alloc() {
    StrList* p= (StrList*)malloc(sizeof(StrList));
    p->_head= NULL;
    p->_size= 0;
    return p;
}

void StrList_free(StrList* StrList) {
    if (StrList==NULL) return;
    Node* p1= StrList->_head;
    Node* p2;
    while(p1!=NULL) {
        p2= p1;
        p1= p1->_next;
        Node_free(p2);
    }
    free(StrList);
}

size_t StrList_size(const StrList* StrList) {
    return StrList->_size;
}

Node* getNodeAt(const StrList* StrList, int index){
    if(StrList==NULL || index<0){return NULL;}
    if(StrList->_size<index+1){return NULL}
    Node* p1= StrList->_head;
    if(index==0){return p1;}
    else {
        for (int i = 1; i <= index; i++) {
            p1 = p1->_next;
        }
    }
    return p1;
}


void StrList_insertLast(const StrList* StrList, char* data) {
    Node* newNode= Node_alloc(strdup(data), NULL);
    Node* lastNode= getNodeAt(StrList,(int)StrList->_size-1)
    if(lastNode==NULL){
        StrList->_head = newNode;
    }
    else{
        lastNode->_next=newNode;
    }
    StrList->_size++;
}

char* StrList_firstData(const StrList* StrList) {
    Node *head = StrList->_head;
    if (head == NULL) { return NULL; }
    return head->_data;
}
/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* StrList) {
    Node *p = StrList->_head;
    while (p != NULL) {
        printf("%s", p->_data);
        if (p->_next != NULL) {
            printf(" ");
            p = p->_next;
        }
    }
}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* Strlist,int index) {
    if (Strlist == NULL || index < 0) { return NULL }
    if (index <= (Strlist->_size) - 1) {
        Node *p = getNodeAt(Strlist, index);
        printf(" %s", p->_data);
    }
}
/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* Strlist);

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* StrList, const char* data);

/*
	Given a string and a list, remove all the appearences of this string in the list.
*/
void StrList_remove(StrList* StrList, const char* data);

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* StrList, int index) {
    if (StrList == NULL || index < 0) { return; }
    if (index == 0) {
        StrList->_head = (StrList->_head)->_next;
    }
    if (index - 1 <= StrList->_size) {
        Node *p1 = getNodeAt(StrList, index - 1);
        Node *p2 = getNodeAt(StrList, index + 1);
        Node *t = getNodeAt(StrList, index);
        if (p2 == NULL) {
            p1->_next = NULL;
            Node_free(t);
        } else {
            p1->_next = p2;
            Node_free(t);
        }
    }
}
/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2);

/*
 * Clones the given StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StrList);

/*
 * Reverces the given StrList.
 */
void StrList_reverse( StrList* StrList);

/*
 * Sort the given list in lexicographical order
 */
void StrList_sort( StrList* StrList);

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList);


//------------------------------------------------
