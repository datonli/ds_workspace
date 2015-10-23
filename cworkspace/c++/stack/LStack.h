#include "Stack.h"
#include "../list/Link.h"

template <class Elem>
class LStack : public Stack<Elem>{
    public :
        LStack()
        {
            size = 0;
            top = NULL;
        }
        ~LStack()
        {
            clear();
        }
        void clear()
        {
            while(top != NULL)
            {
               Link<Elem> * temp = top;
               top = top->next;
               delete temp;
            }
            size = 0;
        }
        bool push(Elem& element)
        {
            Link<Elem> * newElem = new Link<Elem>(element);
            if(newElem == NULL)
                return false;
            newElem->next = top;
            top = newElem;
            size++;
            return true;
        }

        bool pop(Elem& element)
        {
            Link<Elem> * delElem = top;
            if(top != NULL)
            {
                top = top->next;
                element = delElem->element;
                delete delElem;
                size--;
                return true;
            }
            else
            {
                return false;
            }
        }
        
        bool topValue(Elem& element)
        {
            if(top == NULL)
                return false;
            element = top->element;
            return true;
        }

        int length() const
        {
            return size;
        }

    private :
        Link<Elem> * top;
        int size;
};
