#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int numTestCases;
    cin >> numTestCases;
    string input;
    int index = 1;
    while (numTestCases--)
    {
        stack<char> st;
        string input;
        bool isEnded = false;
        cin >> input;

        for(char i : input)
        {
            if(i == ')')
            {
                if(st.empty())
                {
                    isEnded = true;
                    break;
                }
                else { st.pop();}
            }
            else if(i == '(')
            {
                st.push(i);
            }
        }
        if(st.empty() && !isEnded) { cout << "YES" << endl; }
        else { cout << "NO" << endl; }
    }
}