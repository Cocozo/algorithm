#include<iostream>

using namespace std;

#define MAX 1000

void swap(int &a, int &b);
void bubbleSort(int *data, int length);
void bubbleImprove1(int *data, int length);
void bubbleImprove2(int *data, int length);

int main()
{

    // 테스트 케이스 설정
    int testCase;
    cin >> testCase;

    // 테스트케이스만큼 실행
    for(int i = 0; i < testCase; i++)
    {
        int length;
        int data_a[MAX];
        int data_b[MAX];
        int data_c[MAX];
        cin >> length;

        for(int i = 0; i < length; i++){
            cin >> data_a[i];
            data_b[i] = data_a[i];
            data_c[i] = data_a[i];
        }

        // 버블정렬 구현
        bubbleSort(data_a, length);
        // 개선 버전1 구현
        bubbleImprove1(data_b, length);
        // 개선 버전2 구현
        bubbleImprove2(data_c, length);
    }

}

void swap(int &a, int &b){ int temp = a; a = b; b = temp; }

void bubbleSort(int *data, int length)
{
    int countCmpOps = 0; // 비교연산 횟수
    int countSwaps = 0; // 스왑연산 횟수

    for(int pass = 0; pass < length; pass++)
    {
        for(int i = 1; i < length-pass; i++)
        {
            countCmpOps++;
            if (data[i - 1] > data[i])
            {
                countSwaps++;
                swap(data[i-1], data[i]);
            }
        }
    }

    cout << countCmpOps << ' ' << countSwaps << ' ';
}

void bubbleImprove1(int *data, int length)
{
    int countCmpOps = 0; // 비교연산 횟수
    int countSwaps = 0;  // 스왑연산 횟수
    bool swapped = false;
    for (int pass = 0; pass < length; pass++)
    {
        swapped = false;
        for (int i = 1; i < length - pass; i++)
        {
            countCmpOps++;
            if (data[i - 1] > data[i])
            {
                countSwaps++;
                swap(data[i - 1], data[i]);
                swapped = true;
            }
        }

        if(swapped == false){break;}
    }

    cout << countCmpOps << ' ' << countSwaps << ' ';
}

void bubbleImprove2(int *data, int length)
{
    int countCmpOps = 0; // 비교연산 횟수
    int countSwaps = 0;  // 스왑연산 횟수

    int lastSwappedPostion = length;
    while (lastSwappedPostion > 0)
    {
        int swappedPosition = 0;
        for (int i = 1; i < lastSwappedPostion; i++)
        {
            countCmpOps++;
            if (data[i - 1] > data[i])
            {
                countSwaps++;
                swap(data[i - 1], data[i]);
                swappedPosition = i;
            }
        }
        lastSwappedPostion = swappedPosition;
    }

    cout << countCmpOps << ' ' << countSwaps << endl;
}
