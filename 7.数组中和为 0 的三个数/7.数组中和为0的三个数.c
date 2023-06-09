#define _CRT_SECURE_NO_WARNINGS 1
int my_cmp(int* e1, int* e2)
{
    return *e1 - *e2;
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    //首先说明的是：returnColumnSizes是指向一维数组的指针的指针，
    //因为要修改指针的指向，所以要传进去二级指针！

    //第一步——将数组进行排序——升序
    qsort(nums, numsSize, sizeof(int), my_cmp);
    //第二步——将开辟一个二维数组

    //分析:
    //一次一次开的效耗比较大——realloc
    //因此可以一下子把空间开够——那么数组中三个成组的所有可能性就为
    //——从numsSize中选3个不排序
    //因此为——numsSize*(numsSize-1)/(3*2*1)
    int size = numsSize * (numsSize - 1) / 6;
    int** arr = (int**)malloc(sizeof(int*) * size);
    *returnSize = 0;//*returnSize表示有多少行
    int cur_size = 0;
    //第三步——查找指定的数字

    //分析:
    //根据nums[i]+nums[j]+nums[k]==0——>-nums[i] = nums[j]+nums[k]
    //-nums[i]为固定的值，那么我们找的就是 nums[j]+nums[k] = -nums[i]
    //说明：这里的numsize-2说的是最后剩下两个元素就不用进去了，没必要。
    for (int i = 0; i < numsSize - 2;)
    {
        //这是要找的条件
        int  target = -nums[i];

        //双指针进行查找
        int left = i + 1;
        int right = numsSize - 1;
        //printf("hehe");
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum > target)
            {
                right--;//调小
            }
            else if (sum < target)
            {
                left++;//调大
            }
            else
            {
                //找到了
                int va_l = nums[left];
                int va_r = nums[right];
                //开辟一个一维数组进行存储
                int* tmp = (int*)malloc(sizeof(int) * 3);
                tmp[0] = nums[i];
                tmp[1] = nums[left];
                tmp[2] = nums[right];
                //printf("%d",tmp[0]);
                arr[cur_size++] = tmp;
                *returnSize = cur_size;
                //调整部分
                //因为可能有重复多个，原因是存在相等的值，所以如果有要跳过
                while (left < right && nums[right] == va_r)
                {
                    right--;
                }
                //这里的left可以不用动，因为只要一个动了，就会导致最后的sum
                //也会变，之后的循环就会导致left也跟着变。
            }
        }
        int va_i = nums[i];
        //跳过target的相等的元素。
        while ((i < numsSize - 2) && (nums[i] == va_i))
        {
            i++;//至少进一次循环。
        }
    }
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++)
    {
        (*returnColumnSizes)[i] = 3;
    }
    return arr;
}