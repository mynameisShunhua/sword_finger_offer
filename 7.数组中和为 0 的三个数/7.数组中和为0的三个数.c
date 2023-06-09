#define _CRT_SECURE_NO_WARNINGS 1
int my_cmp(int* e1, int* e2)
{
    return *e1 - *e2;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    //����˵�����ǣ�returnColumnSizes��ָ��һά�����ָ���ָ�룬
    //��ΪҪ�޸�ָ���ָ������Ҫ����ȥ����ָ�룡

    //��һ������������������򡪡�����
    qsort(nums, numsSize, sizeof(int), my_cmp);
    //�ڶ�������������һ����ά����

    //����:
    //һ��һ�ο���Ч�ıȽϴ󡪡�realloc
    //��˿���һ���Ӱѿռ俪��������ô������������������п����Ծ�Ϊ
    //������numsSize��ѡ3��������
    //���Ϊ����numsSize*(numsSize-1)/(3*2*1)
    int size = numsSize * (numsSize - 1) / 6;
    int** arr = (int**)malloc(sizeof(int*) * size);
    *returnSize = 0;//*returnSize��ʾ�ж�����
    int cur_size = 0;
    //��������������ָ��������

    //����:
    //����nums[i]+nums[j]+nums[k]==0����>-nums[i] = nums[j]+nums[k]
    //-nums[i]Ϊ�̶���ֵ����ô�����ҵľ��� nums[j]+nums[k] = -nums[i]
    //˵���������numsize-2˵�������ʣ������Ԫ�ؾͲ��ý�ȥ�ˣ�û��Ҫ��
    for (int i = 0; i < numsSize - 2;)
    {
        //����Ҫ�ҵ�����
        int  target = -nums[i];

        //˫ָ����в���
        int left = i + 1;
        int right = numsSize - 1;
        //printf("hehe");
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum > target)
            {
                right--;//��С
            }
            else if (sum < target)
            {
                left++;//����
            }
            else
            {
                //�ҵ���
                int va_l = nums[left];
                int va_r = nums[right];
                //����һ��һά������д洢
                int* tmp = (int*)malloc(sizeof(int) * 3);
                tmp[0] = nums[i];
                tmp[1] = nums[left];
                tmp[2] = nums[right];
                //printf("%d",tmp[0]);
                arr[cur_size++] = tmp;
                *returnSize = cur_size;
                //��������
                //��Ϊ�������ظ������ԭ���Ǵ�����ȵ�ֵ�����������Ҫ����
                while (left < right && nums[right] == va_r)
                {
                    right--;
                }
                //�����left���Բ��ö�����ΪֻҪһ�����ˣ��ͻᵼ������sum
                //Ҳ��䣬֮���ѭ���ͻᵼ��leftҲ���ű䡣
            }
        }
        int va_i = nums[i];
        //����target����ȵ�Ԫ�ء�
        while ((i < numsSize - 2) && (nums[i] == va_i))
        {
            i++;//���ٽ�һ��ѭ����
        }
    }
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++)
    {
        (*returnColumnSizes)[i] = 3;
    }
    return arr;
}