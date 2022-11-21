#include<iostream>

using namespace std;

#define N 16
int col[N];


int isPromising(int row)
{
    int k;
    int promising;
    k = 0;
    promising = 1;
    while(k < row && promising)
    {
        if(col[row] == col[k] || abs(col[row] - col[k]) == row - k) promising = 0;
        k++;
    }
    return promising;
}

void printNqueens(int k){
    for(int i = 0; i < k; i++) cout << col[i]+1 << " ";
}

bool nQueens(int row, int k)
{
    int i;
    if (isPromising(row))
    {
        if (row == k-1)
        {
            printNqueens(k);
            return true;
        }
        else
        {
            for(i=0; i < k; i++)
            {
                col[row+1] = i;
                if(nQueens(row+1, k)) return true;
                
            }
        }
    }
    return false;
}
int main(){

    int i;
    cin >> i;
    while(i--){
        int k;
        cin >> k;
        for(int j=0; j<k; j++)
        {
            col[0] = j;
            if(nQueens(0, k)) break;
        }
        cout << endl;

    }


}