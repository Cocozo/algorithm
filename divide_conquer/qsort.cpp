#include<iostream>

using namespace std;

#define MAX_INDEX 1000

int a[MAX_INDEX], b[MAX_INDEX];
int swapSumRomuto = 0, compSumRomuto = 0;
int swapSumHoare = 0, compSumHoare = 0;

int swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

int partitionRomuto(int start, int end)
{
    int i, j, pivotPos;
    int pivot = a[start];
    j = start;
    
    for(int i = start + 1; i <= end; i++)
    {
        compSumRomuto++;
        if(a[i] < pivot)
        {
            j++;
            swapSumRomuto++;
            swap(a[j], a[i]);
        }
    }

    pivotPos = j;
    swapSumRomuto++;
    swap(a[start], a[pivotPos]);

    return pivotPos;
}

int partitionHoare(int start, int end)
{
    int i, j;
    int pivot;

    pivot = b[start];

    i = start - 1;
    j = end + 1;

    while(true)
    {
        compSumHoare++;
        while (b[++i] < pivot) { compSumHoare++; }

        compSumHoare++;
        while (b[--j] > pivot) { compSumHoare++; }

        if(i < j) {swap(b[i], b[j]); swapSumHoare++; }
        else return j;
    }
}



int qsortRomuto(int start, int end)
{
    int pivotPos;

    if(start < end)
    {
        pivotPos = partitionRomuto(start, end);
        qsortRomuto(start, pivotPos - 1);
        qsortRomuto(pivotPos + 1, end);
    }
}

int qsortHoare(int start, int end)
{
    int pivotPos;

    if(start < end)
    {
        pivotPos = partitionHoare(start, end);
        qsortHoare(start, pivotPos);
        qsortHoare(pivotPos + 1, end);
    }
}


int main()
{
    int tempt;
    cin >> tempt;

    while(tempt--)
    {
        swapSumHoare = 0;
        swapSumRomuto = 0;
        compSumHoare = 0;
        compSumRomuto = 0;

        int size;
        cin >> size;

        for(int i = 0; i < size; i++)
        {
            int input; cin >> input;
            a[i] = input; b[i] = input;
        }

        qsortRomuto(0, size - 1);
        qsortHoare(0, size - 1);
        cout << swapSumHoare << " ";
        cout << swapSumRomuto << " ";
        cout << compSumHoare << " ";
        cout << compSumRomuto << endl;
    }

}