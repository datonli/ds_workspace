#include "Stack.h"

template <class Elem>
class AStack : public Stack<Elem>{
    public :
        AStack(int sz)
        {
            listArray = new Elem[sz];
            top = 0;
            size = sz;
        }        
        ~AStack()
        {
            delete [] listArray;
        }
        bool push(Elem element)
        {
            if(top == size)
                return false;
            else
            {
                listArray[top++] = element;
                return true;
            }
        }
        bool pop(Elem& element)
        {
            if(top == 0)
                return false;
            else
            {
                element = listArray[top--];
                return true;
            }
        }
        bool topValue(Elem& element)
        {
            if(top == 0)
                return false;
            else    
            {
                element = listArray[--top];
                return true;
            }
        }
    private :
        int top;
        int size;
        Elem * listArray;
};
