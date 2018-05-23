#include <set>
#include <ios>
using namespace std;

#define MAX 300003

long long flag[MAX][3]; 
int main()
{

	set< int > L;
	set< int > :: iterator it;
	int num, qtd;
	long long c = 0;
	scanf("%d%d", &qtd, &num);
	L.insert(L.begin(),num);
	printf("%d\n", c);
	while(--qtd)
	{
		scanf("%d", &num);
		it = L.lower_bound(num);
		
		//Verifica se tem um filho na esquerda
		//Se nao tiver, insere
		if(it==L.end())
		{
			L.insert(it,num);
			it--; it--;
			flag[*it][2] = 1;
			flag[num][0] = flag[*it][0]+1;
		}
		//Verifica se tem um filho na direita
		//Se nao tiver, insere
		else if(it==L.begin())
		{
			L.insert(it,num);
			flag[*it][1] = 1;
			flag[num][0] = flag[*it][0]+1;
		}
		//Tinha alguem na esquerda e na direita
		//Caminhando na arvore pra achar o local a 
		//inserir o valor
		else
		{
			L.insert(it,num);
			it--;it--;
			if(!flag[*it][2])
			{
				flag[*it][2] = 1;
				flag[num][0] = flag[*it][0]+1;
			}
			else
			{
				it++;it++;
				flag[*it][1] = 1;
				flag[num][0] = flag[*it][0]+1;
			}
		}
		c += flag[num][0];
		printf("%lld\n", c);
	}
	
	return 0;
}
