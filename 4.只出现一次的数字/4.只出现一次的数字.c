#define _CRT_SECURE_NO_WARNINGS 1
int singleNumber(int* nums, int numsSize)
{
    //���ٲ���ʼ���ռ�
    int* arr = (int*)malloc(sizeof(int) * 32);
    memset(arr, 0, sizeof(int) * 32);
    //��ȡÿһλ��λ��
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
    //��ÿһλģ3��ȡֻ����1�ε����ֵĶ�����λ

    for (int i = 0; i < 32; i++)
    {
        arr[i] = arr[i] % 3;
    }
    //��������λת��Ϊʮ����
    int ret = 0;
    for (int i = 0; i < 32; i++)
    {
        ret = (((unsigned int)ret << 1) | arr[i]);
    }

    //�ǵ��ͷſռ�
    free(arr);
    arr = NULL;
    return ret;
}