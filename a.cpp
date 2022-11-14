#include<iostream>

using namespace std;

#define MAX_INDEX 100
#define MAX 10000
#define MIN 1

int a[MAX_INDEX];

int binarySearch(int start, int end, int target)
{
    if(start == end)
    {
        if(a[start] == target) return start;
        return -1;
    }

    int mid = (start + end) / 2;

    if(a[mid] == target) return mid;
    else if(a[mid] < target) return binarySearch(mid+1, end, target);
    else return binarySearch(start, mid, target);

}

int main()
{
    int tempt;
    cin >> tempt;

    while (tempt--)
    {
        int size, target;
        cin >> size >> target;
        for(int i = 0; i < size; i ++) cin >> a[i];
        
        cout << binarySearch(0, size-1, target) << endl;
    }
    
}
