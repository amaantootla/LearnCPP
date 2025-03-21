#include <iostream>
#include <string>

struct IntPair
{
  private:
    int first;
    int second;

  public:
    IntPair(int first, int second)
    {
        this->first = first;
        this->second = second;
    }

    void print() const // we do not modify the class (thus sutiable to call this method on const instances)
    {
        std::cout << "Pair( " << first << " , : " << second << ")" << std::endl;
    }

    void print()
    { // overload on const-ness
        std::cout << "YOU WILL NEVER CHANGE THESE VALUES HAHAHAH " << "Pair( " << first << " , : " << second << ")"
                  << std::endl;
    }

    bool isEqual(const IntPair &rhs) const
    {
        if (first != rhs.first || second != rhs.second)
            return false;
        return true;
    }
};

int main()
{
    IntPair p1{1, 2};
    IntPair p2{3, 4};

    std::cout << "p1: ";
    p1.print();

    std::cout << "p2: ";
    p2.print();

    std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
    std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

    return 0;
}
