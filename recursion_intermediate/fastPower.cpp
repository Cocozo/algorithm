#include <iostream>

using namespace std;

int fastPower(int number, int power);

int main()
{
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int number;
        int power;
        cin >> number >> power;
        cout << fastPower(number, power) << endl;
    }
}

int fastPower(int number, int power)
{
    if (power == 0)
        return 1;
    if (power % 2 == 0)
    {
        int result = fastPower(number, power / 2);
        return (result * result) % 1000;
    }
    else
    {
        int result = fastPower(number, (power - 1) / 2);
        return (number * result * result) % 1000;
    }
}