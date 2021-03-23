#include<stdio.h>
int main(void)
{
    char str1[6],str2[6];
    for(int i=0;i<6;i++)
    {
        scanf("%c",&str1[i]);
    }
    for(int i=0;i<6;i++)
    {
        scanf("%c",&str2[i]);
    }
    char arr1[3][2],arr2[3][2];
    arr1[0][0]=str1[0];
    arr1[0][1]=str1[5];
    arr2[0][0]=str2[0];
    arr2[0][1]=str2[5];
    arr1[1][0]=str1[1];
    arr1[1][1]=str1[4];
    arr1[2][0]=str1[2];
    arr1[2][1]=str1[3];
    arr2[1][0]=str2[1];
    arr2[1][1]=str2[4];
    arr2[2][0]=str2[2];
    arr2[2][1]=str2[3];
    for(int i=0;i<3;i++)//找第一对面的对应
    {
        if(arr1[0][0]==arr2[i][0])//1
        {
            if(arr1[0][1]==arr2[i][1])
            {
                for(int j=0;j<3;j++)//第二
                {
                    if(arr1[1][0]==arr2[j][0]&&j!=i)//1
                    {
                        if(arr1[1][1]==arr2[j][1])
                        {
                            for(int k=0;k<3;k++)//第三
                            {
                                if(arr1[2][0]==arr2[k][1]&&k!=i&&k!=j)//1
                                {
                                    if(arr1[2][1]==arr2[k][1])printf("Yes!\n");
                                }
                                else if(arr1[2][1]==arr2[k][1]&&k!=i&&k!=j)//2
                                {
                                    if(arr1[2][0]==arr2[k][1])printf("Yes!\n");
                                }
                            }
                        }
                    }
                    if(arr1[1][1]==arr2[j][0]&&j!=i)//2
                    {
                        if(arr1[1][0]==arr2[j][1])
                        {
                            for(int k=0;k<3;k++)//第三
                            {
                                if(arr1[2][0]==arr2[k][1]&&k!=i&&k!=j)//1
                                {
                                    if(arr1[2][1]==arr2[k][1])printf("Yes!\n");
                                }
                                else if(arr1[2][1]==arr2[k][1]&&k!=i&&k!=j)//2
                                {
                                    if(arr1[2][0]==arr2[k][1])printf("Yes!\n");
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(arr1[0][1]==arr2[i][0])//2
        {
            if(arr1[0][0]==arr2[i][1])
            {
                for(int j=0;j<3;j++)//第二
                {
                    if(arr1[1][0]==arr2[j][0]&&j!=i)//1
                    {
                        if(arr1[1][1]==arr2[j][1])
                        {
                            for(int k=0;k<3;k++)//第三
                            {
                                if(arr1[2][0]==arr2[k][1]&&k!=i&&k!=j)//1
                                {
                                    if(arr1[2][1]==arr2[k][1])printf("Yes!\n");
                                }
                                else if(arr1[2][1]==arr2[k][1]&&k!=i&&k!=j)//2
                                {
                                    if(arr1[2][0]==arr2[k][1])printf("Yes!\n");
                                }
                            }
                        }
                    }
                    if(arr1[1][1]==arr2[j][0]&&j!=i)//2
                    {
                        if(arr1[1][0]==arr2[j][1])
                        {
                            for(int k=0;k<3;k++)//第三
                            {
                                if(arr1[2][0]==arr2[k][1]&&k!=i&&k!=j)//1
                                {
                                    if(arr1[2][1]==arr2[k][1])printf("Yes!\n");
                                }
                                else if(arr1[2][1]==arr2[k][1]&&k!=i&&k!=j)//2
                                {
                                    if(arr1[2][0]==arr2[k][1])printf("Yes!\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}