#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 10000005;

int ans[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int n;
	memset(ans, -1, sizeof(ans));	
	ans[0] = 0, ans[1] = 1;

	queue<int> q;
	q.push(1);
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		//cout << q.size() << " size " << cur  << endl;
		
		for(int i = 2; i <= cur; i ++){
			if(cur * i  >= MAX)
				break;
			if(cur * i < MAX && ans[cur * i] == -1){
				q.push(cur * i);
				ans[cur * i] = ans[cur] + 1;
			}
		}
		
		if(cur + 1 < MAX && ans[cur + 1] == -1){
			q.push(cur + 1);
			ans[cur + 1] = ans[cur] + 1;
		}
	}
	
	int num;

	scanf("%d", &n);
	
	for(int i = 0; i < n; i ++){
		scanf("%d", &num);
		printf("%d\n", ans[num]);
	}
	

	
	
		
  return 0;
}
