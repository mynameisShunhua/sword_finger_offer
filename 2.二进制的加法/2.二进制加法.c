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
    //����ָ��Ŀ���ַ����Ŀռ�
    int len_a = strlen(a);
    int len_b = strlen(b);
    int size = len_a > len_b ? len_a + 2 : len_b + 2;
    char* string = (char*)malloc(sizeof(char) * size);
    //��ʼ���ַ���
    memset(string, 0, sizeof(char) * size);
    int end = -1;//���һ��λ�õ��±�
    //���λ��Ϣ
    char* string_a = a;
    char* string_b = b;
    //��ʾ���һλ���±�
    len_a--;
    len_b--;
    //��λ��Ϣ
    int carry = 0;

    while (len_a >= 0 || len_b >= 0)
    {
        //��ȡָ��λ����Ϣ
        //������len_a��len_bΪ�������
        int add_a = len_a >= 0 ? a[len_a] - '0' : 0;
        int add_b = len_b >= 0 ? b[len_b] - '0' : 0;
        //���λ����Ϣ
        int cur = add_a ^ add_b ^ carry;
        //��λ��Ϣ
        carry = (add_a & add_b) | ((add_a | add_b) & carry);
        //�����λ�ӵ�ָ���ַ���
        string[++end] = cur + '0';
        //printf("%c",string[end]);
        //����len_a��len_b
        len_a--;
        len_b--;
    }
    //���һ���Ƿ��н�λ
    if (carry == 1)
    {
        string[++end] = '1';
    }
    //��ת�ַ���
    reverse(string, end);
    return string;
}