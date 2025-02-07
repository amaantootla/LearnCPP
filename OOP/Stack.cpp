#include <iostream>
#include <array>
#include <cassert>

using namespace std;

class Stack
{
    private:
        array<int, 10> integers {};
        int arraySize = 0;

    public: 
        void reset()
        {
            arraySize = 0;
        }

        bool push(int x)
        {
            if (arraySize == 10)
                return false;
            
            integers[arraySize] = x;
            arraySize += 1;

            return true;
        }

        int pop()
        {
            assert(arraySize != 0);
            int tmp = integers[arraySize];
            arraySize--;
            return tmp;
        }

        void print()
        {
            cout << "(";
            for (int i = 0; i < arraySize; i++)
            {
                cout << " " << integers[i];
            }
            cout << " )" << endl;
        }
    
};

int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}

