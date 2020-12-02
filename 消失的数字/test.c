#include<stdio.h>
int missingNumber(int* nums, int numsSize) {
    int a = 0;
    for (int i = 0; i < numsSize; i++) {
        a ^= i;
        a ^= nums[i];
    }
    a ^= numsSize;
    return a;
}
int main()
{
    int arr[] = { 0,3,1 };
    int a = sizeof(arr)/sizeof(arr[0]);
    printf("%d", missingNumber(arr, a));
    return 0;
}