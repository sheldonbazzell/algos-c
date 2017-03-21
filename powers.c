#include <stdio.h>
int powers(int x, int n);
int main(void)
{
	int X, n;
	printf("In computing X to the nth power, enter X:\n");
	scanf("%d", &X);
	printf("Now enter n:\n");
	scanf("%d", &n);
	int result = powers(X, n);
	printf("%d\n", result);
}

int powers(int x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n %2 != 0)
	{
		int y = powers(x,(n-1)/2);
		return x * y * y;
	}
	else
	{
		int y = powers(x,n/2);
		return y * y;
	}
}