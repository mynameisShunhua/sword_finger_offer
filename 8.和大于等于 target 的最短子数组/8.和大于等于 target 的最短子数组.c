#define _CRT_SECURE_NO_WARNINGS 1
int minSubArrayLen(int target, int* nums, int numsSize)
{
    int min_len = 0;
    int left = 0;
    int sum = 0;
    for (int right = 0; right < numsSize; right++)
    {
        sum += nums[right];
        //�����left==rightʱ���ǵ�right��left֮��ֻ��һ������ʱ������жϡ�
        while (sum >= target && left <= right)
        {
            int len = right - left + 1;
            //����Ҫע����ǵ�min_len == 0ʱҲ�ý�ȥ��
            if (min_len > len || min_len == 0)
            {
                min_len = len;
            }
            sum -= nums[left++];
        }
    }
    return min_len;
}