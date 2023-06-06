#define _CRT_SECURE_NO_WARNINGS 1
int singleNumber(int* nums, int numsSize)
{
    //开辟并初始化空间
    int* arr = (int*)malloc(sizeof(int) * 32);
    memset(arr, 0, sizeof(int) * 32);
    //获取每一位的位数
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (((nums[i] >> j) & 1) == 1)
            {
                arr[31 - j] += 1;
            }
        }
    }
    //将每一位模3获取只出现1次的数字的二进制位

    for (int i = 0; i < 32; i++)
    {
        arr[i] = arr[i] % 3;
    }
    //将二进制位转换为十进制
    int ret = 0;
    for (int i = 0; i < 32; i++)
    {
        ret = (((unsigned int)ret << 1) | arr[i]);
    }

    //记得释放空间
    free(arr);
    arr = NULL;
    return ret;
}