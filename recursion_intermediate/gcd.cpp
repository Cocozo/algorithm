#include<iostream>

using namespace std;

int gcd(int a, int b);

int main()
{
    int numTestCases;
    cin >> numTestCases;
    while (numTestCases--)
    {
        int a, b;
        cin >> a;
        cin >> b;
        cout << gcd(a, b) << endl;
    }

}

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}