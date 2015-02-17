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

