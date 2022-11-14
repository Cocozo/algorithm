#include<iostream>

using namespace std;

#define MAX 1000

void swap(int &a, int &b);
void insertSort(int *data, int length);

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
        insertSort(data, length);
    }

}

void swap(int &a, int &b){ int temp = a; a = b; b = temp; }

void insertSort(int *data, int length)
{
    int countCmpOps = 0; // 비교연산 횟수
    int countSwaps = 0; // 스왑연산 횟수
    
    
    for(int i = 1; i < length; i++)
    {
        for(int j = i; j > 0; j--)
        {
            countCmpOps++;
            if (data[j - 1] < data[j]) break;
            
            countSwaps++;
            swap(data[j - 1], data[j]);
        }

    }

    cout << countCmpOps << ' ' << countSwaps << endl;
}