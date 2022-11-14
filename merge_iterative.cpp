#include<iostream>

using namespace std;

#define MAX_INDEX 100
#define MAX 10000
#define MIN(a, b) a > b ? b : a

int a[MAX_INDEX];

int merge(int start, int mid, int end)
{
    int i, j, k; int temp[MAX_INDEX];
    int tempt = 0;
    for(i = start; i <= end; i++) temp[i] = a[i];

    i = start; k = start; j = mid+1;

    while (i <= mid && j <= end)
    {
        tempt++;
        if(temp[i] <= temp[j]) a[k++] = temp[i++];
        else a[k++] = temp[j++];
    }

    while(i <= mid) a[k++] = temp[i++];
    while(j <= end) a[k++] = temp[j++];
    return tempt;
    
}

int mergeSort(int start, int end)
{
    if(start == end) return 0;
    int midIndex = (start + end) / 2;
    int result = 0;
    result += mergeSort(start, midIndex);
    result += mergeSort(midIndex + 1, end);
    return result + merge(start, midIndex, end);
}

int mergeSortIterative(int n) { 
    int size = 1;
    int sum = 0;
    while (size < n)
    { 
        for (int i = 0; i < n; i += 2 * size)
        { 
            int low = i;
            int mid = low + size - 1;
            int high = MIN(i + 2 * size - 1, n - 1);

            if (mid >= n - 1) break; 
            sum += merge(low, mid, high);
        }
        size *= 2;
    }

    return sum;
}

int main()
{
    int tempt;
    cin >> tempt;

    while (tempt--)
    {
        int size;
        cin >> size;
        for(int i = 0; i < size; i++) cin >> a[i];

        cout << mergeSortIterative(size) << endl;
    }
}