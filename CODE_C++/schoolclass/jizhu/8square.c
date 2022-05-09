#include <stdio.h>
#include <math.h>
int main()
{
    int n1 = 27;
    int a[64] = {0}; //数组a，用于存n1转化为二进制后的原码
    int c[64] = {0}; //数组c，用来存n1*n1转化为二进制的原码

    n1 = abs(n1);

    int num1 = 0; /*num1用来计算n1转化为二进制后的码位，如4二进制：100，对应码位：3 （PS:这里的“码位”是笔者自己编的，不要混淆了）*/

    while (n1 > 0)//大端
    {
        if (n1 > 0)
        {
            if (n1 % 2 != 0)
            {
                a[num1] = 1;
            }
            n1 = n1 >> 1;
            num1++;
        }
    }
    int i, i2, j; //循环变量
    int k;        // c数组的指针

    for (int i = 0; i < num1; i++)
    {
        k = i;//下面右移
        for (int j = 0; j < num1; j++)//相加
        {
            c[k] = c[k] + (a[i] & a[j]);
            if (c[k] > 1)
            {
                c[k] = c[k] % 2; //用数组进行乘运算
                c[k + 1]++;
            }
            k++;
        }
    }

    /*c数组在计算中有可能会进位，例如：a:（11111）2*b:（111）2 a码位：5，b码位：3 若结果未进位，结果码位应为：5+2=7 对应数组中：0~6
                                      但是，结果进位了，11111
                                                       11111
                                                      1011101
                                                      11111
                                                     11011001  此时结果码位为：8，对应数组0~7     （PS:这里的“码位”是笔者自己编的，不要混淆了）
    */

    i2 = num1 + num1 - 1; // i2指向进位位
    if (c[i2] == 0)
    {
        i2 = i2 - 1; /*判断是否进位：指针先指向进位位，如果进位位为0，说明没有进位，指针前移一位 */
    }

    i=i2;
    //循环打印结果。解题思想：参考《计算机组成原理》第70页
    for (; i2 >= 0; i2--)
    {
        printf("%d", c[i2]);
    }
    int ans=0,tmp=1;
    for(i2=0;i2<=i;i2++)
    {
        if(c[i2]==1)
            ans=ans+tmp;
        tmp=tmp<<1;
    }
    printf("%d",ans);
    return 0;
}


/**
 *平方
#include<stdio.h>

int main()
{
	int n = 27;
	int a[8];
	int b[16];
	int ans;
	int num = 0;
	
	while(n>0)
	{
		if(n%2 !=0)
		{
			a[num]=1;
		}
		n = n >> 1;
		num++;
	}

	int k=0;
	for(int i=0;i<num;i++)
	{
		k = i;
		for(int j=0;j<num;j++)
		{
			b[k] = b[k] + (a[i] & a[j]);
			if(b[k] > 1)
			{
				b[k] = b[k] %2;
				if(k < 15)
				{
					b[k + 1]++;
			
				}
			}
			k++;
		}
	}

	int tmp = 1;
	for(int i=0;i<16;i++)
	{
		if(b[i]==1)
		{
			ans=ans+tmp;
		}
		tmp = tmp<<1;
	}
	printf("%d",ans);
	return 0
}
*/
