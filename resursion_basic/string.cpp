#include <iostream>

using namespace std;
#define MAX 9

void swap(int &a, int &b);
int permutation(int baseNum[], int depth, int length, int weight);

int main()
{
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        string input;
        int length = 0;
        int baseNumber[MAX];
        cin >> input;
        for(char i : input)
        {
            baseNumber[length] = i - 'a';
            length++;
        }

        cout << permutation(baseNumber, 0, length, 0) << endl;
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int permutation(int baseNum[], int depth, int length, int weight)
{
    int count  = 0;

    if(depth == length)
    {
        if(weight > 0) return 1;
    }

    for(int i = depth; i < length; i++)
    {
        if(i != depth) swap(baseNum[depth], baseNum[i]);

        if(depth % 2 == 0)
            count += permutation(baseNum, depth + 1, length, weight + baseNum[depth]);
        else
            count += permutation(baseNum, depth + 1, length, weight - baseNum[depth]);

        if(i != depth) swap(baseNum[depth], baseNum[i]);
    }

    return count;
}