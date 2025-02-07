#ifndef INTVECTOR_H
#define INTVECTOR_H

class IntVector
{
    private:
        unsigned int vectorLength {};
        int* ints {};
    
    public:
        IntVector();
        IntVector(unsigned int vectorLength);
        ~IntVector();
        
        IntVector(const IntVector& iv);

        // returns value at index i, -1 on a out-of-bounds condition
        int& at(unsigned int i);

        // returns the first element, -1 if empty
        int front();

        // returns the last element, -1 if empty
        int back();

        // returns true if empty, false otherwise
        bool empty();

        // returns size 
        unsigned int size();

        // inserts or deletes at index pos
        void insert(unsigned int pos, int n);
        void erase(unsigned int pos);

        // adds i to end
        void push_back(int n);

        // deletes last element
        void pop_back();

        // destroys all elements and changes size
        void resize(unsigned int n);

        // copies over elements and changes size
        void reallocate(unsigned int n);

        int& operator[](unsigned int n);
        IntVector& operator=(const IntVector& iv);
};

#endif 

// My own implementation of a vector that can hold ints
// NOTE: there is no difference between capacity and size
// in this implementation, the size == capacity
// this makes some processes very inefficent, such as pop_back()
// which now must reallocate memory to accomdate the 1 element smaller
// array