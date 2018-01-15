#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
int a[MAX], pos[MAX];
int visit[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
		a[i] --;
		pos[a[i]] = i;
	}
	int big = 1;
	for(int i = 0; i < n; i ++){
		if(visit[i])
			continue;
		visit[i] = 1;
		int cur = pos[i];
		int x = i, cont = 1;
		while(pos[x + 1] > cur){
			x ++;
			visit[x] = 1;
			cur = pos[x];
			cont ++;
		}
		big = max(cont, big);
	}
	printf("%d\n", n - big);
	return 0;
}
