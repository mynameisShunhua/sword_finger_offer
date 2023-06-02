#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//题目一：整数除法
int divide(int a, int b)
{
    //对特殊情况进行判断
    if (a == 0x80000000 && b == -1)
    {
        return 0x7FFFFFFF;
    }
    //判断商的符号
    //当被除数为0时，直接返回0即可
    if (a == 0)
    {
        return 0;
    }
    //假设为正
    int signal = 1;
    //判断为负数的情况
    if ((a > 0 && b < 0) || (a < 0 && b>0))
    {
        signal = -signal;
    }
    //都转换为负数
    if (a > 0)
    {
        a = -a;
    }
    if (b > 0)
    {
        b = -b;
    }
    //运算得商

    //说明：这里的0x80000000是无符号整形，表达会整形提升为unsigned。
    //因此需将结果转换为int类型。
    int sum_count = 0;
    while (a <= b)
    {
        int count = -1;//是为了处理-2147483648 1这种情况
        int cur = b;
        while ((cur >= (int)(0x80000000 - cur)) && a <= cur + cur)
        {
            cur += cur;
            count += count;
        }
        //更新被除数
        a = a - cur;
        //加上总倍数
        sum_count += count;
    }
    return signal == -1 ? sum_count : -sum_count;
}
//拓展整数加法
int add(int nums1, int nums2)
{
    int begin = nums1;
    int process = 0;
    int end = nums2;

    process = end;//为了进入第一次的循环
    while (process)//当没有进位信息，就停止循环
    {
        //先进行异或不保留进位信息
        end = begin ^ process;
        //获取进位信息，左移之后是进位
        process = (begin & process) << 1;
        //更新下一轮的加数信息
        begin = end;
    }
    return begin;
}

