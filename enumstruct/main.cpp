#include "lang.h"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const Lang &n)
{
    if (n == English)
        return out << "English";
    else if (n == Spanish)
        return out << "Spanish";
    else if (n == French)
        return out << "French";
    else
        return out;
}

std::ostream &operator<<(std::ostream &out, const Person &n)
{
    return out << "Age: " << n.age << " " << "Name: " << n.name << std::endl;
}

std::istream &operator>>(std::istream &in, Lang &n)
{
    std::string s{};
    in >> s;

    if (s == "English")
    {
        n = English;
    }
    else if (s == "Spanish")
    {
        n = Spanish;
    }
    else if (s == "French")
    {
        n = French;
    }
    else
    {
        n = {};
        in.setstate(std::ios_base::failbit);
    }

    return in;
}

int main()
{
    Lang iSpeak{English};
    MonsterType::MonsterType me{MonsterType::MonsterType::troll};

    // we need to cast a inetger to the enum type to set it
    int tmp{};
    Lang youSpeak{};
    std::cin >> tmp;
    tmp = std::clamp(tmp, 0, 2);
    youSpeak = static_cast<Lang>(tmp);

    Lang weSpeak{};
    std::cin >> weSpeak;

    Person amaan {};
    amaan.age = 100;
    amaan.name = "self";

    Person *ptr = &amaan;
    std::cout << ptr->age << " " << ptr->name << std::endl;

    std::cout << amaan;
    std::cout << iSpeak << me << youSpeak << weSpeak << std::endl;
}
