#ifndef LISTA_H
#define LISTA_H
#include "node.h"
#include "bitacora.h"

template <class T>
class DoubleLinkedList{
    private:
    Node<T>* head;
    Node<T>* tail;
    int itemCount;
    Node<T>* curr;
    Node<T>* temp;
    int contador;

    public:
    DoubleLinkedList();
    Node<T>* getHead();
    Node<T>* getTail();
    Node<T>* getNode(int);
    int getItemCount();
    void addFirst(T);
    void addLast(T);
    T getData(int);
    int findData(T);
    void clean();
    void printList();
    void intercambiar(int,int);
    int partition(int,int);
    void quickSort(int,int);
    void sacarLista(int,int,std::string);
    int binaria(entrada);
};

template<class T>
DoubleLinkedList<T>::DoubleLinkedList(){
    head = NULL;
    tail = NULL;
    curr = NULL;
    temp = NULL;
    contador = 0;
    itemCount = 0;
}


template<class T>
Node<T>* DoubleLinkedList<T>::getHead(){
    return head;
}

template<class T>
Node<T>* DoubleLinkedList<T>::getTail(){
    return tail;
}

template<class T>
Node<T>* DoubleLinkedList<T>::getNode(int n){
    contador ++;
    std::cout<<contador<<std::endl;
    curr = head;
    int mitad = itemCount/2;
    if(n<mitad){
        for(int i = 0; i<n;i++){
        curr = curr->siguiente;
        }
        return curr;
    }
    else{
        curr = tail;
        int regreso = itemCount-n;
        for(int i = 0; i<regreso;i++){
        curr = curr->anterior;
        }
        return curr;
    }
    
}

template<class T>
int DoubleLinkedList<T>::getItemCount(){
    return itemCount;
}

template<class T>
void DoubleLinkedList<T>::addFirst(T d){
    Node<T>* n = new Node<T>(d);
    temp = head;
    if(head != NULL){
        n->siguiente = head;
        head->anterior = n;
        head = n;

    }
    else{
        head = n;
        tail = head;
    }
    itemCount ++;
}

template<class T>
void DoubleLinkedList<T>::addLast(T d){
    Node<T>* n = new Node<T>(d);
    n->siguiente = NULL;

    if(head != NULL){
        curr = head;
        tail->siguiente = n;
        n->anterior = tail;
        tail = n;
    }
    else{
        head = n;
        tail = head;

    }
    itemCount ++;
}



template<class T>
T DoubleLinkedList<T>::getData(int pos){
    if(pos>= itemCount){
        throw std::out_of_range("Noup");
    }
    curr = head;
    for(int i = 0;i<pos;i++){
        curr = curr->siguiente;
    }
    return curr->data;
}


template<class T>
int DoubleLinkedList<T>::findData(T ele){
    curr = head;
    for(int i = 0;i<itemCount;i++){
        if(curr->data == ele){
            return i;
        }
        curr = curr->siguiente;
    }
    return -1;
}

template<class T>
void DoubleLinkedList<T>::clean(){
    curr = head;
    while(curr != NULL ) { 
        Node<T>* next = curr->siguiente; 
        delete curr; 
        curr = next; 
    }
    delete curr;
    head = NULL;
    tail = NULL;
    curr = NULL;
    temp = NULL;
    itemCount = 0;
}

template<class T>
void DoubleLinkedList<T>::printList(){
    curr = head;
    while (curr->siguiente != NULL)
    {
        std::cout<<curr->data<<std::endl;
        curr = curr->siguiente;
    }
    std::cout<<curr->data<<std::endl;
}

template<class T>
void DoubleLinkedList<T>::intercambiar(int i,int j){
    T temporaldata;
    Node<T>* primerNodo;
    Node<T>* segundoNodo;
    primerNodo = getNode(i);
    segundoNodo= getNode(j);

    temporaldata = primerNodo->data;
    primerNodo->data = segundoNodo->data;
    segundoNodo->data = temporaldata;
}

template<class T>
int DoubleLinkedList<T>::partition(int l,int h){
    Node<T>* pivot = getNode(h);
    int i = l-1;
    int j;
    for(j=l;j<=h-1;j++){
        if(getNode(j)->data<=pivot->data){
            i++;
            intercambiar(i,j);
        }
    }
    intercambiar(i+1,h);
    return i+1;
}

template <class T>
void DoubleLinkedList<T>::quickSort(int l, int h){
    int stack[h - l + 1];
  
    int top = -1;
  
    stack[++top] = l;
    stack[++top] = h;
  
    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];
  
        int p = partition(l, h);
  
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}


template<class T> 
void DoubleLinkedList<T>::sacarLista(int in,int fi,std::string nombre){
    std::ofstream outfile (nombre);
    for(int i = in;i<fi+1;i++){
        outfile<<getData(i)<<std::endl;
    }
    outfile.close();
}

template<class T> 
int DoubleLinkedList<T>::binaria(entrada k){
    std::cout<<k<<std::endl;
    int min = 0;
    int max = itemCount-1;
    int mitad;
    while(min<=max){
        mitad = min + (max-min)/2;
        if(k==getData(mitad)){
            return mitad;
        }
        else if(k<getData(mitad)){
            max = mitad -1;
        }
        else{
            min = mitad + 1;
        }
    }
    return -1;
}
#endif