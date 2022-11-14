#include<iostream>
#include <iomanip>

using namespace std;

long long factorial(int n);

int main()
{
    int size;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        cout << factorial(input) % 1000 << endl;
    }
}



long long factorial(int n)
{
    if(n == 0) return 1;
    long long result = n * factorial(n - 1);
    while(result % 10 == 0) result /= 10;
    return result % 10000;
}
