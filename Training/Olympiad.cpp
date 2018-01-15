#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 3005;

struct student{
		int prog, sport, idx;
		bool operator <(student other)const{
			return sport > other.sport;
		}
}a[MAX];

int memo[MAX][MAX], path[MAX][MAX], sum[MAX];
int n, p, s, inf = INT_MAX / 10;
int solve(int idx, int k){
	//cout << idx << " " << k << endl;
	if(k == p){
		int miss = s - (idx - k + 1);
	//	cout << "miss es " << miss << " " << idx << " " << k << endl;
		if(miss >= 0){
			return sum[idx + miss] - sum[idx - 1];
		}
		return 0ll;
	}
	if(idx == n)
		return -inf;
	int &ans = memo[idx][k];
	if(ans != -1)
		return ans;
		
	//choose
	ans = a[idx].prog + solve(idx + 1, k + 1);
	path[idx][k] = 1;
	//not choose
	int r;
	if(idx - k < s)
		r = a[idx].sport + solve(idx + 1, k);
	else	
		r = solve(idx + 1, k);
	if(r > ans){
		path[idx][k] = 0;
		ans = r;	
	}
	return ans;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("Olympiad.in", "r", stdin);
  
  scanf("%d%d%d", &n, &p, &s);
		for(int i = 0; i < n; i ++)
		scanf("%d", &a[i].prog);
	for(int i = 0; i < n; i ++){
		scanf("%d", &a[i].sport);
		a[i].idx = i;
	}
	sort(a, a + n);
	memset(memo, -1, sizeof(memo));
	
	sum[0] = a[0].sport;
	
	for(int i = 1; i < n; i ++){
		sum[i] = sum[i - 1] + a[i].sport;
	}
	printf("%d\n", solve(0,0));
	int x = 0, y = 0;
	vector<int> pr, sp;
	while(p > 0 || s > 0){
		if(path[x][y] == 1){
			if(p > 0)
				pr.pb(a[x].idx + 1);
			x ++, y ++;
			p --;
		}
		else{
			if(s > 0)
				sp.pb(a[x].idx + 1);
			x ++;
			s --;
		}
	}
	for(int i = 0; i < (int)pr.size(); i ++)
		printf("%d ", pr[i]);
	printf("\n");
	for(int i = 0; i < (int)sp.size(); i ++)
		printf("%d ", sp[i]);
	printf("\n");
	
	return 0;
}
