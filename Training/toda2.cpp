#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
const int MAX = 101;
pii a[MAX];
int visit[MAX];
vector<int> step;
void add(int x, int y, int z){
	step.pb(x);
	step.pb(y);
	step.pb(z);
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
 // freopen("toda.in", "r",stdin);
  int n;
  scanf("%d", &n);
  
  for(int i = 0; i < n; i ++){
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a, a + n);
	reverse(a, a + n);
	int last = -1;
	for(int i = n - 2; i >= 0; i --){
		if(a[i].first != a[i + 1].first){
			last = i;
			break;
		}
	}
	
	if(last == -1){
		printf("%d\n%d\n", a[0].first, 0);
		return 0;
	}
	
	while(a[0].first != a[1].first){
		if(last == 0)
			last = n - 1;
		a[0].first --;
		a[last].first = max(0, a[last].first-1);
		add(a[0].second, a[last].second, -1);
		
		if(a[last].first == a[last + 1].first)
			last --;
		if(last == 0)
			last = n - 1;
	}
	
	while(true){
		int cont = 0;
		for(int i = 1; i < n; i ++){
			if(a[i].first == a[0].first){
				a[i].first = max(a[i].first, 0);
				cont ++;
			}else
				break;
		}
		if(cont == n - 1)
			break;
		
		
		for(int i = 0; i <= cont; i ++){
			a[i].first = max(0, a[i].first - 1);
		}
			
		if(cont & 1){
			for(int i = 0; i < cont; i += 2){
				add(a[i].second, a[i + 1].second, -1);
			}
		}else{
			for(int i = 0; i < cont; i += 2){
				add(a[i].second, a[i + 1].second, -1);
			}
			step[ (int)step.size() - 1]  = a[cont].second;
		}
	}
	
	printf("%d\n%d\n", a[0].first , (int)step.size()/3);
	
	for(int i = 0; i < (int)step.size(); i += 3){
		memset(visit, 0, sizeof(visit));
		visit[step[i]] = 1;
		visit[step[i + 1]] = 1;
		if(step[i + 2] != -1)
			visit[step[i + 2]] = 1;
		for(int j = 0; j < n; j ++){
			if(visit[j])
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
	
  return 0;
}
