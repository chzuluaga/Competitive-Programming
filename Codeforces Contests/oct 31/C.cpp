#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 10005;

int a[MAX], b[MAX];
vector< pair<int , char> > ans; 
void no(){
	printf("NO\n");
	exit(0);
}
void solve(int from, int to, int cont){
	int maxi = 0, idx;
	for(int i = from; i <= to; i ++){
		if(a[i] == maxi){
				if(i - 1 >= from && a[i - 1] < a[i])
					idx = i;
				
				if(i + 1 <= to && a[i + 1] < a[i])
					idx = i;
		}
		if(a[i] > maxi){
			maxi = a[i];
			idx = i;
		}
	}
	if(idx - 1 >= from && a[idx - 1] < a[idx]){
		for(int i = idx - 1; i >= from; i --){
			if(a[idx] <= a[i])
				no();
			a[idx] += a[i];
			ans.pb(mp(cont + (i - from) + 2, 'L'));
		}
		
		for(int i = idx + 1; i <= to; i ++){
			if(a[idx] <= a[i])
				no();
			a[idx] += a[i];
			ans.pb(mp(cont + 1, 'R'));
		}
	}else{
		for(int i = idx + 1; i <= to; i ++){
			if(a[idx] <= a[i])
				no();
			a[idx] += a[i];
			ans.pb(mp(cont + idx - from + 1, 'R'));
		}
		
		for(int i = idx - 1; i >= from; i --){
			if(a[idx] <= a[i])
				no();
			a[idx] += a[i];
			ans.pb(mp(cont + (i - from) + 2, 'L'));
		}
	}
}


int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, k;
	
  scanf("%d", &n);
  for(int i = 0; i < n; i ++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i ++)
		scanf("%d", &b[i]);
		
	int sum = 0, pos = 0, cont = 0, prev = 0;
	for(int i = 0; i < n; i ++){
		if(pos >= k || sum > b[pos])
			no();
		sum += a[i];
		if(sum == b[pos]){
			solve(prev, i, cont);
			sum = 0;
			cont ++;
			prev = i + 1;
			pos ++;
		}
	}
	if(pos < k)
		no();
		
	printf("YES\n");
	for(int i = 0; i < (int) ans.size(); i ++)
		printf("%d %c\n", ans[i].first, ans[i].second);
	

  return 0;
}
