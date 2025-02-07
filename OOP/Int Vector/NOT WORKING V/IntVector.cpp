#include "IntVector.h"
#include <iostream>

#define ERROR -1

IntVector::IntVector()
{
    vectorLength = 0;
    ints = nullptr;
}

IntVector::IntVector(unsigned int vectorLength)
{
    this->vectorLength = vectorLength;
    this->ints = new int[vectorLength];
}

IntVector::~IntVector()
{
    delete ints;
    ints = nullptr;
}

int& IntVector::at(unsigned int i)
{
    if (i > vectorLength)
    {
        int tmp = -1;
        return tmp; // we know, this is the only way to handle it without a crash
    }
    else
    {
        return ints[i]; // just return as a normal value, and it'll get
                        // turned into a reference (no special operator like & needed)
                        // i.e. this is not a POINTER (c-style)
    }
}

int IntVector::front()
{
    if (vectorLength > 0)
    {
        return ints[0];
    }
    else
    {
        return ERROR;
    }
}

int IntVector::back()
{
    if (vectorLength > 0)
    {
        return ints[vectorLength];
    }
    else
    {
        return ERROR;
    }
}

bool IntVector::empty()
{
    if (vectorLength == 0)
    {
        return true;
    }
    return false;
}

unsigned int IntVector::size()
{
    return vectorLength;
}

void IntVector::insert(unsigned int pos, int n)
{
    if (pos > vectorLength || pos == 0)
    {
        return;
    }

    int* new_ints = new int[vectorLength + 1];

    for (int i = 0; i < pos && i < vectorLength; i++)
    {
        new_ints[i] = ints[i];
    }

    new_ints[pos] = n;

    pos++;
    
    for (; pos < vectorLength; pos++)
    {
        new_ints[pos] = ints[pos];
    }
}

void IntVector::erase(unsigned int pos)
{
    reallocate(vectorLength - pos);
    return; 
}

void IntVector::push_back(int n)
{
    int* new_ints = new int[vectorLength + 1];
    for (int i = 0; i < vectorLength; i++)
    {
        new_ints[i] = ints[i];
    }
    new_ints[vectorLength + 1] = n;

    ++vectorLength;
    delete ints;
    ints = new_ints;
    return;
}

void IntVector::pop_back()
{
    reallocate(vectorLength - 1);
    return;
}

void IntVector::resize(unsigned int n)
{
    delete ints;
    ints = new int[n];
    for (unsigned int i = 0; i < n; i++)
    {
        ints[i] = 0;
    }
    return;
}

void IntVector::reallocate(unsigned int n)
{

    // this is a bogus case
    if (n == vectorLength)
        return;
    
    int* new_vector = new int[n];

    // copy over all elements that CAN be copied over
    // if n < vectorLength data will be lost
    // if n > vectorLength the remaining elemnts will
    // be initialized to zero
    if (n > vectorLength)
    {
        for (int i = 0; i < vectorLength; i++)
        {
            new_vector[i] = ints[i];
        }

        // new elements get zero'd
        for (int i = vectorLength; i < n; i++)
        {
            new_vector[i] = 0;
        }
    }
    else if (n < vectorLength)
    {
        for (int i = 0; i < n; i++)
        {
            new_vector[i] = ints[i];
        }
    } 

    vectorLength = n;
    delete ints;
    ints = new_vector;
    return;
}

int& IntVector::operator[](unsigned int n)
{
    return at(n);
}