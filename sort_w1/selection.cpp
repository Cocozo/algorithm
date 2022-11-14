#include<iostream>

using namespace std;

#define MAX 1000

void swap(int &a, int &b);
void selectionSort(int *data, int length);

int main()
{
    // 테스트 케이스 설정
    int testCase;
    cin >> testCase;
    // 테스트케이스만큼 실행
    for(int i = 0; i < testCase; i++)
    {
        int length;
        int data[MAX];
        cin >> length;

        for(int i = 0; i < length; i++){
            cin >> data[i];
        }

        // 버블정렬 구현
        selectionSort(data, length);
    }

}

void swap(int &a, int &b){ int temp = a; a = b; b = temp; }

void selectionSort(int *data, int length)
{
    int countCmpOps = 0; // 비교연산 횟수
    int countSwaps = 0; // 스왑연산 횟수
    
    for(int i = 0; i < length-1; i++)
    {
        int min = i;
        for(int j = i + 1; j < length; j++)
        {
            countCmpOps++;
            if (data[j] < data[min]) min = j;


        }

        if (min != i)
        {
            countSwaps++;
            swap(data[i], data[min]);
        }

    }

    cout << countCmpOps << ' ' << countSwaps << endl;
}