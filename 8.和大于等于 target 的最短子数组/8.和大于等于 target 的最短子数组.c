#define _CRT_SECURE_NO_WARNINGS 1
int minSubArrayLen(int target, int* nums, int numsSize)
{
    int min_len = 0;
    int left = 0;
    int sum = 0;
    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];
        //这里的left==right时，是当right与left之间只有一个数字时的情况判断。
        while (sum >= target && left <= right)
        {
            int len = right - left + 1;
            //这需要注意的是当min_len == 0时也得进去。
            if (min_len > len || min_len == 0)
            {
                min_len = len;
            }
            sum -= nums[left++];
        }
    }
    return min_len;
}