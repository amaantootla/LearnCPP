#include <iostream>

template<typename T>
struct DLLNode
{
    T val;
    DLLNode* next;
    DLLNode* prev;
};

template<typename T>
class List
{
    private:
        DLLNode<T>* head;
        DLLNode<T>* tail;

    public:
        List();
        ~List();
        void push_front(T val);
        void print();
        void reverse_print();

        class ListIterator
        {
            private:
                DLLNode<T>* ptr;
            
            public:
                ListIterator()
                    : ptr {nullptr}
                {
                }

                ListIterator(DLLNode<T>* n)
                    : ptr {n}
                {
                }

                DLLNode<T>& operator*()
                {
                    return *ptr;
                }

                // prefix
                ListIterator& operator++()
                {
                    if (ptr == nullptr)
                        return *this;
                    
                    ptr = ptr->next;
                    return *this;
                }

                // postfix
                ListIterator operator++(int)
                {
                    // we do move the iterator
                    // but we return the pre-moved position

                    if (ptr == nullptr)
                        return *this;
                
                    ListIterator tmp = *this;
                    ptr = ptr->next;
                    return tmp;
                }

                ListIterator& operator--()
                {
                    if (ptr == nullptr)
                        return *this;
                    
                    ptr = ptr->prev;
                    return *this;
                }

                ListIterator operator--(int)
                {
                    // we do move the iterator
                    // but we return the pre-moved position

                    if (ptr == nullptr)
                        return *this;
                
                    ListIterator tmp = *this;
                    ptr = ptr->prev;
                    return tmp;
                }

                // we use const here in case we want to compare rvalue
                // in these three following operators
                bool operator==(const ListIterator& other)
                {
                    return (ptr == other.ptr);
                }

                bool operator!=(const ListIterator& other)
                {
                    return !(ptr == other.ptr);
                }

                // copy assignment
                void operator=(const ListIterator& other)
                {
                    ptr = other.ptr;
                }
        };
        ListIterator begin();
        ListIterator end();  
};

template<typename T>
List<T>::List()
    : head {nullptr}, tail {nullptr}
{
}

template<typename T>
List<T>::~List()
{
    DLLNode<T>* curr = head;
    while (curr != nullptr)
    {
        DLLNode<T>* next = curr->next;
        delete curr;
        curr = next;
    }
}

template<typename T>
void List<T>::push_front(T val)
{
    DLLNode<T>* n = new DLLNode<T>;
    n->val = val;
    n->prev = nullptr;
    n->next = head;
    head = n;

    if (head->next != nullptr)
        head->next->prev = n;
    else
        tail = n;
}

template<typename T>
void List<T>::print()
{
    for (DLLNode<T>* curr = head; curr != nullptr; curr = curr->next)
    {
        std::cout << curr->val << ' ';
    }
    std::cout << std::endl;
}

template<typename T>
void List<T>::reverse_print()
{
    for (DLLNode<T>* curr = tail; curr != nullptr; curr = curr->prev)
    {
        std::cout << curr->val << ' ';
    }
    std::cout << std::endl;
}

template<typename T>
typename List<T>::ListIterator List<T>::begin()
{
    return ListIterator(head);
}

template<typename T>
typename List<T>::ListIterator List<T>::end()
{
    // https://stackoverflow.com/questions/62358198/how-to-implement-end-for-linked-list
    // this is what i figured out on my own too
    // it makes no sense though ...
    // you cannot reverse iterate via this method

    //DLLNode<T>* tail_end = tail + sizeof(DLLNode<T>);
    //return ListIterator(tail_end);

    return nullptr;
}

int main()
{
    List<int> nums {};
    nums.push_front(10);
    nums.push_front(5);
    nums.push_front(6);
    nums.print();
    nums.reverse_print();

    List<int>::ListIterator it;
    it = nums.begin();
    while (it != nums.end())
    {
        std::cout << (*it).val << ' ';
        it++;
    }
    std::cout << std::endl;
}

// A doubly linked list, templatized, featuring iterators
// Basically just an embeded class with traversal and element selection!