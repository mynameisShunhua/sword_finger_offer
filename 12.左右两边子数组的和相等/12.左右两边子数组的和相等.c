#define _CRT_SECURE_NO_WARNINGS 1
int pivotIndex(int* nums, int numsSize)
{
    int tar_index = -1;

    //��ǰn������֮��
    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }

    int cur_sum = 0;//�͵�����ߵĺ� + �����±�
    for (int i = 0; i < numsSize; i++)
    {
        cur_sum += nums[i];
        //��ߵĺ�
        int left = cur_sum - nums[i];
        //�ұߵĺ�
        int right = sum - cur_sum;
        if (right == left)
        {
            tar_index = i;
            break;
        }
    }
    return tar_index;
}