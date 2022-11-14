#include<iostream>
#include<deque>
#include<string>


using namespace std;

int main()
{
    int tempt;
    cin >> tempt;

    while(tempt--)
    {
        bool isError = false;
        int length;
        string mods;
        string arr;

        cin >> mods >> length >> arr;

        deque<int> nums;

        string number = "";
        for(char a : arr)
        {
            if(a == '[') continue;
            if(a == ',' || a == ']')
            {
                nums.push_back(stoi(number));
                number = "";
            }
            else number += a;
        }
        
        int isReverse = false;
        for(char mod : mods)
        {
            if(mod == 'R') isReverse = !isReverse;
            else if(mod == 'D')
            {
                if(nums.empty())
                {
                    isError = true;
                    break;
                }

                if(!isReverse) nums.pop_front();
                else nums.pop_back();

            }
        }

        if(isError)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << "[";
            while(!nums.empty())
            {
                if(!isReverse) {
                    if(nums.size() != 1) cout << nums.front() << ',';
                    cout << nums.front();
                    nums.pop_front();
                }
                else {
                    if(nums.size() != 1) cout << nums.front() << ',';
                    cout << nums.back();
                    nums.pop_back();
                }
            }
            cout << "]" << endl;
        }

    }
}