#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%I64d"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 200005;
ll a[MAX], tmp[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n, k;
  ll x;
  //freopen("array.in", "r", stdin);
  scanf("%d%d" LL, &n, &k, &x);
  int neg = 0;
  ll le = 1e9 + 2;
  int idx = 0;
  for(int i = 0; i < n; i ++){
		scanf(LL, &a[i]);
		tmp[i] = a[i];
		if(a[i] < 0)
			neg ++;
		ll cur = abs(a[i]);
		if(cur < le){
			le = cur;
			idx = i;
		}
	}
	
	
	if(neg % 2 == 0){
		if(a[idx] >= 0){
			while(k > 0 && a[idx] >= 0){
				k --;
				a[idx] -= x;
			}
		}else{
			while(k > 0 && a[idx] <= 0){
				k --;
				a[idx] += x;
			}
		}
	}
	priority_queue< pll > q;
	
	for(int i = 0; i < n; i ++)
			q.push( mp( -abs(a[i]) , i ) ) ;
	
	
	while(!q.empty() && k > 0){
		k --;
		ll cur = q.top().second;
		ll val = q.top().first;
		//cout << k << " " << cur << " " << -val << endl;
		q.pop();
		val = a[cur];
		
		if(val < 0)
			val -= x;
		else
			val += x;
		
		a[cur] = val;
		q.push( mp( -abs(val) ,cur) );
	}
  /*for(int i = 0; i < n; i++){
		int d = abs(a[i] - tmp[i]);
		if(d % x != 0){
			cout << a[i] << " " << tmp[i] << " " << i << endl;
			return 0;
		}
	}*/
  
  for(int i = 0; i < n; i++)
		printf(LL " ", a[i]);
	
	printf("\n");

  return 0;
}
