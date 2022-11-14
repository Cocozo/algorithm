#include<iostream>
#include<iomanip>

using namespace std;

#define MAX 9

typedef struct Point
{
    int x;
    int y;
} point;

point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int board[MAX][MAX];
int path[MAX][MAX];

int kingTour(int m, int n, point pos, int counter);
void printTour(int m, int n);

int main()
{
    int numTestCases;
    cin >> numTestCases;
    while (numTestCases--)
    {
        int m, n, x, y;
        cin >> m >> n >> y >> x;
        point start;
        start.x = x;
        start.y = y;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                board[i][j] = 0;

        board[start.y][start.x] = 1;
        path[start.y][start.x] = 1;
        int isaval = kingTour(m, n, start, 1);
        cout << isaval << endl;
        if (isaval)
        {
            printTour(m, n);
        }
    }
}

int kingTour(int m, int n, point pos, int counter)
{
 
    if(counter == (m * n)) return 1;

    point next;
    for(int i = 0; i < 8; i++)
    {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if(board[next.y][next.x] == 1) continue;

        if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m)
        {
            board[next.y][next.x] = 1;
            path[next.y][next.x] = counter + 1;
            if (kingTour(m, n, next, counter + 1)) return 1;
            board[next.y][next.x] = 0;
            path[next.y][next.x] = 0;
        }
    }

    return 0;
}

void printTour(int m, int n)
{
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++)
        {
            cout << setw(2) << setfill('0') << path[i][j] << " ";
        }
        cout << endl;
    }
}