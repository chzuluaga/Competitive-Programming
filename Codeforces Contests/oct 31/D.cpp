#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define LL "%lld"
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
struct para{
	ll a, b, c, idx;
	para(){}
	para(ll _a, ll _b, ll _c){
		a = _a;
		b = _b;
		c = _c;
		idx = -1;
	}
	bool operator<(para other) const{
		ll xa = min(a, min(b, c));
		ll xb = min(other.a, min(other.b, other.c));
		return xa > xb;
	}
}p[MAX];


bool cmp1(para x, para y){
	//(a, b) -> c
	if(x.a == y.a){
		if(x.b == y.b)
			return x.c > y.c;
		return x.b > y.b;
	}
	return x.a > y.a;
}

bool cmp2(para x, para y){
	//(a, c) -> b
	if(x.a == y.a){
		if(x.c == y.c)
			return x.b > y.b;
		return x.c > y.c;
	}
	return x.a > y.a;
}

bool cmp3(para x, para y){
	//(b, c) -> a
	if(x.b == y.b){
		if(x.c == y.c)
			return x.a > y.a;
		return x.c > y.c;
	}
	return x.b > y.b;
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("d.in", "r", stdin);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++){
		scanf(LL LL LL , &p[i].a, &p[i].b, &p[i].c);
		p[i].idx = i;
		vector<int> v;
		v.pb(p[i].a);
		v.pb(p[i].b);
		v.pb(p[i].c);
		sort(v.begin(), v.end());
		p[i].a = v[0];
		p[i].b = v[1];
		p[i].c = v[2];
	}
	
	sort(p, p + n);
	
	//for(int i = 0; i < n; i ++)
		//cout << p[i].a << " " << p[i].b << " " << p[i].c << endl;
	int cont = 1;
	int a = p[0].idx, b = -1;
	para ans = p[0];
	
	sort(p, p + n, cmp1);
	for(int i = 1; i < n; i ++){
		if(p[i].a == p[i - 1].a && p[i].b == p[i - 1].b){
			para aux = para(p[i].a, p[i].b, p[i].c + p[i - 1].c);
			if(aux < ans){
				ans = aux;
				cont = 2;
				a = p[i].idx;
				b = p[i - 1].idx;
			}
		}
	}
	sort(p, p + n, cmp2);
	for(int i = 1; i < n; i ++){
		if(p[i].a == p[i - 1].a && p[i].c == p[i - 1].c){
			para aux = para(p[i].a, p[i].c, p[i].b + p[i - 1].b);
			if(aux < ans){
				ans = aux;
				cont = 2;
				a = p[i].idx;
				b = p[i - 1].idx;
			}
		}
	}
	
	sort(p, p + n, cmp3);
	for(int i = 1; i < n; i ++){
		if(p[i].b == p[i - 1].b && p[i].c == p[i - 1].c){
			para aux = para(p[i].b, p[i].c, p[i].a + p[i - 1].a);
			if(aux < ans){
				cont = 2;
				ans = aux;
				a = p[i].idx;
				b = p[i - 1].idx;
			}
		}
	}
	
	printf("%d\n%d\n", cont, a + 1);
	//cout << ans.a << " " << ans.b << " " << ans.c << endl;
	if(cont == 2){
		printf("%d\n", b + 1);
	}
	
	

  return 0;
}
