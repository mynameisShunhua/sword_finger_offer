#define _CRT_SECURE_NO_WARNINGS 1
//�ٷ���1��������
int* countBits(int n, int* returnSize)
{
    //��������
    int* arr = (int*)malloc(sizeof(arr) * (n + 1));
    *returnSize = n + 1;
    memset(arr, 0, sizeof(arr) * (*returnSize));
    //�������
    for (int i = 0; i < n + 1; i++)
    {
        int count = 0;
        //ÿһλ��Ҫ��λ��1
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
//�ڷ���2����i& (i - 1)
int* countBits(int n, int* returnSize)
{
    //��������
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
//�۷���3����i& (i - 1)���Ż�
int* countBits(int n, int* returnSize)
{
    //��������
    int* arr = (int*)malloc(sizeof(arr) * (n + 1));
    *returnSize = n + 1;
    memset(arr, 0, sizeof(arr) * (*returnSize));
    for (int i = 1; i < n + 1; i++)
    {
        arr[i] = arr[i & (i - 1)] + 1;
    }
    return arr;
}
//�ܷ���4������ż����
int* countBits(int n, int* returnSize)
{
    //��������
    int* arr = (int*)malloc(sizeof(arr) * (n + 1));
    *returnSize = n + 1;
    memset(arr, 0, sizeof(arr) * (*returnSize));
    //����˼·
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = arr[i >> 1] + (i & 1);
        //˵����λ��������ȼ��ܵͣ���������i&1��������ţ�
    }
    return arr;
}
