#include<iostream>

using namespace std;

typedef struct point{
    int row, col;
} Point;

int cnt = 0;
int board[5][5] = {0, };
Point blank[16];

void printSudoku(){
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool sudoku(int n){

    if(n == cnt){
        printSudoku();
        return true;
    }

    int check[5] = {0, };

    int curRow = blank[n].row;
    int curCol = blank[n].col;

    for(int i = 1; i <= 4; i++)
    {
        check[board[curCol][i]] = 1;
        check[board[i][curRow]] = 1;
    }

    int resRow = curRow % 2 == 0 ? curRow - 1 : curRow + 1;
    int resCol = curCol % 2 == 0 ? curCol - 1 : curCol + 1;
    check[board[resCol][resRow]] = 1;

    for(int i = 1; i <= 4; i++)
    {
        if(check[i] == 1)continue;
        board[curCol][curRow] = i;
        if(sudoku(n+1)) return true;
        board[curCol][curRow] = 0;
    }

    return false;
}

int main(){

    int tempt;
    cin >> tempt;

    while (tempt--)
    {
        cnt = 0;
        for(int i = 1; i <= 4; i++)
        {
            for(int j = 1; j <= 4; j++)
            {
                cin >> board[i][j];
                if(board[i][j] == 0) 
                {
                    Point data; data.col = i; data.row = j;
                    blank[cnt] = data;
                    cnt++;
                }
            }
        }
        
        sudoku(0);

    }
    
}