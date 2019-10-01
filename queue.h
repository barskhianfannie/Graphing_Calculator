//
//  queue.h
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef queue_h
#define queue_h
#include <iostream>
#include "linked_list.h"
#include "Iterators.h"

#include <iostream>




template <typename T>
class Queue
{
public:
    class Iterator{
    public:
        friend class Queue;
        Iterator(): list_iterator(){                                            //default ctor
            
        }
        
        
        Iterator(typename List<T>:: Iterator p): list_iterator(p)                    //Point Iterator to where p is
        {
            
        }
        
        
        
        Iterator next()
        {
            return list_iterator.next();
        }
        
        T& operator *()                             //dereference operator // item  RETURN _PTR->_ITEM;
        {
            return *list_iterator;
        }
        
        T* operator ->()                        //address list iterator
        {
            return &*list_iterator;
        }
        
        
        friend bool operator !=(const Iterator& left, const Iterator& right) //true if left != right
        {
            if(left.list_iterator != right.list_iterator)
                return true;
            else
                return false;
        }
        
        friend bool operator ==(const Iterator& left, const Iterator& right) //true if left == right
        {
            if(left.list_iterator == right.list_iterator)
                return true;
            else
                return false;
        }
        
        Iterator& operator++()                              //member operator: ++it; or ++it = new_value
        {
            list_iterator = list_iterator.next();
            return *this;
        }
        
        friend Iterator operator++(Iterator& it, int unused)                //friend operator: it++
        {
            Iterator temp = it;
            it = it.next();
            return temp;
        }
        
    private:
        typename List<T>::Iterator  list_iterator;                         //pointer being encapsulated
    };
    
    Queue():_front(nullptr), _back(nullptr), _size(0) //CTOR
    {
        
    }
    ~Queue();
    Queue(const Queue<T>& other);
    Queue<T> &operator =(const Queue& rhs)
    {
        
        if(this != &rhs)
        {
            delete [] _front;
            clear_list(_front);
            _front = copy_list(rhs._front);       // I need copy_list to return front of the linked list // DONE
            _back = copy_list(rhs._front);
            _size = rhs._size;
        }
        return *this;
    }
    
    void enqueue(const T& item);
    void enqueue(T& item);
    T dequeue(); // takes first person FIFO
    T front(); // returns first item in line
    
    bool isEmpty();
    Iterator Begin() const;
    Iterator End() const;
    
    
    template <typename U>
    friend ostream& operator <<(ostream& outs, const Queue<U>& rhs)
    {
        print_list(rhs._front);
        return outs;
    }
    
private:
    
    node<T>* _front;
    node<T>* _back;
    int _size;
    
    
};

//=======================================================================================
//                  THE REST OF THE BIG THREE
//=======================================================================================
template <typename T>
Queue<T>::~Queue()
{
    
    clear_list(_front);
}

//COPY CONSTRUCTOR
template <typename T>
Queue<T>:: Queue(const Queue<T>& other)
{
    _front = copy_list(other._front);
    _size = other._size;
    _back = last_node(_front);
}

//=======================================================================================
//                  MUTATORS / ACCESSORS FOR QUEUE
//=======================================================================================
template <typename T>
void Queue<T>:: enqueue(const T& item)
{
    _size++;
    _back = insert_after(_front,_back,item);
}

template <typename T>
void Queue<T>:: enqueue(T& item)
{
    _size++;
    _back = insert_after(_front,_back,item);
}

template <typename T>
T Queue<T>:: dequeue()
{
    _size--;
    return delete_head(_front);
}

template <typename T>
T Queue<T>:: front()
{
    return _front->_item;
}

template <typename T>
bool Queue<T>:: isEmpty()
{
    
    return  (_front == nullptr);
}


template <typename T>
typename Queue<T>:: Iterator Queue<T>:: Begin() const
{
    int front = at(_front, 1);
    return Iterator(search_list(_front, front));
}


template <typename T>
typename Queue<T>:: Iterator Queue<T>:: End() const
{
    int back = at(_front, _size);
    return  Iterator(search_list(_front, back));
}



#endif /* queue_h */
