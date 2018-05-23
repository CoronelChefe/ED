#include <stdio.h>

char s[10001];
int i;

int max(int p, int q);
int comprim();

int main()
{
	int qtd; 
	scanf("%d", &qtd);

	while (qtd--)
	{
		scanf("%s", s);
		i = 0;
		printf("%d\n", comprim() - 1);
	}
	return 0;
}

int max(int p, int q)
{
	return p > q ? p : q;
}
int comprim()
{
	if (s[i++] == 'l')
		return 1;
 
	else
		return max(comprim(), comprim()) + 1;
}
