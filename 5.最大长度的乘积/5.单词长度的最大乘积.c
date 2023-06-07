#define _CRT_SECURE_NO_WARNINGS 1
int maxProduct(char** words, int wordsSize)
{
    //开辟并初始化空间
    int* arr = (int*)malloc(sizeof(int) * wordsSize);
    memset(arr, 0, sizeof(int) * wordsSize);
    //将字符串转换为二进制信息
    for (int i = 0; i < wordsSize; i++)
    {
        char* cur = words[i];
        while (*cur != '\0')
        {
            arr[i] |= (1 << (*cur - 'a'));
            cur++;
        }
    }
    //循环遍历
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
    //释放空间
    free(arr);
    arr = NULL;
    return max_product;
}