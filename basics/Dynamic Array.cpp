#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n {};
    cout << "Number of names: ";
    cin >> n;

    string* names { new string[n]{} };
    for (int i = 0; i < n; i++)
    {
        cout << "Name: ";
        getline(cin >> ws, names[i]);
    }

    sort(names, names + n);
    
    for (int i = 0; i < n; i++)
    {
        cout << names[i] << '\n';
    }
}