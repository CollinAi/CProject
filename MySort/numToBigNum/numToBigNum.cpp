// numToBigNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string ConvertMoneyCaps(long double moneySum)
{
    long int temp_i = (long int)moneySum;  /**//* 整数部分 */
    float temp_f = moneySum - temp_i; /**//* 小数部分 */
    int digit = 0, i, j, k, num_i;
    string money("");
    char num[20] ="", * p=NULL;
    char name[][3] = { "元","拾","佰","仟","万","亿" };
    char numchar[][3] = { "零","壹","贰","叁","肆","伍","陆","柒","捌","玖" };
    _itoa_s(temp_i, num, 10);  /**//* 整数部分转换成字符串后在处理 */
    p = num;
    digit = strlen(num);            /**//* 整数部分位数 */
    /**//*--------处理整数部分 start--------*/
    for (i = 1; i <= digit; i++)
    {
        k = (digit - i) % 4;
        if (isdigit(*p))
        {
            num_i = *p & 0xF; /* 把字符转换成数字,比如 '0'-> 0,'1' -> 1*/
            /**//*--------转换数字开始---------*/
            if (num_i)
            {
                money = money + numchar[num_i];
            }
            else
            {
                if (k && (*(p + 1) & 0xF))
                    money += "零";
            }
            /**//*--------转换数字结束-------*/
            /**//*---------添加计数单位开始----*/
            if (k)
            {
                if (num_i)
                    money = money + name[k];
            }
            else
            {
                j = digit - i;
                if (j)
                    money = money + name[j / 4 + 3];
                else
                    money += "元";
            }
            /**//*--------添加计数单位结束--------*/
            p++;
        }
        else
        {
            money = "遇到非数字退出!";
            return money;
        }
    }
    /**//*--------处理整数部分 End --------*/
    /**//*--------处理小数部分 start--------*/
    if (temp_f > 0.01)
    {
        if ((int)(temp_f * 10)) money = money + numchar[(int)(temp_f * 10)] + "角";
        if ((int)(temp_f * 100) % 10) money = money + numchar[(int)(temp_f * 100) % 10] + "分";
    }
    /**//*--------处理小数部分 End--------*/
    money += "整";

    return money;
}



int Atoi(string s, int radix)    //s是给定的radix进制字符串
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char t = s[i];
        if (t >= '0' && t <= '9') ans = ans * radix + t - '0';
        else ans = ans * radix + t - 'a' + 10;
    }
    return ans;
}

string intToA(int n, int radix)    //n是待转数字，radix是指定的进制
{
    string ans = "";
    do {
        int t = n % radix;
        if (t >= 0 && t <= 9)	ans += t + '0';
        else ans += t - 10 + 'a';
        n /= radix;
    } while (n != 0);	//使用do{}while（）以防止输入为0的情况
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    long double x = 33.20;
    cout << "please input the money:";
    cin >> x;
    cout << "Convert Money Caps:";
    string money = ConvertMoneyCaps(x);
    cout << money << endl;


    int num = 10;
    string str;
    str = intToA(num, 2);  //c++中一般用_itoa，用itoa也行,
    printf("%s\n", str.c_str());
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
