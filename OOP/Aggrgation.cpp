#include <iostream>
#include <string>
#include <functional>
#include <vector>

class Teacher
{
private:
  std::string m_name{};

public:
  Teacher(const std::string& name)
      : m_name{ name }
  {
  }

  const std::string& getName() const { return m_name; }
};

class Department
{
private:
  std::vector<std::reference_wrapper<const Teacher>> teachers {};

public:

  Department() {}

  Department(const Teacher& teacher)
  {
    teachers.push_back(teacher);
  }

  void add(const Teacher& t)
  {
    teachers.push_back(t);
  }

  friend std::ostream& operator<< (std::ostream& out, Department& d);
};

std::ostream& operator<< (std::ostream& out, Department& d)
{
    out << "Deparment: ";
    unsigned int teachersLength = d.teachers.size();
    for (int i = 0; i < teachersLength; i++)
    {
        // .get() is needed for std::reference_wrapper<>
        // it GETS the object being stored as a reference, duh!
        out << d.teachers[i].get().getName();
    }
    return out;
}

int main()
{
  // Create a teacher outside the scope of the Department
  Teacher t1{ "Bob" };
  Teacher t2{ "Frank" };
  Teacher t3{ "Beth" };

  {
    // Create a department and add some Teachers to it
    Department department{}; // create an empty Department

    department.add(t1);
    department.add(t2);
    department.add(t3);

    std::cout << department;

  } // department goes out of scope here and is destroyed

  std::cout << t1.getName() << " still exists!\n";
  std::cout << t2.getName() << " still exists!\n";
  std::cout << t3.getName() << " still exists!\n";

  return 0;
}