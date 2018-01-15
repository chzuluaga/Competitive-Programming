#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define LL "%lld"
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 100005;
int dx[] = {1, -1, -1, 1};
int dy[] = {1, 1, -1, -1};
ll curx = 0, cury = 0, dir = 0, n, m;

map< pll, ll > visit[5];

void solve(){
	ll t = 0;
	while(true){
	//	cout << dir << " " << curx << " " << cury << endl;
		
		if(visit[dir].count(mp(curx,cury)))
			break;
		
		visit[dir][mp(curx,cury)] = t;
		
		if(dir == 0){
			if(n - curx > m - cury){//up
				t += (m - cury);
				curx += m - cury;
				cury = m;
				visit[dir][mp(curx, cury)] = t;
				dir = 3;
			}else{
				if(n - curx < m - cury){//right
					t += (n - curx);
					cury += n - curx;
					curx = n;
					visit[dir][mp(curx, cury)] = t;
					dir = 1;
				}else{
					t += (n - curx);
					visit[dir][mp(n, m)] = t;
					break;
				}
			}
			continue;
		}
		
		if(dir == 1){
			if(curx > m - cury){//up
				t += (m - cury);
				curx -= m - cury;
				cury = m;
				visit[dir][mp(curx, cury)] = t;
				dir = 2;
			}else{
				if(curx < m - cury){//right
					t += (curx);
					cury += curx;
					curx = 0;
					visit[dir][mp(curx, cury)] = t;
					dir = 0;
				}else{
					t += (curx);
					visit[dir][mp(0, m)] = t;
					break;
				}
			}
			continue;
		
		}
		if(dir == 2){
			if(curx > cury){//up
				t += (cury);
				curx -= cury;
				cury = 0;
				visit[dir][mp(curx, cury)] = t;
				dir = 1;
			}else{
				if(curx < cury){//right
					t += (curx);
					cury -= curx;
					curx = 0;
					visit[dir][mp(curx, cury)] = t;
					dir = 3;
				}else{
					t += (cury);
					visit[dir][mp(0, 0)] = t;
					break;
				}
			}
			continue;
		}
		if(dir == 3){
			if(n - curx > cury){//up
				t += (cury);
				curx += cury;
				cury = 0;
				visit[dir][mp(curx, cury)] = t;
				dir = 0;
			}else{
				if(n - curx < cury){//right
					t += (n - curx);
					cury -= n - curx;
					curx = n;
					visit[dir][mp(curx, cury)] = t;
					dir = 2;
				}else{
					t += (cury);
					visit[dir][mp(n, 0)] = t;
					break;
				}
			}
			continue;
		}
	}
}
int main(){
  
  ll k, x, y;
  //freopen("ray.in", "r", stdin);
  scanf(LL LL LL, &n, &m, &k);
  
  solve();
  
  for(int i = 0; i < k; i ++){
		scanf(LL LL, &x, &y);
		
		ll x1, x2, y1, y2;
		ll ans = LLONG_MAX;
		
		x1 = (x - min(x, m - y));
		y1 = (y + min(x, m - y));
		x2 = (x + min(n - x, y));
		y2 = (y - min(n - x, y));
		
		//cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		
		
		// dir 1 or 3
		if(visit[1].count(mp(x1, y1)) && visit[1].count(mp(x2, y2)) ){
			//cout << "paso en 1 " <<visit[1][mp(x1, y1)] << endl;
			ans = min(ans, visit[1][mp(x1, y1)] - (y1 - y) );
		}
		if(visit[3].count(mp(x1, y1)) && visit[3].count(mp(x2, y2)) ){
			//cout << "paso en 3 " <<visit[3][mp(x2, y2)] << endl;
			ans = min(ans, visit[3][mp(x2, y2)] - (x2 - x) );
		}
		
		x1 = (x - min(x,  y));
		y1 = (y - min(x, y));
		x2 = (x + min(n - x, m - y));
		y2 = (y + min(n - x, m - y));
		//cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
		//cout << endl;
		
		// visit 0 or 2
		if(visit[0].count(mp(x1, y1)) && visit[0].count(mp(x2, y2)) ){
			//cout << "paso en 0 " <<visit[0][mp(x2, y2)] << endl;
			ans = min(ans, visit[0][mp(x2, y2)] - (y2 - y) );
		}
		if(visit[2].count(mp(x1, y1)) && visit[2].count(mp(x2, y2)) ){
			//cout << "paso en 2 " <<visit[2][mp(x1, y1)] << endl;
			ans = min(ans, visit[2][mp(x1, y1)] - (y - y1) );
		}
		if(ans < LLONG_MAX)
			printf(LL "\n", ans);
		else
			printf("-1\n");
	}
	
	
	

  return 0;
}
