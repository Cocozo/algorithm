#include<iostream>

using namespace std;

#define MAX 1000

void swap(int &a, int &b);
void combSort(int *data, int length);

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
        combSort(data, length);
    }

}

void swap(int &a, int &b){ int temp = a; a = b; b = temp; }

void combSort(int *data, int length)
{
    int countCmpOps = 0; // 비교연산 횟수
    int countSwaps = 0; // 스왑연산 횟수

    int gap = length;
    bool sorted = false;

    while (sorted == false)
    {
        gap = gap / 1.3;
        if(gap <= 1)
        {
            gap = 1;
            sorted = true;
        }

        for(int i = 0; i+gap < length; i++)
        {
            countCmpOps++;
            if(data[i] > data[i+gap])
            {
                countSwaps++;
                swap(data[i], data[i+gap]);
                sorted = false;
            }
        }

    }

    cout << countCmpOps << ' ' << countSwaps << endl;
}