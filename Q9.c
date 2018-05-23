#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l, //linhas
	    	c, //colunas
	    	p; //pontacao
	    	
		scanf("%d%d",&l,&c);
		
		p = 2*c*l-l-c;
		printf("%d\n",p);
	}
return 0;
}
