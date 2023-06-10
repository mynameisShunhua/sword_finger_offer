#define _CRT_SECURE_NO_WARNINGS 1
typedef struct HashNode
{
    int count;//����
    struct HashNode* next;
}HN;
int Hash_Key(int x)
{
    return x + 200000;
}
int find_key(HN** arr, int x, int index)
{
    int key = Hash_Key(x);
    HN* judge = arr[key];
    if (judge == NULL)
    {
        return 0;
    }
    return (judge)->count;
}
void PushBack(HN** arr, int key, int index)
{
    HN* NewNode = (HN*)malloc(sizeof(HN));

    NewNode->count = 0;
    NewNode->next = NULL;
    if (arr[key] == NULL)
    {
        NewNode->count = 1;
        arr[key] = NewNode;
        return;
    }
    else
    {
        HN* cur = arr[key];
        (cur->count)++;
    }
    free(NewNode);
}
//�������һ��,͵������֪������
void Destory(HN** arr)
{

}
int subarraySum(int* nums, int numsSize, int k)
{
    HN** arr = (HN**)malloc(sizeof(HN*) * 30000001);
    memset(arr, 0, sizeof(HN*) * 30000001);
    //���ȼ���Ͳ��������
    int sum = 0;
    int target = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
        target = sum - k;
        int ret = find_key(arr, target, i);
        if (sum == k)
        {
            count++;
        }
        count += ret;
        PushBack(arr, Hash_Key(sum), i);//����Ҫ����ٲ��룬����Ӱ��
    }
    Destory(arr);
    return count;
}