#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define endl "\n"
using namespace std;
typedef long long ll;

const int MAX = 1005;
string ma[MAX];
int vis[4][MAX][MAX], dis[4][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0 , -1};
vector<int> ans;
int n, m;
bool ok(int x, int y, int idx){
	return x >= 0 && x < n && y >= 0 && y < m && -1 == vis[idx][x][y] && ma[x][y] != '#';
}
void bfs(queue<int> &q, int idx){
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		int cost = q.front();
		q.pop();
		for(int i = 0; i < 4; i ++){
			if(ok(x + dx[i], y + dy[i], idx)){
				vis[idx][x + dx[i]][y + dy[i]] = cost + 1;
				if(idx == 1){
					if(ma[x + dx[i]][y + dy[i]] == '2' 
					|| ma[x + dx[i]][y + dy[i]] == '3'){
						dis[idx][ma[x + dx[i]][y + dy[i]] - '0'] = min(dis[idx][ma[x + dx[i]][y + dy[i]] - '0'], cost);
					}else{
						q.push(x + dx[i]);
						q.push(y + dy[i]);
						q.push(cost + 1);
					}
				}else if(idx == 2){
					if(ma[x + dx[i]][y + dy[i]] == '3'){
						dis[idx][ma[x + dx[i]][y + dy[i]] - '0'] = min(dis[idx][ma[x + dx[i]][y + dy[i]] - '0'], cost);
					}else{
						q.push(x + dx[i]);
						q.push(y + dy[i]);
						q.push(cost + 1);
					}
				}else{
					if(ma[x + dx[i]][y + dy[i]] == '1' 
					|| ma[x + dx[i]][y + dy[i]] == '2'){
						dis[idx][ma[x + dx[i]][y + dy[i]] - '0'] = min(dis[idx][ma[x + dx[i]][y + dy[i]] - '0'], cost);
					}else{
						q.push(x + dx[i]);
						q.push(y + dy[i]);
						q.push(cost + 1);
					}
				}
			}
		}
	}
	
	if(idx == 1){
		if(dis[1][2] < INT_MAX / 100)
			ans.pb(dis[1][2]);
		if(dis[1][3] < INT_MAX / 100)
			ans.pb(dis[1][3]);
	}else if (idx == 2){
		if(dis[2][3] < INT_MAX / 100)
			ans.pb(dis[2][3]);
	}
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  memset(vis, -1, sizeof(vis));
  for(int i = 0; i < n; i ++)
		cin >> ma[i];
	queue<int> one, two, three;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			if(ma[i][j] == '1'){
				one.push(i);
				one.push(j);
				one.push(0);
				vis[1][i][j] = 0;
			}
			if(ma[i][j] == '2'){
				two.push(i);
				two.push(j);
				two.push(0);
				vis[2][i][j] = 0;
			}
			if(ma[i][j] == '3'){
				three.push(i);
				three.push(j);
				three.push(0);
				vis[3][i][j] = 0;
			}
		}
	}
	for(int i = 0; i < 4; i ++)
		for(int j = 0; j < 4; j ++)
			dis[i][j] = INT_MAX / 100;
	bfs(one, 1);
	bfs(two, 2);
	bfs(three, 3);
	
	if(ans.size() < 2 ){
		cout << -1 << endl;
	}else{
		sort(ans.begin(), ans.end());
		int r = ans[0] + ans[1];
		
		for(int i = 0; i < n; i ++){
			for(int j = 0;j < m;j ++){
				
				//if(vis[1][i][j] == 0 && vis[2][i][j] == 0 && vis[3][i][j] == -0)
					//cout << i << " " << j << " " << ma[i][j] << endl;
				if(vis[1][i][j] != -1 && vis[2][i][j] != -1 && vis[3][i][j] != -1){
					//cout << i << " " << j << endl;
					r = min(r, vis[1][i][j] + vis[2][i][j] + vis[3][i][j] - 2);
				}
			}
		}
		cout << r << endl;
	}

  return 0;
}
