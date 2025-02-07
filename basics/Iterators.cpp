#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> nums {1, 2, 3, 4, 5};
    std::vector<int>::iterator it;
    
    it = nums.begin();
    while (it != nums.end())
    {
        // *iterator gives the value
        // i.e. like a pointer
        std::cout << *it << ' ';
        ++it;
    }
    std::cout << std::endl;

    // many STL algos also make use of iterators
    std::reverse(nums.begin(), nums.end());
    for (auto i: nums)
        std::cout << i << ' ';
    std::cout << std::endl;
}

// An abstraction for common operations on data strcutures
// like moving froward or backward through the strcuture or
// changing values within
