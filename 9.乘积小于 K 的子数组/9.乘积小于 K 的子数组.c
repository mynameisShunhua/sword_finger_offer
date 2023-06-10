#define _CRT_SECURE_NO_WARNINGS 1
int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    //乘积
    int sum_product = 1;
    //子数组的个数
    int count = 0;
    //左边界
    int left = 0;
    for (int right = 0; right < numsSize; right++)
    {
        sum_product *= nums[right];
        //判断是否大于k,并且需注意前提left<=right
        while (left <= right && sum_product >= k)
        {
            sum_product /= nums[left++];
        }
        //这里sum_product必定小于target，因此只需计算新增的个数即可
        count += (right - left + 1);
        //注意：当left -1 == right-> right-left +1 ==0 时，
        //——刚好新增的个数为0。

    }
    return count;
}