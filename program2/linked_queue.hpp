// Submitter: haitaoy(Ye, Haitao)
// Partner  : burnscr(Burns, Connor)
// We certify that we worked cooperatively on this programming
//   assignment, according to the rules for pair programming
#ifndef LINKED_QUEUE_HPP_
#define LINKED_QUEUE_HPP_

#include <string>
#include <iostream>
#include <sstream>
#include <initializer_list>
#include "ics_exceptions.hpp"


namespace ics {


template<class T> class LinkedQueue {
  public:
    //Destructor/Constructors
    ~LinkedQueue();

    LinkedQueue          ();
    LinkedQueue          (const LinkedQueue<T>& to_copy);
    explicit LinkedQueue (const std::initializer_list<T>& il);

    //Iterable class must support "for-each" loop: .begin()/.end() and prefix ++ on returned result
    template <class Iterable>
    explicit LinkedQueue (const Iterable& i);


    //Queries
    bool empty      () const;
    int  size       () const;
    T&   peek       () const;
    std::string str () const; //supplies useful debugging information; contrast to operator <<


    //Commands
    int  enqueue (const T& element);
    T    dequeue ();
    void clear   ();

    //Iterable class must support "for-each" loop: .begin()/.end() and prefix ++ on returned result
    template <class Iterable>
    int enqueue_all (const Iterable& i);


    //Operators
    LinkedQueue<T>& operator = (const LinkedQueue<T>& rhs);
    bool operator == (const LinkedQueue<T>& rhs) const;
    bool operator != (const LinkedQueue<T>& rhs) const;

    template<class T2>
    friend std::ostream& operator << (std::ostream& outs, const LinkedQueue<T2>& q);



  private:
    class LN;

  public:
    class Iterator {
      public:
        //Private constructor called in begin/end, which are friends of LinkedQueue<T>
        ~Iterator();
        T           erase();
        std::string str  () const;
        LinkedQueue<T>::Iterator& operator ++ ();
        LinkedQueue<T>::Iterator  operator ++ (int);
        bool operator == (const LinkedQueue<T>::Iterator& rhs) const;
        bool operator != (const LinkedQueue<T>::Iterator& rhs) const;
        T& operator *  () const;
        T* operator -> () const;
        friend std::ostream& operator << (std::ostream& outs, const LinkedQueue<T>::Iterator& i) {
          outs << i.str(); //Use the same meaning as the debugging .str() method
          return outs;
        }
        friend Iterator LinkedQueue<T>::begin () const;
        friend Iterator LinkedQueue<T>::end   () const;

      private:
        //If can_erase is false, current indexes the "next" value (must ++ to reach it)
        LN*             prev = nullptr;  //if nullptr, current at front of list
        LN*             current;         //current == prev->next (if prev != nullptr)
        LinkedQueue<T>* ref_queue;
        int             expected_mod_count;
        bool            can_erase = true;

        //Called in friends begin/end
        Iterator(LinkedQueue<T>* iterate_over, LN* initial);
    };


    Iterator begin () const;
    Iterator end   () const;


  private:
    class LN {
      public:
        LN ()                      {}
        LN (const LN& ln)          : value(ln.value), next(ln.next){}
        LN (T v,  LN* n = nullptr) : value(v), next(n){}

        T   value;
        LN* next = nullptr;
    };


    LN* front     =  nullptr;
    LN* rear      =  nullptr;
    int used      =  0;            //Cache the count of nodes in the linked list
    int mod_count =  0;            //Allows the sensing of concurrent modification

    //Helper methods
    void delete_list(LN*& front);  //Deallocate all LNs, and set front's argument to nullptr;
};





////////////////////////////////////////////////////////////////////////////////
//
//LinkedQueue class and related definitions

//Destructor/Constructors

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
    delete_list(front);
}


template<class T>
LinkedQueue<T>::LinkedQueue()
{
}


template<class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& to_copy):
front(to_copy.front), rear(to_copy.rear), used(to_copy.used), mod_count(to_copy.mod_count)
{
}


template<class T>
LinkedQueue<T>::LinkedQueue(const std::initializer_list<T>& il)
{
    for (const T& q_elem : il)
        enqueue(q_elem);
}


template<class T>
template<class Iterable>
LinkedQueue<T>::LinkedQueue(const Iterable& i)
{
    for (const T& elem: i)
    {
        enqueue(elem);
    }
}


////////////////////////////////////////////////////////////////////////////////
//
//Queries

template<class T>
bool LinkedQueue<T>::empty() const
{
    return (front == nullptr);
}


template<class T>
int LinkedQueue<T>::size() const
{
    return used;
}


template<class T>
T& LinkedQueue<T>::peek () const
{
    if (this->empty())
        throw EmptyError("LinkedQueue::dequeue");

    return front->value;
}


template<class T>
std::string LinkedQueue<T>::str() const
{
    std::ostringstream answer;
    LN* p = front;
    answer << "LinkedQueue[";


    for (; p != rear; p = p->next)
    {
        answer << p->value << "->";
    }

    answer << rear->value << "]" ;
    answer << "(used=" << used << ",front=" << front << ",rear=" << rear << ",mod_count=" << mod_count << ")";
    return answer.str();
}


////////////////////////////////////////////////////////////////////////////////
//
//Commands

template<class T>
int LinkedQueue<T>::enqueue(const T& element)
{
    LN* p = new LN;
    p->value = element;
    if(front == nullptr)
    {
        front = p;
        rear = p;
    }
    else
    {
        rear->next = p;
        rear = p;

    }

    used++;
    mod_count++;
    return 1;
}


template<class T>
T LinkedQueue<T>::dequeue()
{
    if (this->empty())
        throw EmptyError("LinkedQueue::dequeue");

    LN* p = front;
    front = front ->next;
    ++mod_count;
    --used;
    return p->value;
}


template<class T>
void LinkedQueue<T>::clear()
{
    LN* p = front;
    front = rear = nullptr;
    delete_list(p);
    ++mod_count;
    used = 0;
}


template<class T>
template<class Iterable>
int LinkedQueue<T>::enqueue_all(const Iterable& i)
{
    int count = 0;
    for (const T& v : i) {
        count += enqueue(v);
    }
    return count;
}


////////////////////////////////////////////////////////////////////////////////
//
//Operators

template<class T>
LinkedQueue<T>& LinkedQueue<T>::operator = (const LinkedQueue<T>& rhs)
{
    if (this == &rhs)
        {return *this;}

    LN* p1 = this->front;
    LN* p2 = rhs.front;
    if (this->empty())
    {
        enqueue_all(rhs);
    }

    else if (rhs.size() == this->size())
    {
        while (p1 != nullptr)
        {
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    else if (rhs.size() < this->size())
    {
        while (p2->next != nullptr)
        {
            p1->value = p2->value;
            p1 = p1->next;
            p2 = p2->next;
        }
        delete_list(p1->next);
        p1->next = nullptr;
    }

    this->used = rhs.used;
    ++mod_count;
    return *this;
}


template<class T>
bool LinkedQueue<T>::operator == (const LinkedQueue<T>& rhs) const
{
    int used = this->size();
    if (used != rhs.size())
        return false;

    Iterator itor = this->begin();
    Iterator ritor = rhs.begin();
    while (itor != this->end())
    {
        if(*itor != *ritor)
            return false;
        itor++;
        ritor++;
    }
    return true;
}


template<class T>
bool LinkedQueue<T>::operator != (const LinkedQueue<T>& rhs) const {
    int used = this->size();
    if (used != rhs.size())
        return true;

    Iterator itor = this->begin();
    Iterator ritor = rhs.begin();
    while (itor != this->end())
    {
        if(*itor != *ritor)
            return true;
        itor++;
        ritor++;
    }
    return false;
}


template<class T>
std::ostream& operator << (std::ostream& outs, const LinkedQueue<T>& q)
{
    outs << "queue[";

    if (!q.empty()) {
        outs << q.front->value;
        for (typename LinkedQueue<T>::LN* p = q.front->next; p != nullptr; p = p->next)
            outs << "," << p->value;
    }

    outs << "]:rear";
    return outs;
}


////////////////////////////////////////////////////////////////////////////////
//
//Iterator constructors

template<class T>
auto LinkedQueue<T>::begin () const -> LinkedQueue<T>::Iterator
{
    return Iterator(const_cast<LinkedQueue<T>*>(this), front);
}

template<class T>
auto LinkedQueue<T>::end () const -> LinkedQueue<T>::Iterator
{
    return Iterator(const_cast<LinkedQueue<T>*>(this), nullptr);
}


////////////////////////////////////////////////////////////////////////////////
//
//Private helper methods

template<class T>
void LinkedQueue<T>::delete_list(LN*& front)
{
    while(front != nullptr)
    {
        LN* d = front;
        front = front->next;
        delete(d);
    }
}



////////////////////////////////////////////////////////////////////////////////
//
//Iterator class definitions

template<class T>
LinkedQueue<T>::Iterator::Iterator(LinkedQueue<T>* iterate_over, LN* initial)
:ref_queue(iterate_over), current(initial), expected_mod_count(ref_queue->mod_count)
{
}


template<class T>
LinkedQueue<T>::Iterator::~Iterator()
{}


template<class T>
T LinkedQueue<T>::Iterator::erase() {
    if (expected_mod_count != ref_queue->mod_count)
        throw ConcurrentModificationError("LinkedQueue::Iterator::erase");

    if (current == nullptr) {
        throw CannotEraseError("LinkedQueue::Iterator::erase Iterator cursor beyond data structure");
    }

    if(can_erase)
    {
        can_erase = false;
        LN* i = current;

        current = current ->next;
        if(current == nullptr)
        {
            ref_queue->rear = prev;
        }

        if(prev != nullptr)
        {
            prev->next = current;
        }
        else
        {
            ref_queue->front = current;
        }
        T val = i->value;
        delete(i);

        --ref_queue->used;
        ++ref_queue->mod_count;
        expected_mod_count = ref_queue->mod_count;

        return  val;
    } else
    {
        throw CannotEraseError("LinkedQueue::Iterator::erase Iterator cursor already erased");
    }
}


template<class T>
std::string LinkedQueue<T>::Iterator::str() const {
    std::ostringstream answer;
    answer << ref_queue->str() << "(current=" << current << ",expected_mod_count=" << expected_mod_count << ",can_erase=" << can_erase << ")";
    return answer.str();
}


template<class T>
auto LinkedQueue<T>::Iterator::operator ++ () -> LinkedQueue<T>::Iterator&
{
    if (expected_mod_count != ref_queue->mod_count)
        throw ConcurrentModificationError("LinkedQueue::Iterator::operator ++");

    if(can_erase)
    {
        if (current == ref_queue->rear) {
            current = nullptr;
            return *this;
        }
        if(prev == nullptr){
            prev = current;
        }else{
            prev = prev->next;
        }
        current = current ->next;
    }
    else
    {
        can_erase = true;
    }
    return *this;
}


template<class T>
auto LinkedQueue<T>::Iterator::operator ++ (int) -> LinkedQueue<T>::Iterator {
    if (expected_mod_count != ref_queue->mod_count)
        throw ConcurrentModificationError("LinkedQueue::Iterator::operator ++");
    Iterator to_return(*this);

    if (current == ref_queue->rear) {
        current = nullptr;
        return to_return;
    }


    if(can_erase)
    {
        prev = current;
        current = current ->next;
    }
    else
    {
        can_erase = true;
    }

    return to_return;
}


template<class T>
bool LinkedQueue<T>::Iterator::operator == (const LinkedQueue<T>::Iterator& rhs) const
{
    const Iterator* rhsASI = dynamic_cast<const Iterator*>(&rhs);
    if (rhsASI == nullptr)
        throw IteratorTypeError("LinkedQueue::Iterator::operator ==");
    if (expected_mod_count != ref_queue->mod_count)
        throw ConcurrentModificationError("LinkedQueue::Iterator::operator ==");
    if (ref_queue != rhsASI->ref_queue)
        throw ComparingDifferentIteratorsError("LinkedQueue::Iterator::operator ==");

    return current == rhsASI->current;
}


template<class T>
bool LinkedQueue<T>::Iterator::operator != (const LinkedQueue<T>::Iterator& rhs) const
{
    const Iterator* rhsASI = dynamic_cast<const Iterator*>(&rhs);
    if (rhsASI == nullptr)
        throw IteratorTypeError("LinkedyQueue::Iterator::operator !=");
    if (expected_mod_count != ref_queue->mod_count)
        throw ConcurrentModificationError("LinkedQueue::Iterator::operator !=");
    if (ref_queue != rhsASI->ref_queue)
        throw ComparingDifferentIteratorsError("LinkedQueue::Iterator::operator !=");
    return current != rhsASI->current;
}


template<class T>
T& LinkedQueue<T>::Iterator::operator *() const {
    if (expected_mod_count != ref_queue->mod_count)
        throw ConcurrentModificationError("LinkedQueue::Iterator::operator *");
    if (!can_erase || current == nullptr) {
        std::ostringstream where;
        where << current
              << " when front = " << ref_queue->front
              << " and rear = " << ref_queue->rear;
        throw IteratorPositionIllegal("LinkedQueue::Iterator::operator * Iterator illegal: "+where.str());
    }

    return current->value;
}


template<class T>
T* LinkedQueue<T>::Iterator::operator ->() const {
    if (expected_mod_count != ref_queue->mod_count)
        throw ConcurrentModificationError("LinkedyQueue::Iterator::operator ->");
    if (!can_erase || current == nullptr) {
        std::ostringstream where;
        where << current
              << " when front = " << ref_queue->front
              << " and rear = " << ref_queue->rear;
        throw IteratorPositionIllegal("LinkedQueue::Iterator::operator -> Iterator illegal: "+where.str());
    }

    return &current->value;
}


}

#endif /* LINKED_QUEUE_HPP_ */
