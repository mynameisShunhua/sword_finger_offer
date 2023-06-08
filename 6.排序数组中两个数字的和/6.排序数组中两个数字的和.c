#define _CRT_SECURE_NO_WARNINGS 1
//法①代码——双指针
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    //开辟空间并初始化数组
    int* arr = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    memset(arr, 0, sizeof(int) * 2);
    //双指针查找思路
    int left = 0;
    int right = numbersSize - 1;
    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum > target)
        {
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            arr[0] = left;
            arr[1] = right;
            break;
        }
    }

    return arr;
}
//法②代码——二分查找
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    //开辟空间并初始化数组
    int* arr = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    memset(arr, 0, sizeof(int) * 2);
    //二分查找思路
    for (int i = 0; i < numbersSize; i++)
    {
        //从左边开始
        int left = i + 1;
        int right = numbersSize - 1;
        int mid = (left + right) / 2;
        int Target = target - numbers[i];
        int flag = 0;
        while (left <= right)//这里是可以相等的，因为我要找的是一个数
        {
            if (numbers[mid] > Target)
            {
                right = mid - 1;
            }
            else if (numbers[mid] < Target)
            {
                left = mid + 1;
            }
            else
            {
                flag = 1;
                break;
            }
            //更新mid
            mid = (left + right) / 2;
        }
        if (flag)
        {
            arr[0] = i;
            arr[1] = mid;
            break;
        }
    }

    return arr;
}