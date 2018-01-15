#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mp make_pair
using namespace std;

typedef long long ll;
const int MAX = 104;
int arr[MAX];
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);

  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i ++)
    scanf("%d", &arr[i]);

  bool flag = true;
  while(flag){
    flag = false;
    int l = -1, r = -1;
    for(int i = 0; i < n - 1; i ++){
      if(arr[i] > arr[i + 1]){
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
        flag = true;
        if(l == -1){
          l = i + 1;
        }
        r = i + 2;
        i ++;
      }else{
        if(l != -1 && r != -1){
          printf("%d %d\n", l, r);
        }
        l = -1;
        r = -1;
      }
    }
    if(l != -1 && r != -1){
      printf("%d %d\n", l, r);
      flag = true;
    }

  }


  return 0;
}
