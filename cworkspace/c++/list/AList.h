#include "List.h"

using namespace std;

template <class Elem>
class AList : public List<Elem>{
    private :
        int maxSize;
        int listSize;
        int fence;
        Elem* listArray;
    public :
        AList(int size){
            maxSize = size;
            listSize = fence = 0;
            listArray = new Elem[maxSize];
        }

        ~AList()
        {
            delete [] listArray;
        }
        void clear(){
            delete [] listArray;
            listSize = fence = 0;
            listArray = new Elem[maxSize];
        }

        bool insert (const Elem&);
        bool append (const Elem&);
        bool remove(Elem&);
        void setStart() {   fence = 0;  }
        void setEnd() { fence = listSize;   }
        void prev() {   if (fence != 0) fence--;    }
        void next() {   if (fence <= listSize) fence++; }
        int leftLength() const {    return fence;   }
        int rightLength() const {   return listSize-fence;  }
        bool setPos(int pos){
            if((pos >= 0) && (pos <= listSize)) 
                fence = pos;
            return (pos >= 0) && (pos <= listSize);
        }
        bool getValue(Elem& it){
            if(rightLength() == 0)
                return false;
            else
            {
                it = listArray[fence];
                return true;
            }
        }
        void print() const{
            int temp = 0;
            cout << "<";
            while(temp < fence) 
                cout << listArray[temp++] << " ";
            cout << " | ";
            while(temp<listSize) 
                cout << listArray[temp++] << " ";
            cout << ">\n";
        }
};

template <class Elem>
bool AList<Elem>::insert(const Elem& item)
{
    if(listSize == maxSize)
        return false;
    for(int i = listSize; i > fence; i--)
        listArray[i] = listArray[i-1];
    listArray[fence] = item;
    listSize++;
    return true;
}

template <class Elem>
bool AList<Elem>::append(const Elem& item){
    if(listSize == maxSize)
        return false;
    listArray[listSize++] = item;
    return true;
}

template <class Elem>
bool AList<Elem>::remove(Elem& it){
    if(rightLength() == 0)
        return false;
    it = listArray[fence];
    for(int i = fence; i<listSize-1; i++)
        listArray[i] = listArray[i+1];
    listSize--;
    return true;
}
