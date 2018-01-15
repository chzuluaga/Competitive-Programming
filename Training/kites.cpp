#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 200005;
ll bit[MAX];
void update(int pos, ll val, int limit){
	for(int i = pos; i < limit; i += i&-i){
		bit[i] += val;
	}
}

ll get(int pos){
	ll ans = 0;
	
	for(int i = pos; i ; i -= i&-i)
		ans += bit[i];
	return ans;
}
struct pt{
	ll x, y;
	pt(){}
	pt(ll _x, ll _y){
		x = _x;
		y = _y;
	}
};

struct line{
	pt from, to;
	line(){}
	line(pt _from, pt _to){
		from = _from;
		to = _to;
	}
};

struct event{
	int type;
	ll x, y1, y2;
	event(){}
	event(int _type,ll _x, ll _y){
		type = _type;
		x = _x;
		y1 = _y;
	}
	
	event(int _type,ll _x, ll _y1, ll _y2){
		type = _type;
		x = _x;
		y1 = _y1;
		y2 = _y2;
	}
	
	bool operator <(event other)const{
		if(x == other.x)
			return type < other.type;
		
		return x < other.x;
	}
};

vector< event > e;
int main(){
  
  int n, m;
  ll x, y, l;
  
  while(~scanf("%d %d", &n, &m)){
		
		vector<line> seg;
		vector<ll> hori;
		
		ll longest = 0;
		for(int i = 0; i < n; i ++){
			scanf("%lld %lld %lld", &x, &y, &l);
			line cur;
			cur.from.x = cur.to.x = x;
			cur.from.y = y;
			cur.to.y = y + l;
			seg.pb(cur);
			longest = max(l, longest);
		}
		
		for(int i = 0; i < m; i ++){
			scanf("%lld %lld %lld", &x, &y, &l);
			line cur;
			cur.from.x = x;
			cur.to.x = x + l;
			cur.from.y = cur.to.y = y;
			seg.pb(cur);
			longest = max(l, longest);
			hori.pb(y);
		}
		sort(hori.begin(), hori.end());
		hori.resize(unique(hori.begin(), hori.end()) - hori.begin());
		
		
		ll lo = 0, hi = longest, mit, total = 0;
		while(lo < hi){
			mit = hi + lo + 1ll;
			mit /= 2ll;
			
			e.clear();
			
			for(int i = 0; i < (int)seg.size(); i ++){
				line cur = seg[i];
				if(cur.from.x == cur.to.x){//vertical
					cur.from.y += mit;
					cur.to.y -= mit;
					if(cur.to.y >= cur.from.y){
						e.pb(event(1, cur.from.x, cur.from.y, cur.to.y));
					}
				}else{//horizontal
					cur.from.x += mit;
					cur.to.x -= mit;
					if(cur.to.x >= cur.from.x){
						e.pb(event(0, cur.from.x, cur.from.y));
						e.pb(event(2,cur.to.x, cur.from.y));
					}
				}
			}
			
			sort(e.begin(), e.end());
			
			ll cont = 0;
			for(int i = 0; i < (int)e.size(); i ++){
				event cur = e[i];
				vector<ll>::iterator low, up;
				//cout << e[i].x << " x and type " << cur.type<< endl;
				if(cur.type == 0){
					low = lower_bound(hori.begin(), hori.end(), cur.y1);
					int pos = (int)(low - hori.begin());
					pos ++;
					update(pos, 1, m + 1);
				}
				if(cur.type == 2){
					low = lower_bound(hori.begin(), hori.end(), cur.y1);
					int pos = (int)(low - hori.begin());
					pos ++;
					update(pos, -1,m + 1);
				}
				if(cur.type == 1){
					
					low = lower_bound(hori.begin(), hori.end(), cur.y1);
					up = upper_bound(hori.begin(), hori.end(), cur.y2);
					up --;
					
					int posLow = (int)(low - hori.begin());
					int posUp = (int)(up - hori.begin());
					
					cont += get(posUp + 1) - get(posLow);
				}
			}
			if(cont){
				lo = mit;
				total = cont;
			}
			else
				hi = mit - 1;
		}
		
		printf("%lld %lld\n", lo*2, total);
	}

  return 0;
}
