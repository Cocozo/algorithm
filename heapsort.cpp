#include<iostream>

using namespace std;

#define MAX 1001

int arr[MAX] = {0, };
int cnt = 0;

void fixHeap(int root, int key, int length){
    int vacant = root;
    int largerChild;

    while(vacant * 2 <= length)
    {
        int left = vacant * 2;
        int right = (vacant * 2) + 1;
        cnt++;
        if(right > length)
        {
            largerChild = left;
        }
        else
        {
            largerChild = arr[left] > arr[right] ? left : right;
            cnt ++;
        }

        if(key < arr[largerChild])
        {
            arr[vacant] = arr[largerChild];
            vacant = largerChild;
        }
        else break;
    }
    

    arr[vacant] = key;
}


void heapsort(int n)
{
    for(int i = n/2; i >= 1; i--)
    {
        fixHeap(i, arr[i], n);
    }
    
    int max = 0;
    for(int heapSize = n; heapSize >= 2; heapSize--)
    {
        max = arr[1];
        fixHeap(1, arr[heapSize], heapSize-1);
        arr[heapSize] = max;
    }
}

int main() {
    int tempt;
    cin >> tempt;

    while (tempt--)
    {  
        cnt = 0;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> arr[i];
        heapsort(n);
        cout << cnt << endl;

    }
    
}