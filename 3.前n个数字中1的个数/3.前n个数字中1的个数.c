#define _CRT_SECURE_NO_WARNINGS 1
//①方法1——遍历
int* countBits(int n, int* returnSize)
{
    //开辟数组
    int* arr = (int*)malloc(sizeof(arr) * (n + 1));
    *returnSize = n + 1;
    memset(arr, 0, sizeof(arr) * (*returnSize));
    //遍历求解
    for (int i = 0; i < n + 1; i++)
    {
        int count = 0;
        //每一位都要按位与1
        for (int j = 0; j < 32; j++)
        {
            if (((i >> j) & 1) == 1)
            {
                count++;
            }
        }
        arr[i] = count;
    }
    return arr;
}
//②方法2——i& (i - 1)
int* countBits(int n, int* returnSize)
{
    //开辟数组
    int* arr = (int*)malloc(sizeof(arr) * (n + 1));
    *returnSize = n + 1;
    memset(arr, 0, sizeof(arr) * (*returnSize));
    for (int i = 0; i < n + 1; i++)
    {
        int tmp_i = i;
        int count = 0;
        while (tmp_i)
        {
            count++;
            tmp_i &= (tmp_i - 1);
        }
        arr[i] = count;
    }
    return arr;
}
//③方法3——i& (i - 1)的优化
int* countBits(int n, int* returnSize)
{
    //开辟数组
    int* arr = (int*)malloc(sizeof(arr) * (n + 1));
    *returnSize = n + 1;
    memset(arr, 0, sizeof(arr) * (*returnSize));
    for (int i = 1; i < n + 1; i++)
    {
        arr[i] = arr[i & (i - 1)] + 1;
    }
    return arr;
}
//④方法4——奇偶分类
int* countBits(int n, int* returnSize)
{
    //开辟数组
    int* arr = (int*)malloc(sizeof(arr) * (n + 1));
    *returnSize = n + 1;
    memset(arr, 0, sizeof(arr) * (*returnSize));
    //运算思路
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = arr[i >> 1] + (i & 1);
        //说明：位运算的优先级很低，所以这里i&1必须加括号！
    }
    return arr;
}
