//
//  linked_list.h
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h
#include <iostream>
#include <cstdlib>
using namespace std;



template <class T>
struct node{
    node(): _next(nullptr){};
    
    
    node(T item=T(), node<T>* next = nullptr):_item(item), _next(next){
        //node constructor
    }
    friend ostream& operator <<(ostream& outs, const node<T>& print_me){
        if(print_me._next == nullptr)
        {
            outs << " " << print_me._item  << endl;
        }else{
            outs<<" "<<print_me._item<<"  ";
        }
        
        return outs;
    }
    
    
    
    T _item;
    node<T>* _next;
    
};

//======================================================================
template <typename T>
node<T>* search_list(node<T>* head, T key);                                     //return ptr to key or NULL if not found
template<typename T>
node<T>* insert_head(node<T>* &head_ptr, const T& item);                             //insert at the head of list
template <typename T>
node<T>* insert_after(node<T>*& head, node<T> *after_this, T insert_this);        //insert after ptr
template <typename T>
void print_list(node<T>* head_ptr, ostream& outs=cout);
template <typename T>
node<T>* insert_before(node<T>*& head,node<T>* before_this,T insert_this);        //insert before ptr
template <typename T>
node<T>* where_this_goes(node<T>* head, T item, bool ascending=true);             //node after which this item goes order
template <typename T>
node<T>* previous_node(node<T>* head, node<T>* prev_to_this);                   //ptr to previous node
template <typename T>
node<T>* last_node(node<T>* head);
template <typename T>
T delete_node(node<T>*& head, node<T>* delete_this);                            //delete, return item
template <typename T>
void clear_list(node<T>*& head);                                                   // delete all of the nodes
template <typename T>
T& at(node<T>* head, int pos);                                                  //_item at this position
template <typename T>
node<T>* copy_list(node<T>* head);                                              //duplicate the list...
template <typename T>
node<T>* insert_sorted(node<T>* &head, T item, bool ascending=true);            //insert into sorted list
template <typename T>
node<T>* insert_sorted_and_add(node<T>* &head, T item, bool ascending=true);
template <typename T>
T delete_head(node<T>* &head);//insert or add if a dup

//======================================================================

//Linked List General Functions:




template <typename T>
void print_list(node<T>* head_ptr, ostream& outs)
{
    node<T>* walker = head_ptr;
    while (walker!=NULL){
        outs<<*walker;
        walker = walker->_next;
    }
    outs<<endl;
}



template <typename T>
node<T>* search_list(node<T>* head, T key)
{
    node<T>* walker = head;
    
    while(walker !=nullptr)
    {
        if(walker->_item == key)
        {
            return walker;
        }else{
            walker = walker ->_next;
        }
    }
    return nullptr;
}


template<typename T>
node<T>* insert_head(node<T>* &head_ptr, const T& item)
{
    node<T>* temp = new node<T>(item);
    temp->_next = head_ptr;
    head_ptr = temp;
    
    return temp;
    
}


template <typename T>
node<T>* insert_after(node<T>*& head, node<T> *after_this, T insert_this)
{
    node<T>* temp = new node<T>(insert_this);
    
    if(head == nullptr)
        head = temp;
    else if(after_this == nullptr)
    {
        temp->_next = head->_next;
        head->_next = temp;
    }
    else
    {
        temp->_next = after_this->_next;
        after_this->_next = temp;
    }
    
    return temp;
}


template <typename T>
node<T>* insert_before(node<T>*& head,node<T>* before_this,T insert_this)
{
    node<T>* temp = new node<T>(insert_this);
    node<T>* marker = head;
    int count = 0;
    
    
    
    while(marker != before_this)
    {
        if(marker->_next == NULL) return marker;
        marker = marker->_next;
        count++;
    }
    
    if(marker == before_this){
        node<T>*walker = head;
        for(int i = 0; i < count - 1; i++)
        {
            walker = walker->_next;
        }
        temp->_next = walker->_next;
        walker->_next = temp;
        return temp;
    }else{
        return NULL;
    }
}


template <typename T>
node<T>* previous_node(node<T>* head, node<T>* prev_to_this)
{
    node<T>* marker = head;
    int count = 0;
    
    while(marker != prev_to_this)
    {
        if(marker->_next == NULL) return marker;
        marker = marker->_next;
        count++;
    }
    
    node<T>* previous = head;
    for(int i = 0; i < count-1; i++)
    {
        previous = previous->_next;
    }
    return previous;
}


template <typename T>
T delete_node(node<T>*& head, node<T>* delete_this)
{
    //    assert(head != NULL);
    
    node<T>* temp = previous_node(head, delete_this);
    T deleted_item = delete_this->_item;
    if(head == delete_this)
    {
        return delete_head(head);
    }else{
        temp->_next = delete_this->_next;
    }
    delete delete_this;
    return deleted_item;
}

template <typename T>
T delete_head(node<T>* &head)
{
    assert(head != NULL);

    node<T>* temp = NULL;
    T item = head->_item;
    temp = head->_next;
    delete head;
    head = temp;
    return item;
    
}



template <typename T>
void clear_list(node<T>*& head)
{
    node<T>* walker;
    while(head != nullptr)
    {
        walker = head;
        head = walker->_next;
        delete walker;
    }
    head = nullptr;
}

template <typename T>
T& at(node<T>* head, int pos)
{
    for(int i = 1; i < pos; i++)               // start at one so the position index doesnt get confusing
    {
        if(head->_next == NULL || pos == 0)
        {
            cout << "This position doesn't exist" << endl;
            break;
        }
        else if(head != NULL)
        {
            head = head->_next;
        }
    }
    return head->_item;
    
}

template <typename T>
node<T>* copy_list(node<T>* head)
{
    node<T>* walker = head;
    node<T>* copy = new node<T>(walker->_item);
    node<T>* temp = copy;
    walker = walker->_next;
    while(walker != NULL){
        temp = insert_after (copy, temp, walker->_item);
        walker = walker->_next;
    }
    //added
    return copy;
}




template <typename T>
node<T>* insert_sorted(node<T>* &head, T item, bool ascending)
{
    /** Will raise exception if the list has the number we have
     ** so that we use insert sorted and add function instead
     **/
    assert(search_list(head, item) == NULL); // MAKE SURE THERE ISNT SAME ITEM IN THERE
    node<T>* insertion = where_this_goes(head, item, ascending);
    if( insertion == NULL)
        return insert_head(head, item);
    else
        return insert_after(head, insertion, item);
    
}



template <typename T>
node<T>* insert_sorted_and_add(node<T>* &head, T item, bool ascending)  //insert or add if a dup
{
    node<T>*found = search_list(head, item);
    if(found == NULL){
        node<T>* insertion = insert_sorted(head, item, ascending);
        return insertion;
    }else{
        found->_item += item;
    }
    return found; // check this sheit
}


template <typename T>
node<T>* where_this_goes(node<T>* head, T item, bool ascending)
{
    
    node<T>* walker = head;
    if(walker->_next == NULL && ascending == false)
    {
        if(head->_item > item)
        {
            return walker;
        }else if(head->_item < item)
        {
            return NULL;
        }
    }else if(walker->_next == NULL && ascending == true)
    {
        if(head->_item < item)
        {
            return walker;
        }else if(head->_item > item)
        {
            return NULL;
        }
    }
    
    while(ascending)
    {
        while(walker != NULL)
        {
            if(walker->_item < item && walker->_next == NULL)
            {
                ascending = false;
                return walker;
            }
            if(walker->_item > item)
                return previous_node(head, walker);
            else
                
                walker = walker->_next;
        }
        return walker;
    }
    
    
    while(!ascending)
    {
        while(walker != NULL)
        {
            if(walker->_item > item && walker->_next == NULL)
            {
                ascending = true;
                return walker;
            }
            if(walker->_item < item)
            {
                return previous_node(head, walker);
            }else{
                walker = walker->_next;
            }
            
            if(walker->_item == item) ascending = false;
        }
    }
    
    return walker;
    
    
}


template <typename T>
node<T>* last_node(node<T>* head)
{
    node<T>* marker = head;

    
    while(marker->_next !=NULL)
    {
        
        marker = marker -> _next;
    }
    
    if(marker->_next == NULL)
    {
        return marker;
    }
    //TESTING WORKS
    clear_list(head);
    return marker;
}


#endif /* linked_list_h */
