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
	return 0;
}