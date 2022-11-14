#include <iostream>

using namespace std;

#define MAX 11

int stack[MAX];
int k = 0;
void hanoi(int a, int b, int c, int n);

int main()
{
    int size;
    cin >> size;
    
    for (int i = 0; i < size; i++)
    {
        int input;
        k = 0;
        cin >> input;
        hanoi(1, 2, 3, input);
        cout << endl;
    }
}

void hanoi(int a, int b, int c, int n)
{
    if(n > 0)
    {   
        // 상위 타워들을 옮긴다 a->b
        hanoi(a, c, b, n - 1);
        if(c == 3)
        {
            cout << n << " ";
            stack[++k] = n;
        }
        if(a == 3)
        {
            cout << stack[--k] << " ";
        }
        // 나머지를 옮긴다. b -> c
        hanoi(b, a, c, n - 1);
    }
}