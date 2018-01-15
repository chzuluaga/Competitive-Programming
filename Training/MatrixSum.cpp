#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 511111;
ll a[MAX], b[MAX], mod = 1000000007ll;
ll sumA[MAX], sumB[MAX], L[MAX], R[MAX], saux[MAX];
int n;

void calc(ll *sum, ll val, ll lf,ll rg){
	if(lf > rg)
		swap(lf, rg);
		
	//cout << val << " en " << lf << "  - " << rg << endl;
	for(int i = 1; i <= lf; i ++){
		sum[i] += (val * (ll)(i)) % mod;
		sum[i] %= mod;
		sum[lf + rg + 2 - i] += (val * (ll)(i)) % mod;
		sum[lf + rg + 2 - i] %= mod;
	}
//	cout << "sumando en " << lf << " " << lf * val << endl;
//	cout << "restando en " << rg + 1 << " " << lf * val << endl;
	saux[lf + 1] += ((ll)(lf + 1) * val) % mod;
	saux[lf + 1] %= mod;
	saux[rg + 2] += ((mod - (((ll)(lf + 1) * 1ll * val)%mod))) % mod;
	saux[rg + 2] %= mod;
}

void solve(ll *sum, ll *cur){
	stack<int> st;
	memset(saux, 0, sizeof(saux));
	for(int i = 0; i < n; i ++){
		while(!st.empty() && cur[st.top()] < cur[i])	
			st.pop();
		if(st.empty())
			L[i] = (ll) (i + 1);
		else
			L[i] = (ll) (i - st.top());
		st.push(i);
	}
	
	while(!st.empty())	st.pop();
	
	for(int i = n - 1;i >= 0; i --){
		while(!st.empty() && cur[st.top()] <= cur[i])	st.pop();
		if(st.empty())
			R[i] = (ll)(n - i);
		else
			R[i] = (ll)(st.top() - i);
		st.push(i);
		
		calc(sum, cur[i], L[i] - 1, R[i] - 1);
	}
	
	for(int i = 1; i <= n; i ++){
		
		saux[i] += saux[i - 1];
		saux[i] %= mod;
		
	//	cout << saux[i] << " " ;
		sum[i] += saux[i];
		sum[i] %= mod;
		
	}
	//cout << " fin saux " << endl;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 // freopen("matrixSum.in", "r", stdin);
  
  cin >> n;
  
  for(int i = 0; i < n; i ++){
		cin >> a[i];
	  a[i] += (i + 1ll);
	  //a[i] %= mod;
	  //cout << a[i] << " " ;
	}
	//cout << endl;

	
	
	for(int i = 0; i < n; i ++){
		cin >> b[i];
		b[i] += (i + 1ll);
		//b[i] %= mod;
	}
	
	solve(sumA, a);
	
	/*for(int i = 0; i <= n; i ++)
		cout << sumA[i] << " " ;
		
	cout << endl << endl;;
	*/
	solve(sumB, b);
	
	
	
	
	for(int i = 1; i <= n; i ++){
		if(i > 1)	cout << " ";
		ll ans = sumA[i] * sumB[i];
		ans %= mod;
		cout << ans;
	}
	
	cout << '\n';	
	
	
	

  return 0;
}
