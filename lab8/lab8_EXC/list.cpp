//list.cpp
//ENSF 337 Lab 8 Exercise C
//Creathed by: Jaxon Braun

#include <stdlib.h>
#include <iostream>
using namespace std;
#include "list.h"

FlowList::FlowList() //initiales empty linked list
: headM(0), ptr(0), record_count(0)
{
}

void FlowList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;    //Creating the new node from given data itemA
    new_node->item.year = itemA.year;
    new_node->item.flow = itemA.flow;
    
    if (headM == 0 || itemA.year <= headM->item.year ) { //checks if new node should go in first position
        new_node->next = headM;
        headM = new_node;
        ptr = headM;
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA.year > after->item.year) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;  //moves pointers to correct positions to finalize the insertion    
    }
    record_count += 1;
}

void FlowList::remove(const ListItem& itemA)
{
    // if list is empty, do nothing
    if (headM == 0 || itemA.year < headM->item.year)
        return;
    
    Node *doomed_node = 0;
    
    if (itemA.year == headM->item.year) { //checks if node to be deleted is the first one
        doomed_node = headM;
        headM = headM->next;
        ptr = headM;
    }
    else {                              //searches for the node to be removed from the list
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA.year > maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        doomed_node = maybe_doomed;
        before->next = maybe_doomed->next;
        delete doomed_node; 
    }
    record_count -= 1;
}

void FlowList::print() const  
{
    if (headM != 0) {
        cout << headM->item.year << "\t" << headM->item.flow << endl;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << p->item.year << "\t" << p->item.flow << endl;
    }
}

int FlowList::sum()
{
    int sum = 0;
    if (headM != 0){
        sum += headM->item.flow;
        for (const Node *p = headM->next; p != 0; p = p->next)
            sum += p->item.flow;
    }
    return sum;
}

int FlowList::searchForYear(ListItem& itemA)
{
    if (headM->item.year == itemA.year)
            return 1;
    else{
        for (const Node *p = headM->next; p != 0; p = p->next){
        if (headM->item.year == itemA.year)
            return 1;
        if (p->item.year == itemA.year)
            return 1;
        }
    }
    return 0;
}

