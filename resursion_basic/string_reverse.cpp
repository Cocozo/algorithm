#include<iostream>
#include <iomanip>

using namespace std;

string reverseString(int first, int last, string data);

int main()
{
    int size;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        string input;
        cin >> input;
        cout << reverseString(0, input.length() - 1, input) << endl;
    }
}

string reverseString(int first, int last, string data)
{
    if(first >= last) return data;

    char temp = data[first];
    data[first] = data[last];
    data[last] = temp;

    return reverseString(first+1, last-1, data);
}
