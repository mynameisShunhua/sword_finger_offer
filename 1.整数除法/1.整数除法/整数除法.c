#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��Ŀһ����������
int divide(int a, int b)
{
    //��������������ж�
    if (a == 0x80000000 && b == -1)
    {
        return 0x7FFFFFFF;
    }
    //�ж��̵ķ���
    //��������Ϊ0ʱ��ֱ�ӷ���0����
    if (a == 0)
    {
        return 0;
    }
    //����Ϊ��
    int signal = 1;
    //�ж�Ϊ���������
    if ((a > 0 && b < 0) || (a < 0 && b>0))
    {
        signal = -signal;
    }
    //��ת��Ϊ����
    if (a > 0)
    {
        a = -a;
    }
    if (b > 0)
    {
        b = -b;
    }
    //�������

    //˵���������0x80000000���޷������Σ�������������Ϊunsigned��
    //����轫���ת��Ϊint���͡�
    int sum_count = 0;
    while (a <= b)
    {
        int count = -1;//��Ϊ�˴���-2147483648 1�������
        int cur = b;
        while ((cur >= (int)(0x80000000 - cur)) && a <= cur + cur)
        {
            cur += cur;
            count += count;
        }
        //���±�����
        a = a - cur;
        //�����ܱ���
        sum_count += count;
    }
    return signal == -1 ? sum_count : -sum_count;
}
//��չ�����ӷ�
int add(int nums1, int nums2)
{
    int begin = nums1;
    int process = 0;
    int end = nums2;

    process = end;//Ϊ�˽����һ�ε�ѭ��
    while (process)//��û�н�λ��Ϣ����ֹͣѭ��
    {
        //�Ƚ�����򲻱�����λ��Ϣ
        end = begin ^ process;
        //��ȡ��λ��Ϣ������֮���ǽ�λ
        process = (begin & process) << 1;
        //������һ�ֵļ�����Ϣ
        begin = end;
    }
    return begin;
}

