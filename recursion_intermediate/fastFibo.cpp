#include <iostream>

using namespace std;

typedef struct Matrix
{
    int a, b;
    int c, d; // 변수명 뭘로할까
}matrix;

matrix fastFibo(int n);
matrix matmulti(matrix mat1, matrix mat2);

matrix base = {1,1,1,0};
int main()
{
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int n;
        cin >> n;
        if(n == 0) cout << '0' << endl;
        else cout << fastFibo(n).b << endl;
    }
}

matrix fastFibo(int n)
{
    if (n == 1)
        return base;
    if (n % 2 == 0)
    {
        matrix result = fastFibo(n / 2);
        return matmulti(result, result);
    }
    else
    {
        matrix result = fastFibo((n - 1) / 2);
        return matmulti(matmulti(result, result), base);
    }
}

matrix matmulti(matrix mat1, matrix mat2)
{
    matrix result;
    result.a = ((mat1.a * mat2.a) + (mat1.b * mat2.c)) % 1000;
    result.b = ((mat1.a * mat2.b) + (mat1.b * mat2.d)) % 1000;
    result.c = ((mat1.c * mat2.a) + (mat1.d * mat2.c)) % 1000;
    result.d = ((mat1.c * mat2.b) + (mat1.d * mat2.d)) % 1000;

    return result;
}
