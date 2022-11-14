#include<iostream>

using namespace std;

#define MAX_INDEX 100

int a[MAX_INDEX] = {0, };

int maxNumber(int a, int b, int c)
{
    if(a > b)
    {
        if(a > c) return a;
        else return c;
    }
    else
    {
        if(b > c) return b;
    }
}

int findMaxNum(int start, int end)
{
    //만약에 인덱스가 하나인경우.
    if((start+1) == end) return a[start];

    // 중앙값 구하기    
    int midIndex = (end / 2) + start;

    //왼쪽, 오른쪽 구하기
    int left = findMaxNum(start, midIndex);
    int right = findMaxNum(midIndex+1, end);

    //중앙값 구하기
    int middle = 0;
    int temp;
    for(int i = start; i < midIndex; i++) { if(temp < 0) temp = 0; temp += a[i]; }
    middle += temp; temp = 0;
    for(int i = end-1; i >= midIndex; i--) { if(temp < 0) temp = 0; temp += a[i]; }
    middle += temp;

    //세 숫자 비교.
    int max = maxNumber(left, right, middle);

    return max;
}

int main()
{
    int tempt;
    cin >> tempt;

    while(tempt--)
    {
        int size;
        cin >> size;
        for(int i = 0; i < size; i++) cin >> a[i];

        int maxNum = findMaxNum(0, size);


    }

}