#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl "\n"
using namespace std;
typedef long long ll;
const int MAX = 200005;
struct tshirt{
		int price, a , b;
}arr[MAX];
vector<int> v[4];
int vis[MAX];

bool cmp(int x, int y){
	return arr[x].price < arr[y].price;
}
int main(){
  int n, m, x;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++)
		scanf("%d", &arr[i].price);
  for(int i = 0; i < n; i++)
		scanf("%d", &arr[i].a);
	for(int i = 0; i < n; i ++)
		scanf("%d", &arr[i].b);
		
		
	for(int i = 0; i < n; i ++){
		v[arr[i].a - 1].pb(i);
		if(arr[i].a == arr[i].b)	continue;
		
		v[arr[i].b - 1].pb(i);
		
	}

	sort(v[0].begin(), v[0].end(), cmp);
	sort(v[1].begin(), v[1].end(), cmp);
	sort(v[2].begin(), v[2].end(), cmp);
	int p[4];
	p[0] = p[1] = p[2] = 0;
	
	scanf("%d", &m);
	
	for(int i = 0; i < m; i ++){
		scanf("%d", &x);
		x --;
		while(p[x] < (int) v[x].size() && vis[v[x][p[x]]]){
			p[x] ++;
		}
		if(p[x] >= (int) v[x].size())
			printf("-1\n");
		else{
			printf("%d\n", arr[v[x][p[x]]].price);
			vis[v[x][p[x]]] = 1;
		}
		
	}
	
  
  

  return 0;
}
