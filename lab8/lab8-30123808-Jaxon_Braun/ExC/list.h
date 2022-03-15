//list.h
//ENSF 337Lab 8 Exercise C
//Created by: Jaxon Braun

#ifndef LIST_H
#define LIST_H

struct ListItem   //struct to hold data at each node in linked list
{
    int year;
    double flow;
};

struct Node             //node used to store every element of struct ListItem in linked list
{
    ListItem item;
    Node *next;
};

class FlowList{
public:
    int record_count;
    Node *ptr;
    FlowList(); // PROMISES: Creates empty list.

    void insert(const struct ListItem& itemA);
    // PROMISES:
    //    A node with a copy of itemA is added in 
    //    a way that preserves the nondecreasing 
    //    order of items in nodes.

    void remove(const struct ListItem& itemA);
    //  PROMISES:
    //    If no node has an item matching itemA, 
    //    list is unchanged.
    //    Otherwise exactly one node with 
    //    its item == itemA is removed.

    void print() const;  
    // PROMISES:
    //  Prints data in table format without headers

    int sum();
    // PROMISES:
    //  Calculates and returns the sum of the flow data

    int searchForYear(ListItem& itemA);
    // PROMISES:
    //  Returns 1 if year in argument exits in FlowList, 0 otherwise

private:
    Node *headM;
};



#endif
