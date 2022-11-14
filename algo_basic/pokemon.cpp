#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef struct Context
{
    string name;
    int index;
} context;

int isNummeric(string const &str)
{
    char *result;
    strtol(str.c_str(), &result, 10);
    return *result == 0;
}

int main()
{
    vector<string> dogam;

    int numTestCases, searchCnt;
    cin >> numTestCases >> searchCnt;
    string input;
    int index = 1;
    while (numTestCases--)
    {
        cin >> input;
        dogam.push_back(input);
    }


    while (searchCnt--)
    {
        cin >> input;
        if(isNummeric(input))
        {   
            cout << dogam[stoi(input)-1] << endl;
        }
        else
        {
            vector<string>::iterator a = find(dogam.begin(), dogam.end(), input);
            cout << a - dogam.begin() + 1 << endl;
        }
    }

}