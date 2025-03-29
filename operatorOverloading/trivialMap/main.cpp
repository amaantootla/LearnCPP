#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade
{
    std::string name{};
    char grade{};
};

class GradeMap
{
  private:
    std::vector<StudentGrade> m_map{};

  public:
    char &operator[](const std::string &key)
    {
        auto found{std::find_if(m_map.begin(), m_map.end(), [&key](const StudentGrade &curr) -> bool {
            if (curr.name == key)
                return true;
            return false;
        })};

        if (found != m_map.end()) // already exists
        {
            return found->grade;
        }

        m_map.push_back(StudentGrade{key});
        return m_map.back().grade;
    }
};

int main()
{
    GradeMap grades{};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return EXIT_SUCCESS;
}
