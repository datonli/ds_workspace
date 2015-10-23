#include <iostream>
#include <string>

template <class Elem> 
class Stack{
    public :
        virtual bool push(Elem element) = 0;
        virtual bool pop(Elem& element) = 0;
        virtual bool topValue(Elem& element) = 0;
        virtual int length() const = 0;
};
