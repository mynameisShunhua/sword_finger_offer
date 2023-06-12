#define _CRT_SECURE_NO_WARNINGS 1
typedef struct HashNode
{
    int i;//�±�λ��
    struct HashNode* next;
}HN;
int Hash_Key(int x)
{
    return x + 100000;
}
int find_key(HN** arr, int x, int index)
{
    int key = Hash_Key(x);
    HN* judge = arr[key];
    if (judge == NULL)
    {
        return -1;
    }
    int smaller = -1;
    HN* cur = arr[key];
    int i = cur->i;
    if (i < index)
    {
        smaller = i;
    }
    return smaller;
}
void PushBack(HN** arr, int key, int index)
{
    HN* NewNode = (HN*)malloc(sizeof(HN));
    NewNode->i = index;
    NewNode->next = NULL;
    if (arr[key] == NULL)
    {
        arr[key] = NewNode;
        return;
    }
    //��Ϊ��index�ǵ����ģ����Բ���Ҫ�ٽ����ж��ˣ�ֱ��free����
    // else
    // {
    //     HN* cur = arr[key];
    //     if(index<cur->i)
    //     {
    //         cur->i = index;
    //     }
    // }
    free(NewNode);
}
//�������һ��
void Destory(HN** arr)
{
}
int findMaxLength(int* nums, int numsSize)
{
    HN** arr = (HN**)malloc(sizeof(HN*) * 200001);
    memset(arr, 0, sizeof(HN*) * 200001);

    int sum = 0;
    int target = 0;
    int max_len = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i] == 0 ? -1 : 1;
        target = sum;
        int left = find_key(arr, target, i);
        if (left != -1)
        {
            int len = i - left;//���ұ�
            if (len > max_len)
            {
                max_len = len;
            }
        }
        if (sum == 0)
        {
            max_len = i + 1;
        }
        //����Ҫ����ٲ��룬����Ӱ��
        PushBack(arr, Hash_Key(sum), i);
    }
    Destory(arr);
    return max_len;
}