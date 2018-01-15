#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
#define pi pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
const int MAX = 1000005;
ll arr[MAX];
ll sum[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for(int i = 0; i < n; i ++)
        cin >> arr[i];
        
		sum[0] = 0;
    int cont = 0;
		for(int i = 1; i < n; i ++){
			sum[i] = (arr[i] > arr[i - 1]?1:arr[i] == arr[i - 1]?0:-1) + sum[i - 1];
		}
		
		ll ans = 1, val = 0, all = 0;
    map<ll, int> sol;
    for(ll i = 1; i < n; i ++){
				if(sum[i] == 0){
						if(arr[i] != arr[0])
							continue;
						all ++;
						continue;
				}
				if( (abs(arr[i] - arr[0])) % abs(sum[i]) == 0){
						if(arr[i] - arr[0] < 0 && sum[i] > 0)
							continue;
						if(arr[i] - arr[0] > 0 && sum[i] < 0)
							continue;
							
						ll div = (arr[i] - arr[0]) / sum[i];
						div = abs(div);
						sol[div] ++;
            //cout << arr[i] << " here " << div << " " << cont ++ << " " << i << endl;
						ll r = sol[div];
            if(r + 1 > ans){
                ans = r + 1;
                val = div;
            }
        }
        
    }
    cout << ans + all<< "\n" << val << "\n";
    
    return 0;
}
