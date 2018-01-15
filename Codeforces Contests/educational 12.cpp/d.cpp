#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 1003;
pii a[MAX];
bool mrk[2000006];
vector<int> prime;
map<int, bool> isPrime;
bool visit[MAX];
void sieve(){

	for(int i = 2; i < 2000006; i ++){
		if(!mrk[i]){
			prime.pb(i);
			isPrime[i] = true;
			for(int j = i; j < 2000005; j += i)
				mrk[j] = true;
		}
	}
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  
  int n;
  
  sieve();
  
  scanf("%d", &n);
  
  for(int i = 0; i < n; i ++)
		scanf("%d", &a[i].first);
		
	vector<int> graph[MAX];
		
	for(int i = 0;i < n; i ++){
		for(int j = i + 1;j < n; j ++){
			int cur = a[i].first + a[j].first;
			if(!isPrime[cur]){
			//	cout << "no es primo " << cur << endl;
				a[i].second ++;
				graph[i].pb(j);
				a[j].second ++;
				graph[j].pb(i);
			}
		}
	}
	priority_queue<pii> q;
	for(int i = 0; i < n; i ++)
		q.push(mp(a[i].second, i));
		
	while(!q.empty()){
		int cur = q.top().second;
		int total = q.top().first;
		q.pop();
		if(a[cur].second != total)
			continue;
			
		if(total == 0)
			break;
			
		visit[cur] = true;
		//cout << cur << " " << total << " " << a[cur].first << endl;
		
			
		for(int i = 0; i < (int)graph[cur].size(); i ++){
			int nei = graph[cur][i];
			if(!visit[nei]){
				a[nei].second --;
				q.push(mp(a[nei].second , nei));
			}
		}
	}
	vector<int> ans;
	for(int i = 0; i < n; i ++){
		if(!visit[i])
			ans.pb(i);
	}
	
	printf("%d\n",(int) ans.size());
	
	for(int i = 0; i < (int)ans.size(); i ++)
		printf("%d ", a[ans[i]].first);
		
	
	
	
	
	

  return 0;
}
