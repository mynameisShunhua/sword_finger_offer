#define _CRT_SECURE_NO_WARNINGS 1
int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    //�˻�
    int sum_product = 1;
    //������ĸ���
    int count = 0;
    //��߽�
    int left = 0;
    for (int right = 0; right < numsSize; right++)
    {
        sum_product *= nums[right];
        //�ж��Ƿ����k,������ע��ǰ��left<=right
        while (left <= right && sum_product >= k)
        {
            sum_product /= nums[left++];
        }
        //����sum_product�ض�С��target�����ֻ����������ĸ�������
        count += (right - left + 1);
        //ע�⣺��left -1 == right-> right-left +1 ==0 ʱ��
        //�����պ������ĸ���Ϊ0��

    }
    return count;
}