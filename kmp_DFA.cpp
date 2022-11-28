#include<iostream>
#include<string>

using namespace std;

#define MAX 10001

int patternLength = 0;
int txtLength = 0;
int patNum[MAX];
int txtNum[MAX];
int DFA[3][MAX];

void makePattern(string pattern, string text)
{
    for(int i = 0; i < patternLength; i++)
    {
        patNum[i] = pattern[i] - 'A';
    }

    for(int i = 0; i < txtLength; i++)
    {
        txtNum[i] = text[i] - 'A';
    }
}

int constructDFA(string pattern)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j <= patternLength; j++) DFA[i][j] = 0;
    }

    DFA[patNum[0]][0] = 1;
    int X, j;
    int cnt = 0;

    for(X = 0, j=1; j < patternLength; j++)
    {
        for(int c=0; c<3; c++)
            DFA[c][j] = DFA[c][X];

        DFA[patNum[j]][j] = j+1;    
        X = DFA[patNum[j]][X];             
    }

    for(int c=0; c<3; c++)
        DFA[c][j] = DFA[c][X];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j <= patternLength; j++)
        {
            if(DFA[i][j] != 0) cnt++;
        }
    }

    return cnt;
}


int KMP(string text)
{
    int i, j;
    int ans = 0;
    
    j = 0;
    for(int i = 0; i < txtLength; i++)
    {  
        j = DFA[txtNum[i]][j];  // text[i] to be modified
        if(j == patternLength) ans++;
    }

    return ans;
}



int main()
{

    int tempt;
    cin >> tempt;
    while (tempt--)
    {    
        string pattern = "ABABACA";
        string text = "ABCABAABABABACACA";

        cin >> pattern >> text;

        patternLength = pattern.size();
        txtLength = text.size();
        makePattern(pattern, text);
        cout << constructDFA(pattern) << " ";
        cout << KMP(text) << endl;
    }


}