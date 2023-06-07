#define _CRT_SECURE_NO_WARNINGS 1
int maxProduct(char** words, int wordsSize)
{
    //���ٲ���ʼ���ռ�
    int* arr = (int*)malloc(sizeof(int) * wordsSize);
    memset(arr, 0, sizeof(int) * wordsSize);
    //���ַ���ת��Ϊ��������Ϣ
    for (int i = 0; i < wordsSize; i++)
    {
        char* cur = words[i];
        while (*cur != '\0')
        {
            arr[i] |= (1 << (*cur - 'a'));
            cur++;
        }
    }
    //ѭ������
    int max_product = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = i + 1; j < wordsSize; j++)
        {
            if ((arr[i] & arr[j]) == 0)
            {
                int len_i = strlen(words[i]);
                int len_j = strlen(words[j]);
                int product = len_i * len_j;
                if (product > max_product)
                {
                    max_product = product;
                }
            }
        }
    }
    //�ͷſռ�
    free(arr);
    arr = NULL;
    return max_product;
}