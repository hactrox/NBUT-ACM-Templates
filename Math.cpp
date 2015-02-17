//********** 大数阶乘 n! **********//
const int Maxn = 10000;
int f[Maxn];
void factorial(int n) // 函数直接输出结果
{
	memset(f, 0, sizeof(f));
	int i, j;
	f[0] = 1;
	for (i = 2;i <= n;i++)
	{
		int cnt = 0;
		for (j = 0;j < Maxn;j++)
		{
			int s = f[j] * i + cnt;
			f[j] = s % 10000;
			cnt = s / 10000;
		}
	}
	for (j = Maxn - 1;j >= 0;j--)
		if(f[j]) break;

	printf("%d",f[j]);
	for (i = j - 1;i >= 0;i--)
		printf("%04d",f[i]);
	printf("\n");
}

//********** 大数取余 **********//
int MOD(char *a, int mod)
{
	int len = strlen(a), re = 0;

	for (int i = 0; i < len; i++)
	{
		re = re * 10 + a[i] - '0';
		re = re % mod;
	}
	return re;
}

//********** 大数除法(char除int, 返回int) **********//
int division(char *src, int n)
{
	int len = strlen(src), i, k, t=0, s=0;
	char dest[1000];
	bool flag = true;    //商是否有了第一个有效位，防止商首部一直出现0    
	for (i = 0, k = 0; i < len; i++)
	{
		t = s * 10 + (src[i] - 48);    //新余数
		if (t/n > 0 || t == 0)        //余数为0要修改商
		{
			dest[k++] = t/n + 48, s = t%n, flag = false;
		}
		else                    //不够除，修改余数
		{
			s = t;
			if(!flag)            //商已经有有效位了，补零
				dest[k++] = '0';
		}
	}
	dest[k] = '\0';
	return atoi(dest);
}
