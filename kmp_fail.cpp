#include<iostream>
#include<string>
using namespace std;
#define MAX 1000

int fail[MAX] = {0, };

void getFail(string pattern)
{
    int m = (int) pattern.size();
    int j = 0;

    //실패시 이동할 포지션 정하기.
    for(int i = 1; i< m ; i++)
    {

        while(j > 0 && pattern[i] != pattern[j])
            j = fail[j-1];

        if(pattern[i] == pattern[j])
            fail[i] = ++j;

    }
}


int kmp(string text, string pattern)
{
    int ans = 0;
    getFail(pattern);
    for(int i = 0; i < (int) pattern.size(); i++) cout << fail[i] << " ";
    cout << endl;
    int n = (int) text.size(); int m = (int) pattern.size();
    int j = 0;

    for(int i = 0 ; i < n ; i++)
    {
        while(j>0 && text[i] != pattern[j]) j = fail[j-1];
        if(text[i] == pattern[j])
        {
            //패턴을 찾았을때.
            if(j==m-1)
            {
                // 패턴 포지션 정답 벡터에 저장.
                ans++; 
                j = fail[j];
            }
            else j++;
        }
    }
    return ans;
}


int main() {

    int tempt;
    cin >> tempt;

    while(tempt--)
    {  
        for(int i = 0; i < 1000; i++) fail[i] = 0;
        string text, pattern;
        cin >> pattern >> text;
        cout << kmp(text, pattern) << endl;
    }
}