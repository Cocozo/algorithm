#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findsimilarUpper(string a)
{
    int num = stoi(a);
    int i = 1;
    while((num + i) < 10)
    {
        if(find(broken.begin(), broken.end(), num + i) != broken.end()) break;
        i++
    }

    if(num + i < 10) return num + i
    else return -1

}

int findsimilarUnder(string a)
{
    int num = stoi(a);
    int i = 1;
    while(num - i > -1)
    {
        if(find(broken.begin(), broken.end(), num - i) != broken.end()) break;
        i++
    }

    if(num - i > -1) return num - i
    else return -1

}

int main()
{
    vector<int> broken;
    for(int i = 0; i < 10; i++) broken.push_back(i);
    string input;
    cin >> input;
    
    int tempt;
    cin >> tempt;
    while(tempt--)
    {
        int a; cin >> a;
        broken.append(a);
        
    }

    string maxNumber = "";

    if(find(broken.begin(), broken.end(), stoi(input[0])) ==  broken.end())
    {
        maxNumber.append(to_string(a));
        for(int i = 1; i < input.length(); i++)
        {
            if(find(broken.begin(), broken.end(), stoi(input[0])) ==  broken.end()) 
        }

    }
    else
    {
        
    }

    
}
