#ifndef LANG_H
#define LANG_H
#include <string>

// better this then to rely on magic numbers, give them a name at least

namespace MonsterType
{
enum MonsterType
{
    orc,
    goblin,
    troll,
    ogre,
    skeleton
};
} // namespace MonsterType

enum Lang
{
    English, // 0
    Spanish, // 1
    French,   // 2
             // ... n - 1
};

struct Person
{
    int age {};
    std::string name {};
};

#endif
