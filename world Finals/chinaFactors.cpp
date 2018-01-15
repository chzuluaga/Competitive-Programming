#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include<bits/stdc++.h>

using namespace std;

#define LLU unsigned long long int

const LLU oo = 1ULL<<63;
LLU yh[100][100];
LLU ss[50] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
map<LLU, LLU> anses;

//求组合数
void preWork()
{
    yh[0][0] = 1;
    for (int i = 1; i <= 62; i++) {
        yh[i][0] = 1;
        for (int j = 1; j <= 62; j++) {
            if (yh[i-1][j] <= oo && yh[i-1][j-1] <= oo)
                yh[i][j] = yh[i-1][j] + yh[i-1][j-1];
            else
                yh[i][j] = oo;
        }
    }
}

//暴力搜索维护答案
void work(LLU k, LLU n, LLU count, LLU i)
{
    if (count && (!anses.count(k) || anses[k] > n))
        anses[k] = n;
    LLU tot = 0;
    LLU tmp = n;
    while(ss[i] <= oo/tmp) {
        tot++;
        tmp *= ss[i];
        work(k*yh[count+tot][tot], tmp, count+tot, i+1);
    }
}

int main()
{
    //freopen("factors.in", "r", stdin);
    freopen("factors.out", "w", stdout);
    preWork();
    work(1, 1, 0, 0);
    LLU x;
    cout << anses.size() << endl;
    for(map<LLU, LLU>:: iterator it = anses.begin(); it != anses.end(); it ++){
			cout << (*it).first << " " << (*it).second << endl;
		}
		return 0;
    while (scanf("%llu", &x) != EOF) {
        printf("%llu %llu\n", x, anses[x]);
    }
    return 0;
}
