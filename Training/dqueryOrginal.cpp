#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
#define pii pair<int,int>
#define pb push_back


using namespace std;

const int MAX = 30005;
const int TAM = 1000005;
const int x = 150;
typedef long long ll;

int res[TAM], seen[TAM], bef[MAX], arr[MAX];

struct question{
    int l, r;
    int idx;
    question(){}
    question(int _l, int _r, int _idx):l(_l),r(_r), idx(_idx){}
}querie[TAM];

bool cmp(question a, question b){
    if(a.l / x == b.l / x)
        return a.r < b.r;

    return a.l / x < b.l / x;

}

int main(){
 //   freopen("dquery.in", "r",stdin);
 //  freopen("newDquery.out", "w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;

    cin >> n;

    for(int i = 1; i <= n; i ++)
        cin >> arr[i];

    cin >> q;

    for(int i = 0; i < q; i ++){
        cin >> querie[i].l >> querie[i].r;
        querie[i].idx = i;
    }

    sort(querie, querie + q, cmp);

    int from, to, ans = 0;
    from = to = 0;
    memset(seen, -1, sizeof(seen));

    for(int i = 0; i < q; i ++){
        int lf = querie[i].l;
        int rg = querie[i].r;

        while(from < lf){
            if(seen[arr[from]] == from){
                seen[arr[from]] = -1;
                ans --;
            }
            from ++;
            //to = max(to, from);
        }

        while(from > lf){
            from --;
            if(seen[arr[from]] == -1){
                seen[arr[from]] = from;
                ans ++;
            }
        }

        while(to < rg){
            to ++;
            if(to < from)
                continue;
            if(seen[arr[to]] == -1){
                seen[arr[to]] = to;
                ans ++;
                bef[to] = -1;
            }else{
                bef[to] = seen[arr[to]];
                seen[arr[to]] = to;
            }
        }
        while(to > rg){
            int prev = bef[to];
            if(prev >= lf){
                seen[arr[to]] = prev;
            }else{
                seen[arr[to]] = -1;
                ans --;
            }
            to --;
        }
      //  cout << from << " - " << to << " " << ans  << " para query " << querie[i].idx + 1<< endl;
        res[querie[i].idx] = ans;


    }

    for(int i = 0; i < q; i ++)
        cout << res[i] << '\n';



    return 0;
}
