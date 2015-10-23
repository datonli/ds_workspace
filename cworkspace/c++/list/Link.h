
template <class Elem>
class Link{
    public:
        Elem element;
        Link *next;
        Link(const Elem& elemval)
        {
            element = elemval;
            next = NULL;
        }
        Link()
        {
            next = NULL;
        }
};
