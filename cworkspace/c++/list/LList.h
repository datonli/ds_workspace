#include "List.h"
#include "Link.h"

template <class Elem>
class LList:public List<Elem>{
    private:
        Link<Elem> * head;
        Link<Elem> * tail;
        Link<Elem> * fence;
        int leftcnt,rightcnt,listsize;

    public :
        LList()
        {
            head = tail = fence = NULL;
            leftcnt = rightcnt = 0;
            listsize = 0;
        }

        ~LList()
        {
            while(head != NULL)
            {
                fence = head;
                head = head->next;
                delete fence;
            }
            leftcnt = rightcnt = 0;
        }

        void clear()
        {
            head = tail = fence = NULL;
            leftcnt = rightcnt = 0;
        }
    
        bool insert(const Elem& element);
        bool append(const Elem& element);
        bool remove(Elem& element);
        
        void setStart()
        {
            fence = head;
            leftcnt = 0;
            rightcnt = listsize;
        }

        void setEnd()
        {
            fence = tail;
            leftcnt = listsize;
            rightcnt = 0;
        }

        void prev()
        {
            
        }




}
}
