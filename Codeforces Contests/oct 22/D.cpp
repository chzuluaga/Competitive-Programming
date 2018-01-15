#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 300005;

struct team{
	ll t, w, pos;
	bool operator<(team other) const{
		if(other.t == t)
			return  w > other.w;
		return t > other.t;
	}
}a[MAX];

bool cmp(pll x, pll y){
	return x.second > y.second;
}
int main(){
  int n;
  ll cur = 0, cont = 0;
	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf(LL LL, &a[i].t, &a[i].w);
		a[i].pos = i;
	}
	
	cur = a[0].t;
	
	sort(a, a + n);
	
	priority_queue< ll > q;
	
	
	bool flag = true;
	vector< pll >v;
	int start = 1;
	for(int i = 0; i < n; i ++){
		if(i == 0){
			cont = a[i].w - a[i].t + 1;
			if(a[i].pos == 0)
				cont -= a[i].w - a[i].t + 1;
			
			if(a[i].t == cur)
				flag = false;
		}else{
			if(a[i].t != a[i - 1].t){
				if(flag){
					q.push(-cont);
					start ++;
				}
				else
					if(cont > 0)
						v.pb(mp(cont, a[i - 1].t));
				
				cont = a[i].w - a[i].t + 1;
				
				if(a[i].t == cur)
					flag = false;
				
				if(a[i].pos == 0)
					cont -= a[i].w - a[i].t + 1;
			}else{
				cont += a[i].w - a[i].t + 1;
				if(a[i].pos == 0)
					cont -= a[i].w - a[i].t + 1;
			}
		}
	}
	
	if(flag)
		q.push(-cont);
	else
		if(cont > 0)
			v.pb(mp(cont, a[n - 1].t));
			
	/*for(int i = 0; i < (int) v.size(); i ++)
		cout << v[i].first << " " << v[i].second << endl;
	*/	
		
	int ans = start, idx = 0;
	//cout << "inicia en " << start << endl;
	while(!q.empty()){
		ll val = -q.top();
		q.pop();
		//cout << val << " entra " << cur << endl;
		if(cur - val >= 0){
			cur -= val;
		//	cout << "delete " << val << endl;
		}
		else
			break;
		start --;
		for(; idx < (int)v.size(); idx ++){
			if(v[idx].second > cur){
			//	cout << "mete " << v[idx].first << " " << v[idx].second << endl;
				start ++;
				q.push(-v[idx].first);
			}else
				break;
		}
		ans = min(start, ans);
	}
	
	printf("%d\n", ans);
	
	return 0;
}
