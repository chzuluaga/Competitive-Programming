#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

ll m[4];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  freopen("tresMosqueteros.in", "r", stdin);
  
  int n;
  ll x;
  scanf("%d", &n);
    
  for(int i = 0; i < 3; i ++)
		scanf(LL, &m[i]);
		
	sort(m, m + 3);
	multiset<ll> criminal;
	multiset<ll>::iterator it;	
	for(int i = 0; i < n; i ++){
		scanf(LL, &x);
		criminal.insert(x);
	}
	
	ll abc = m[0] + m[1] + m[2];
	ll bc = m[1] + m[2];
	ll ac = m[0] + m[2];
	ll ab = m[0] + m[1];
	ll a = m[0];
	ll b = m[1];
	ll c = m[2];
	ll ans = 0;
		
	//abc
	while(true){
		it = criminal.upper_bound(bc);
		if(it == criminal.end())
			break;
		ll cur = *it;
		if(cur > abc){
			printf("-1\n");
			return 0;
		}
		ans ++;	
		criminal.erase(it);
	}
	
	//bc
	while(true){
		it = criminal.upper_bound(ac);
		if(it == criminal.end())
			break;
		ll cur = *it;
		ans ++;	
		criminal.erase(it);
		it = criminal.lower_bound(a);
		cur = *it;
		if(it != criminal.end() && cur <= a)
			criminal.erase(it);
		else{
			if(it != criminal.begin()){
				it --;
				cur = *it;
				if(cur <= a)
					criminal.erase(it);
			}
		}
	}
	
	//ac
	while(true){
		it = criminal.upper_bound(max(ab, c));
		if(it == criminal.end())
			break;
		ll cur = *it;
		ans ++;	
		criminal.erase(it);
		it = criminal.lower_bound(b);
		cur = *it;
		if(it != criminal.end() && cur <= b)
			criminal.erase(it);
		else{
			if(it != criminal.begin()){
				it --;
				cur = *it;
				if(cur <= b)
					criminal.erase(it);
			}
		}
	}
	
	ll best = INT_MAX, one = 0, two = 0;
	for(it = criminal.begin(); it != criminal.end(); it ++){
		cout << *it << " " ;
		if(*it <= ab)
			one ++;
		if(*it <= c)
			two ++;
	}
	ll cont = 0;
	cout << endl;
	cout << ans << endl;
	for(int i = 0; i < n * 2 ; i ++){
		cout << one << " " << two << endl;
		
		best = min(best, cont + max(( (ll) criminal.size() + 1) / 2, max(one - two, two - one)));
		if(!criminal.size())
			break;
		for(int j = 0; j < 3; j ++){
			it = criminal.upper_bound(m[j]);
			if(it != criminal.begin()){
					it --;
				if(*it <= ab)
					one --;
				if(*it <= c)
					two --;
					
				cout << "borro " << *it << endl;
				criminal.erase(it);
			}
			
		}
		cont ++;
	}
		
	
	printf(LL "\n", ans + best); 
	

  return 0;
}
