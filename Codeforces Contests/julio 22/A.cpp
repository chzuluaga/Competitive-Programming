#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 105;

pii arr[MAX];


int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);

  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i ++){
    scanf("%d", &arr[i].first);
    arr[i].second = i + 1;
  }

  sort(arr, arr + n);
  int rev = n - 1;
  for(int i = 0; i < n / 2; i ++){
    cout << arr[i].second << " " << arr[rev --].second << '\n';
  }



  return 0;
}
