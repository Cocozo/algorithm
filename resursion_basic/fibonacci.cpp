#include<iostream>

using namespace std;

int fibonacci(int n);

    int main()
{
    int size;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        cout << fibonacci(input) << endl;
    }
}

int fibonacci(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}