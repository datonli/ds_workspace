#include <iostream>
#include <string>

template <class Elem>
class Queue{
    public :
        virtual void clear() = 0;
        virtual bool enqueue(const Elem& it) = 0;
        virtual bool dequeue(Elem& it) = 0;
        virtual bool frontValue(Elem& it) const = 0;
        virtual int length() const = 0;
};

