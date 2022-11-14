#include<iostream>

using namespace std;

#define MIN(a, b) a > b ? b : a
#define MAX_NUMBER 101

int a[MAX_NUMBER] = {0, };
int M[MAX_NUMBER][MAX_NUMBER] = {0, };
int P[MAX_NUMBER][MAX_NUMBER] = {0, };

int MatrixMultiplication(int n)
{   

    for(int i = 1; i <= n; i++) M[i][i] = 0;

    for(int d = 1; d <= n-1; d++)
    {
        for(int i = 1; i <= n - d; i++)
        {
            int min = 99999999;
            int target = -1;
            int j = i + d;
            for(int k = i; k <= j-1; k++) {
                int temp = M[i][k] + M[k+1][j] + (a[i-1] * a[k] * a[j]);
                min = MIN(min, temp);
                if(temp == min) target = k;
            }
            M[i][j] = min;
            P[i][j] = target;
        }
    }

    return M[1][n];
}

void order(int i, int j)
{
    if(i == j) cout << 'M' << i;
    else
    {
        int k = P[i][j];
        cout << "(";
        order(i, k);
        order(k+1, j);
        cout << ")";
    }
}

int main()
{
    int tempt;
    cin >> tempt;

    while (tempt--)
    {
        for(int i = 0; i < MAX_NUMBER; i++)
            for(int j = 0; j < MAX_NUMBER; j++) {M[i][j] = 0; P[i][j] = 0;}
        int n; cin >> n;
        for(int i = 0; i <= n; i++) cin >> a[i];
        int result = MatrixMultiplication(n);
        order(1, n);
        cout << endl;
        cout << result << endl;
    }
    
}
