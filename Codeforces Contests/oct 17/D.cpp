#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 100005;

int a[MAX]; 
ll d[MAX];
bool visit[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	int n, m;
	//freopen("d.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
		a[i] --;
	}
	
	for(int i = 0;i < m; i ++)
		scanf(LL , &d[i]);
		
	int lo = 0, hi = n - 1, mit;
	while(lo < hi){
		mit = lo + hi;
		mit /= 2;
//		cout << lo << " " << hi << " " << mit << endl;
		memset(visit, false, sizeof(visit));
		ll cur = 0;
		int cont = 0;
		for(int i = mit; i >= 0; i --){
			if(a[i] == -1){
				cur ++;
				cur = min(cur, 0ll);
			}
			else{
				int sub = a[i];
				if(visit[sub]){
					cur ++;
					cur = min(cur, 0ll);
				}else{
					cont ++;
					visit[sub] = true;
					cur -= d[sub];
				}
			}
		}
		
	//	cout << "cur " << cur << " " << cont << endl;
		
		if(cur >= 0 && cont == m){
			hi = mit;
		}else{
			lo = mit + 1;
		}
	}
	//cout << "lo dio " << lo << endl;
	memset(visit, false, sizeof(visit));
	ll cur = 0;
	int cont = 0;
	for(int i = lo; i >= 0; i --){
		if(a[i] == -1){
			cur ++;
			cur = min(cur, 0ll);
		}
		else{
			int sub = a[i];
			if(visit[sub]){
				cur ++;
				cur = min(cur, 0ll);
			}else{
				cont ++;
				visit[sub] = true;
				cur -= d[sub];
			}
		}
	}
	
	if(cur >= 0 && cont == m)
		printf("%d\n", lo + 1);
	else
		printf("-1\n");
	
	return 0;
}
