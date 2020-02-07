/*
ESERCIZIO. 

Definire un template di classe dList<T> i cui oggetti rappresentano una struttura dati lista doppiamente concatenata (doubly linked list) per elementi di uno stesso tipo T. Il template dList<T> deve soddisfare i seguenti vincoli:

1. Gestione della memoria senza condivisione.

2. dList<T> rende disponibile un costruttore dList(unsigned int k, const T& t) che costruisce una 
lista contenente k nodi ed ognuno di questi nodi memorizza una copia di t.

3. dList<T> permette l’inserimento in testa ed in coda ad una lista in tempo O(1) (cioe` costante):
-- Deve essere disponibile un metodo void insertFront(const T&) con il seguente comportamento: dl.insertFront(t) inserisce l’elemento t in testa a dl in tempo O(1).
-- Deve essere disponibile un metodo void insertBack(const T&) con il seguente comportamento: dl.insertBack(t) inserisce l’elemento t in coda a dl in tempo O(1).

4. dList<T> rende disponibile un opportuno overloading di operator< che implementa l’ordinamento lessicografico (ad esempio, si ricorda che per l'ordinamento lessicografico tra stringhe abbiamo che "campana" < "cavolo" e che
"eccellente" < "ottimo").

5. dList<T> rende disponibile un tipo iteratore costante dList<T>::constiterator i cui oggetti permettono di iterare sugli elementi di una lista.
*/

#include<iostream>

template<class T>
class dList {
private:
  class nodo {
  public:
    T info;
    nodo *prev, *next;
    nodo(const T& t = T(), nodo* p=nullptr, nodo* n=nullptr):
      info(t), prev(p), next(n) {}
    ~nodo() {delete next;}
  };
  nodo *last, *first; // lista vuota iff first==last==nullptr

  static nodo* copy(nodo* p, nodo*& l){
    if(p==nullptr) return l=nullptr;
    nodo* prec=new nodo(p->info,nullptr,nullptr);
    nodo* succ=prec;;
    nodo* start=prec;
    while(p->next!=nullptr) {
      succ = new nodo(p->next->info,prec,nullptr);
      prec->next=succ;
      p=p->next;
      prec=prec->next;
    }
    l=succ;
    return start;
  }

  /* possibile versione ricorsiva
  static nodo* copy(nodo* p, nodo* pre, nodo*& l) {
    if(p == nullptr) return p = nullptr;
    // p != nullptr
    nodo* temp = new nodo(p->info,pre,nullptr);
    temp->next = copy(p->next,temp,l);
    if(p->next == nullptr) l=temp;
    return temp;
  }
  */

  static bool isLess(nodo* d1, nodo* d2) {
    if(d2==nullptr) return false;
    // d2 NON e' vuota
    if(d1==nullptr) return true;
    // d1 e d2 NON vuote
    return d1->info < d2->info || 
      (d1->info==d2->info && isLess(d1->next,d2->next));
  }

public:
  ~dList() {delete first;}
  dList(const dList& d): first(copy(d.first,last)) {
    // first=copy(d.first,last);
  }
   
  dList& operator=(const dList& d) {
    if(this != &d) {
      delete first;
      first=copy(d.first,last);
    }
    return *this;
  }

  void insertFront(const T& t) {
    first = new nodo(t,nullptr,first);
    if(first->next==nullptr) {
      // lista di invocazione era vuota
      last=first;
    }
    else {
      // lista di invocazione NON era vuota
      (first->next)->prev=first;
    }
  }

  void insertBack(const T& t) {
    last = new nodo(t,last,nullptr);
    if(last->prev==nullptr) {
      // lista di invocazione era vuota
      first=last;
    }
    else {
      // lista di invocazione NON era vuota
      (last->prev)->next=last;
    }
  }

  dList(unsigned int k, const T& t): last(nullptr), first(nullptr) {
    for(unsigned int i=0; i<k; ++i) 
      insertFront(t);
  }

  bool operator<(const dList& d) const {
    return isLess(first,d.first);
  }
  
  class constiterator {
    friend class dList<T>;
  private:
    nodo* ptr;
    bool pastTheEnd; // true iff constiterator e' "past-the-end"
    // conversione nodo* => constiterator
    constiterator(nodo* p, bool pte=false): ptr(p), pastTheEnd(pte) {}
  public:
    constiterator(): ptr(nullptr), pastTheEnd(false) {}

    const T& operator*() const {
      return ptr->info;
    }
    
    const T* operator->() const {
      return &(ptr->info);
    }
    
    constiterator& operator++() {
      if(ptr!= nullptr) {
	if(!pastTheEnd) { 
	  if(ptr->next==nullptr) {++ptr; pastTheEnd=true;}
	  else {ptr=ptr->next;}
	}
      }
      return *this;
    }
    
    constiterator& operator--() {
      if(ptr!=nullptr) {
	if(pastTheEnd) {--ptr; pastTheEnd=false;}
	else ptr=ptr->prev;
      }
      return *this;
    }
    
    bool operator==(const constiterator& x) const {
      return ptr==x.ptr;
    }

    bool operator!=(const constiterator& x) const {
      return ptr!=x.ptr;
    }
  };

  constiterator begin() const {
    return first;
  }
  
  constiterator end() const {
    if(last==nullptr) return nullptr;
    return constiterator(last+1,true);
  }
};


// esempio d'uso
int main() {
  dList<int> x(4,2), y(0,0), z(6,8);
  y=x;
  x.insertFront(-2); z.insertFront(3); y.insertFront(0);
  if(x<y) std::cout << "x < y" << std::endl;
  if(z<x) std::cout << "z < x" << std::endl;
  if(y<z) std::cout << "y < z" << std::endl;
  if(z<y) std::cout << "z < y" << std::endl;

  std::cout << "x= ";
  dList<int>::constiterator j = --(x.end());
  for(; j != x.begin(); --j) std::cout << *j << ' '; 
  std::cout << *j << std::endl << "y= ";
  for(dList<int>::constiterator k = y.begin(); k != y.end(); ++k) std::cout << *k << ' ';  
  std::cout << std::endl << "z= ";
  dList<int>::constiterator i = z.begin(); 
  for( ; i != z.end(); ++i) std::cout << *i << ' ';  
  std::cout << std::endl;
}
