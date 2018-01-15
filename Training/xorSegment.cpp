#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define LL "%lld"
using namespace std;
typedef long long ll;
const int MAX = 100005;
ll a[MAX];

struct node{
    
    node *L, *R;
    int lf, rg;
    ll sum;
    int lazy;
    node(){
        lazy = 0;
        sum = 0;
        L = NULL;
        R = NULL;
    }
    void create(int from, int to){
        lf = from;
        rg = to;
        if(from == to)
            return;
					L = new node();
					R = new node();
					L -> create(from, (from + to)/ 2);
					R -> create((from + to)/2 + 1, to);
    }
    
    void expand(){
        
        if(lazy == 0)
            return;
        
        if(L != NULL){
            L -> sum =(L->rg - L->lf + 1) - L -> sum;
            L -> lazy ^= 1;
        }
            
        if(R != NULL){
            R -> sum = R->rg - R ->lf + 1 - R -> sum;
            R -> lazy ^= 1;
        }
            
        lazy = 0;
    }
    
    void update(int from, int to){
        expand();
        //cout << "from " << from << " " << to << " lf rg " << lf << " " << rg<< endl;
        if(from == lf && to == rg){
            sum = (rg - lf + 1) - sum;
            lazy = 1;
            //cout << " val " << (val * (rg - lf + 1)) << endl;
            return;
        }
        
        if(to < R -> lf){
            L -> update(from, to);
        }else{
            if(from > L -> rg){
                R -> update(from, to);
            }else{
                L -> update(from, L->rg);
                R -> update(R -> lf, to);
            }
        }
        sum = L -> sum + R -> sum;
    }
    
    ll get(int from, int to){
        expand();
        if(from == lf && to == rg){
            return sum;
        }
        ll ans = 0;
        if(to < R -> lf){
            ans =  L -> get(from, to);
        }else{
            if(from > L -> rg){
                ans = R -> get(from, to);
            }else{
                ans = L -> get(from, L->rg) + R -> get(R -> lf, to);
            }
        }
        sum = L -> sum + R -> sum;
        return ans;
    }
}bit[25];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  //freopen("xorSegment.in", "r", stdin);
	int n, m, type, lf, rg, x;
	
	scanf("%d", &n);
	
	for(int i = 0; i < 22; i ++)
		bit[i].create(0, n - 1);
	for(int i = 0; i < n; i ++)
		scanf(LL , &a[i]);
	
	for(int i = 0; i < 21; i ++){
		for(int j = 0; j < n; j ++){
			if(a[j] & (1 << i))
				bit[i].update(j, j);
		}
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i ++){
		scanf("%d", &type);
		if(type == 1){
			scanf("%d%d", &lf, &rg);
			lf --, rg --;
			ll ans = 0;
			for(int j = 0; j < 21; j ++){
				ans += (1ll << j) * bit[j].get(lf, rg);
			}
			
			printf(LL "\n", ans);
		}else{
			scanf("%d%d%d", &lf, &rg, &x);
			lf --, rg --;
			for(int j = 0; j < 21; j ++){
				if(x & (1<<j))
					bit[j].update(lf, rg);
			}
		}
	}
  return 0;
}
