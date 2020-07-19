#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
long long a[500005];
int dp1[500005], dp2[500005];
int main()
{
	int i, j, m, n, temp1, temp2;
	long long ans, pre, temp;
	std::cin >> n; ans = 0;
	for (i = 1; i <= n; i++)
	{
		std::cin >> a[i];
		ans += a[i];
	}
	if (ans % 3 != 0)
		std::cout << "0" << endl;
	else
	{
		temp1 = temp2 = 1;
		pre = ans / 3;
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			ans = ans + a[i];
			if (ans == pre&&i <= n - 2)
				dp1[temp1++] = i;
			if (ans == 2 * pre&&i <= n - 1)
				dp2[temp2++] = i;
		}
		temp1--; temp2--;
		temp = 0;
		for (i = 1; i <= temp1; i++)
		{
			for (j = 1; j <= temp2; j++)
			{
				if (dp2[j] > dp1[i])
				{
					temp = temp + temp2 - j + 1;
					break;
				}
			}
		}
		cout << temp << endl;
	}
	return 0;
}