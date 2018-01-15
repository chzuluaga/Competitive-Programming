#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 2005;
ll a[MAX];
ll diff[5003];
ll bit[10005];

void update(int pos, ll val){
	for(int i = pos; i <= 10000; i += i&-i)
		bit[i] += val;
}

ll get(int pos){
	ll r = 0;
	
	for(int i = pos; i ; i -= i &-i)
		r += bit[i];
		
	return r;
}


int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  ll n;
  
  scanf(LL, &n);
  
  for(int i = 0; i < n; i ++)
		scanf(LL, &a[i]);
	
	sort(a, a + n);
	ll total = 0;
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n;j ++){
			diff[a[j] - a[i]] ++;
			total ++;
		}
	}
	
	for(int i = 1; i <= 5000; i ++){
		for(int j = 1; j <= 5000; j ++){
			ll r = diff[i] * diff[j];
			update(i + j, r);
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j ++){
			int d = a[j] - a[i];
			ans += get(d - 1);
		}
	}
	total *= total * total;
	//cout << ans << " " << total << endl;
	double sol = (ans*1.0) / (1.0 * total);
	printf("%.8lf\n", sol);
	
			
	

  return 0;
}
