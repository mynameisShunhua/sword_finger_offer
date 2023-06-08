#define _CRT_SECURE_NO_WARNINGS 1
//���ٴ��롪��˫ָ��
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    //���ٿռ䲢��ʼ������
    int* arr = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    memset(arr, 0, sizeof(int) * 2);
    //˫ָ�����˼·
    int left = 0;
    int right = numbersSize - 1;
    while (left < right)
    {
        int sum = numbers[left] + numbers[right];
        if (sum > target)
        {
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            arr[0] = left;
            arr[1] = right;
            break;
        }
    }

    return arr;
}
//���ڴ��롪�����ֲ���
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    //���ٿռ䲢��ʼ������
    int* arr = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    memset(arr, 0, sizeof(int) * 2);
    //���ֲ���˼·
    for (int i = 0; i < numbersSize; i++)
    {
        //����߿�ʼ
        int left = i + 1;
        int right = numbersSize - 1;
        int mid = (left + right) / 2;
        int Target = target - numbers[i];
        int flag = 0;
        while (left <= right)//�����ǿ�����ȵģ���Ϊ��Ҫ�ҵ���һ����
        {
            if (numbers[mid] > Target)
            {
                right = mid - 1;
            }
            else if (numbers[mid] < Target)
            {
                left = mid + 1;
            }
            else
            {
                flag = 1;
                break;
            }
            //����mid
            mid = (left + right) / 2;
        }
        if (flag)
        {
            arr[0] = i;
            arr[1] = mid;
            break;
        }
    }

    return arr;
}