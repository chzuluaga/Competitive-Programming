#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define LL "%lld"
using namespace std;
typedef long long ll;
const int MAX = 300005;
pll team[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
	int n;
	ll ball, weight;
	scanf("%d", &n);
	scanf(LL LL, &ball, &weight);
	n --;
	for(int i = 0; i < n; i ++)
		scanf(LL LL, &team[i].first,&team[i].second);
		
	sort(team, team + n);
	
	reverse(team, team + n);
	
	priority_queue< ll > q;
	int idx = 0, ans;
	while(idx < n && team[idx].first > ball){
		q.push(-(team[idx].second - team[idx].first + 1));
		idx ++;
	}	
	ans = (int)q.size() + 1;
	while(!q.empty()){
		ll cur = q.top();
		cur *= -1;
		if(cur <= ball)
			ball -= cur;
		else
			break;
			
		q.pop();
		
		while(idx < n && team[idx].first > ball){
			q.push(-(team[idx].second - team[idx].first + 1));
			idx ++;
		}	
		ans = min((int)q.size() + 1, ans);
	}
	
	printf("%d\n", (int)ans);
  return 0;
}
