#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
#define pi pair<int,int>

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
    for(int i = 1; i < n; i ++)
        sum[i] = abs(arr[i] - arr[i - 1]) + sum[i - 1];

    ll ans = 1, val = 1;
    map<ll, int> sol;
    for(int i = 1; i < n; i ++){
        if(sum[i] % i == 0){
            sol[sum[i] / i] ++;
          //  cout << "sumando a " << sum[i] / i << " ";
            ll r = sol[sum[i] / i];
            if(r + 1 > ans){
                ans = r + 1;
                val = sum[i] / i;
            }
        }
    }
    //cout << endl;
    cout << ans << "\n" << val << "\n";

    return 0;
}
