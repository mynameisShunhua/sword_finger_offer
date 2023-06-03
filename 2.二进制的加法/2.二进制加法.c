#define _CRT_SECURE_NO_WARNINGS 1
void reverse(char* string, int right)
{
    int left = 0;
    while (left <= right)
    {
        char tmp = string[left];
        string[left] = string[right];
        string[right] = tmp;
        left++;
        right--;
    }
}
char* addBinary(char* a, char* b)
{
    //开辟指定目标字符串的空间
    int len_a = strlen(a);
    int len_b = strlen(b);
    int size = len_a > len_b ? len_a + 2 : len_b + 2;
    char* string = (char*)malloc(sizeof(char) * size);
    //初始化字符串
    memset(string, 0, sizeof(char) * size);
    int end = -1;//最后一个位置的下标
    //求进位信息
    char* string_a = a;
    char* string_b = b;
    //表示最后一位的下标
    len_a--;
    len_b--;
    //进位信息
    int carry = 0;

    while (len_a >= 0 || len_b >= 0)
    {
        //获取指定位的信息
        //可能有len_a和len_b为负的情况
        int add_a = len_a >= 0 ? a[len_a] - '0' : 0;
        int add_b = len_b >= 0 ? b[len_b] - '0' : 0;
        //结果位的信息
        int cur = add_a ^ add_b ^ carry;
        //进位信息
        carry = (add_a & add_b) | ((add_a | add_b) & carry);
        //将结果位加到指定字符串
        string[++end] = cur + '0';
        //printf("%c",string[end]);
        //调整len_a和len_b
        len_a--;
        len_b--;
    }
    //最后一次是否有进位
    if (carry == 1)
    {
        string[++end] = '1';
    }
    //逆转字符串
    reverse(string, end);
    return string;
}