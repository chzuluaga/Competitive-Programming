    #include <iostream>
    #include <cstdio>
    #include <cstring>
    #include <queue>
    using namespace std;


    bool status[500005],LR;
    long long int amount[500005];
    long long int n,x,y;
    int m,a,b,lft[500005],rght[500005],tmp,in[500005],L,R;
    char c;
    queue <int> cal;

    int main()
    {
        //freopen("digi.in", "r", stdin);
        //freopen("saloff.out", "w", stdout);
        while(~scanf("%lld%d",&n,&m))
        {
            memset(status,0,sizeof(status));
            memset(amount,0,sizeof(amount));
            memset(in,0,sizeof(in));
            memset(lft,0,sizeof(lft));
            memset(rght,0,sizeof(rght));
            getchar();
            amount[1]=n;
            for(int i=1;i<=m;i++)
            {
                scanf("%c %d %d",&c,&a,&b);
                getchar();
                lft[i]=a;
                rght[i]=b;
                if(c=='L')
                    status[i]=1;
                in[a]++;
                in[b]++;
            }
            for(int i=1;i<=m;i++)
            {
                if(in[i]==0)
                    cal.push(i);
            }

            while(!cal.empty())
            {
               tmp=cal.front();
               cal.pop();
               L=lft[tmp];
               R=rght[tmp];
               if(L||R)
               {
                 x=(amount[tmp]+1)/2;
                 y=amount[tmp]-x;
                 if(status[tmp])
                 {
                   amount[L]+=x;
                   amount[R]+=y;
                 }
                 else
                 {
                   amount[L]+=y;
                   amount[R]+=x;
                 }
                 in[L]--;
                 in[R]--;
               if(L==R)
               {
                   if(L&&in[L]==0)
                     cal.push(L);
               }
               else
               {
                   if(in[L]==0&&L)
                     cal.push(L);
                   if(in[R]==0&&R)
                     cal.push(R);
                }
              }
            }
            for(int i=1;i<=m;i++)
            {
                if(amount[i]%2)status[i]=!status[i];
                if(status[i])printf("L");
                else printf("R");
            }
            printf("\n");
        }
        return 0;
    }
