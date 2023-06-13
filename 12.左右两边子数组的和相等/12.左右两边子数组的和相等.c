#define _CRT_SECURE_NO_WARNINGS 1
int pivotIndex(int* nums, int numsSize)
{
    int tar_index = -1;

    //求前n个数字之和
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }

    int cur_sum = 0;//就等于左边的和 + 中心下标
    for (int i = 0; i < numsSize; i++)
    {
        cur_sum += nums[i];
        //左边的和
        int left = cur_sum - nums[i];
        //右边的和
        int right = sum - cur_sum;
        if (right == left)
        {
            tar_index = i;
            break;
        }
    }
    return tar_index;
}