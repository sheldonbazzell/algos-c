#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int get_max_price(int n, int prices[]);

int main(void)
{
	int prices[] = {1,5,8,9,10,17,17,20};
	int n = 8;
	int x = get_max_price(n, prices);
	printf("%d\n", x);
	return 0;
}

int get_max_price(int n, int prices[])
{
	if (n <= 0)
		return 0;

	int max_value = 0;

	for (int i = 1; i <= n; i++)
		max_value = MAX(max_value, prices[i-1] + get_max_price(n-i, prices));
	
	return max_value;
}