#include<bits/stdc++.h>
#define pb push_back
#define LL "%lld"
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

const int MAX = 1000006;
const int nprime = 33000;
bitset<nprime> isPrime;
ll arr[MAX];
vector<int> primes;
set<ll> p;
void make_sieve(){
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for(int i = 2; i < nprime; i ++){
		if(isPrime[i]){
			primes.pb(i);
			for(int j = i + i; j < nprime; j += i)
				isPrime[j] = 0;
		}
	}
}

void factorize(int val){
	
	for(int cur : primes){
		
		if(cur * cur > val)
			break;
		if(val % cur == 0){
			p.insert(cur);
			
			while(val % cur == 0)
				val /= cur;
		}
	}
	if(val > 1)
		p.insert(val);
}

bool ok(int x, int y){
	if(x % y == 0)	return true;
	if((x - 1) % y == 0)	return true;
	if((x + 1) % y == 0)  return true;
	return false;
}

ll forw[MAX][3], rev[MAX][3];

int main(){
  
  int n;
  ll rem, add;
  
  scanf("%d" LL LL, &n, &rem, &add);
  
  make_sieve();
  
  for(int i = 0; i < n; i ++)
		scanf(LL, &arr[i]);
		
	factorize(arr[0] - 1);
	factorize(arr[0]);
	factorize(arr[0] + 1);
	
	factorize(arr[n - 1] - 1);
	factorize(arr[n - 1]);
	factorize(arr[n - 1] + 1);
	
	ll ans = LLONG_MAX;
	for(int cur : p){
		int i = 0,j = n - 1;
		while( i < n && ok(arr[i], cur)){
			ll cost = (arr[i] % cur)?add:0;
			if(i == 0){
				forw[i][0] = cost;
				forw[i][1] = min(forw[i][0], rem);
				forw[i][2] = forw[i][1];
			}else{
				forw[i][0] = cost + forw[i - 1][0];
				forw[i][1] = min(forw[i][0], rem + forw[i - 1][1]);
				forw[i][2] = min(forw[i][1], cost + forw[i - 1][2]);
			}
			
			i ++;
		}
		
		if(i == n){
			ans = min(ans, forw[i - 1][2]);
			continue;
		}
		
		while(j >= i && ok (arr[j], cur)){
			ll cost = (arr[j] % cur)?add:0;
			if(j == n - 1){
				rev[j][0] = cost;
				rev[j][1] = min(rev[j][0], rem);
			}else{
				rev[j][0] = cost + rev[j + 1][0];
				rev[j][1] = min(rev[j][0], rem + rev[j + 1][1]);
			}
			j --;
		}
		
		if(i == 0 && j == n - 1)	//remove all
			continue;
		
		ans = min(ans, (i?forw[i - 1][1]:0) + (j < n - 1?rev[j + 1][1]:0) +
		rem * ll(j - i + 1));
	}
	
	printf(LL"\n", ans);
	

  return 0;
}
