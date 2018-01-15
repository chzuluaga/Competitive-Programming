#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define LL "%lld"
using namespace std;
typedef long long ll;
const int MAX = 1234567;

ll bit[MAX];
int n, k;
ll add(ll x, ll y){return (x + y) % n;}
ll sub(ll x, ll y){return (x - y + n) % n;}

ll get(int x){
	ll sum = 0;
	for(int i = x; i ; i -= (i&-i))
		sum += bit[i];
	return sum;
}

void update(int x, ll val){
	for(int i = x; i <= n; i += (i&-i)){
		bit[i] +=  val;
	}
}
int getCWDis(int from, int to){
	while(to < from)
		to += n;
		
	return to - from;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	scanf("%d%d", &n, &k);
	
	ll cur = 0;
	ll ans = 1;
	for(int i = 0; i < n; i ++){
		ll nxt = (cur + k);
		//cout << cur << " nxt = " << nxt << endl;
		ll lines = 0, from = 0, to = 0;
		//clockwise distance
		ll d = getCWDis(nxt, cur);
		from = (cur + 1), to = min(nxt - 1, cur + d - 1);
		from %= n;
		to = sub(to, 0);
		//cout << "Salen " << from << " " << to << endl;
		from ++, to ++;
		if(to < from){
			lines += get(n) - get(from - 1) + get(to);
		}else{
			lines += get(to) - get(from - 1);
		}
		to = cur - 1;
		if(to < n) to += n;
		from = max(nxt + 1, to - k + 2);
		from %= n;
		to = sub(to, 0);
		//cout << "Entran " << from << " " << to << endl;
		from ++, to ++;
		if(to < from){
			lines += get(n) - get(from - 1) + get(to);
		}else{
			lines += get(to) - get(from - 1);
		}
		ans += (lines + 1);
		update(cur + 1, 1);
		cur = nxt % n;
		printf(LL "\n", ans);
	}
	
	
  return 0;
}
