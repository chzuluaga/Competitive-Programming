#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1003;
char table[MAX][MAX];
int visit[MAX][MAX];
int n, m;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool ok(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m && visit[x][y] == 0 && table[x][y] == '.';
}

bool ok2(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m && table[x][y] == '.';
}

vector<int> cant;

void bfs(int x, int y, int label){
	
	queue<int> q;
	q.push(x);
	q.push(y);
	visit[x][y] = label;
	
	cant.pb(0);
	int sz = (int)cant.size() - 1;
	
	while(!q.empty()){
		x = q.front();
		q.pop();
		y = q.front();
		q.pop();
		//cout << x << " " << y << " " << label << endl;
		cant[sz] ++;
		for(int i = 0; i < 4; i ++){
			if(ok(x + dx[i], y + dy[i])){
				q.push(x + dx[i]);
				q.push(y + dy[i]);
				visit[x + dx[i]][y + dy[i]] = label;
			}
		}
	}
}

int a[5];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	
	//freopen("c.in", "r", stdin);
	
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < n; i ++)
		scanf("%s", table[i]);
	int cont = 1;
	vector< pii > v;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j ++){
			if(table[i][j] == '*'){
				v.pb(mp(i,j));
				continue;
			}
			if(!visit[i][j]){
				bfs(i, j, cont);
				cont ++;
			}
		}
	}
	
	
	
	for(int i = 0; i < (int)v.size(); i ++){
		int x = v[i].first;
		int y = v[i].second;
		
		memset(a, 0, sizeof(a));
		for(int j = 0; j < 4; j ++){
			if(ok2(x + dx[j], y + dy[j])){
				a[j] = visit[x + dx[j]][y + dy[j]];
			}
		}
		int sum = 1;
		for(int j = 0; j < 4; j ++){
			if(a[j] != -1 && a[j] != 0)
				sum += cant[a[j] - 1];
			for(int k = j + 1; k < 4; k ++){
				if(a[j] == a[k])
					a[k] = -1;
			}
		}
		sum %= 10;
		
		table[x][y] = (sum + '0');
		
	}
	
	/*for(int i = 0; i < n;  i ++){
		for(int j = 0; j < m; j ++){
			cout << visit[i][j]<< " ";
		}
		cout << endl;
	}*/
	
	for(int i = 0; i < n; i ++)
		printf("%s\n", table[i]);
  return 0;
}
