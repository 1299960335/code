#include<stdio.h>
int removeElement(int* nums, int numsSize, int val) {
    if (nums == NULL || numsSize == 0) {
        return 0;
    }
    int size = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[size] = nums[i];
            size++;
        }
    }
    return size;
}
int main()
{
    int arr[] = { 1,2,3,5,1,8,1,1,2,8 };
    int a = sizeof(arr) / sizeof(arr[0]);
    int b = 1;
    printf("移除元素后的长度为%d", removeElement(arr, a, b));
    return 0;
}