#include <fstream>
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int main()
{
    // Input

    ifstream inputFileStream;

    inputFileStream.open("test.txt");
    assert(inputFileStream.is_open());

    // read until there is nothing left in the file
    while (inputFileStream)
    {
        string line {};
        inputFileStream >> line;
        cout << line;
    }

    inputFileStream.close();

    // Output

    ofstream outputFileStream;

    outputFileStream.open("test.txt");
    assert(outputFileStream.is_open());

    outputFileStream << "again" << endl;
    outputFileStream << "hello" << endl;
}