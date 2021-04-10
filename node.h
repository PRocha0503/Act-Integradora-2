#ifndef NODE_H
#define NODE_H
#include<iostream>

template <class T>
class Node { 
public: 
    T data; 
    Node* siguiente;
    Node* anterior;
    Node();
    Node(T);
}; 

template<class T>
Node<T>::Node(){
    data = 20;
    siguiente = NULL;
    anterior = NULL;
}
template<class T>
Node<T>::Node(T d){
    data = d;

}

#endif