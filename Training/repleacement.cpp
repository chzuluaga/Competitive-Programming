#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 100005;
int arr[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  int n;

  scanf("%d", &n);

  for(int i = 0; i < n; i ++)
    scanf("%d", &arr[i]);

  sort(arr, arr + n);

  if(arr[n - 1] == 1)
    arr[n - 1] = 2;
  else
    arr[n - 1] = 1;

  sort(arr, arr + n);

  for(int i = 0; i < n;i  ++)
    printf("%d\n", arr[i]);

  return 0;
}
