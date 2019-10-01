//
//  stack.h
//  graph_lL
//
//  Created by Fannie Barskhian on 6/8/19.
//  Copyright © 2019 Fannie Barskhian. All rights reserved.
//

#ifndef stack_h
#define stack_h
#include <stdio.h>
#include "Iterators.h"

#include <iostream>


#include <stdio.h>

#include "linked_list.h"

#include <iostream>




template <typename T>
class Stack
{
public:
    class Iterator{
    public:
        friend class Stack;
        Iterator(): list_iterator(){                         //default ctor
            //            if(!DBUG) cout << "STACK ITERATOR DEFAULT CONSTRUCTOR FIRED" << endl;
        }
        
        
        Iterator(typename List<T>:: Iterator p): list_iterator(p)                    //Point Iterator to where p is
        {
            //            if(!DBUG) cout << "STACK ITERATOR CONSTRUCTOR FIRED" << endl;
        }
        
        
        
        Iterator next()
        {
            return list_iterator.next();
        }
        
        T& operator *()                      //dereference operator // item  RETURN _PTR->_ITEM;
        {
            return *(list_iterator);
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
        
        Iterator& operator++()                       //member operator: ++it; or ++it = new_value
        {
            list_iterator = list_iterator.next();
            return *this;
        }
        
        friend Iterator operator++(Iterator& it, int unused)    //friend operator: it++
        {
            Iterator temp = it;
            it = it.next();
            return temp;
        }
        
        template <typename U>
        friend ostream& operator <<(ostream& outs, const List<U>& list)
        {
            print_list(list._head);
            return outs;
        }
        
    private:
        typename List<T>::Iterator  list_iterator;                      //pointer being encapsulated
    };
    
    Stack(){
        //        if(DBUG) cout << "STACK CTOR FIRED " << endl;
    }
    
    void push(const T& item);
    void push(T& item);
    T Pop();
    T Top();
    bool isEmpty();
    Iterator Begin() const;
    Iterator End() const;
    
    
    template <typename U>                      //Note the template arg U
    friend ostream& operator <<(ostream& outs, const Stack<U>& rhs)
    {
        rhs._stack.Print();
        return outs;
    }
    
private:
    
    List<T> _stack;
    
};

template <typename T>
void Stack<T>:: push(const T& item)
{
    _stack.InsertHead(item);
}
template <typename T>
void Stack<T>:: push(T& item)
{
    _stack.InsertHead(item);
}

template <typename T>
T Stack<T>:: Pop()
{
    return _stack.Delete(_stack.Begin());
}

template <typename T>
T Stack<T>:: Top()
{
    return *_stack.Begin();
}


template <typename T>
bool Stack<T>:: isEmpty()
{
    
    return  _stack.Begin().is_null();
}


template <typename T>
typename Stack<T>:: Iterator Stack<T>:: Begin() const
{
    
    return  _stack.Begin();
}


template <typename T>
typename Stack<T>:: Iterator Stack<T>:: End() const
{
    
    return  _stack.LastNode();
}


#endif /* stack_h */
