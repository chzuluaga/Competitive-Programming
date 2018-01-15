#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 30005;
int parent[MAX], rnk[MAX], cmp[MAX], menor, mayor;
int find(int x){
	if(x == parent[x])
		return x;
	
	return parent[x] = find(parent[x]);
}

void merge(int x, int y){
	
	x = find(x);
	y = find(y);
	if(x == y)
		return;
		
	if(rnk[x] > rnk[y]){
		parent[y] = x;
		cmp[x] += cmp[y];
		mayor = max(cmp[x], mayor);
	}else{
		parent[x] = y;
		cmp[y] += cmp[x];
		mayor = max(cmp[y], mayor);
		if(rnk[x] == rnk[y])
			rnk[y] ++;
	}
	
	
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n, u, v;
  
  scanf("%d", &n);
  menor = n * 2 + 2;
  mayor = 2;
  for(int i = 0; i < 2 * n + 2; i ++)
		parent[i] = i, rnk[i] = 0, cmp[i] = 1;
  
  for(int i = 0; i < n; i++){
		scanf("%d %d",&u, &v);
		merge(u,v);
	}
	
	for(int i = 0; i <= 2 * n; i ++){
		int x = find(i);
		if(cmp[x] > 1)
			menor = min(menor, cmp[x]);
	}
	printf("%d %d\n", menor, mayor);

  return 0;
}
