#include <iostream>

using namespace std;

int fibonacci(int n, int mat[2][2]);

int main()
{
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int input;
        cin >> input;
        int mat[2][2] = { {1, 1},
                          {1, 0} };

        cout << fibonacci(1, mat) << endl;
    }
}


int fibonacci(int n, int mat[2][2])
{
    if (n == 0)
        return mat[1][1];
    if (n == 1)
        return mat[1][0];


    fibonacci(n - 1, newMat);
}