#include <bits/stdc++.h>

using namespace std;

int com[104], arr[105], arr2[105], arr3[205];
int main(){

int n,p,pa,pa2=0,i,y,j,num,cont,z=0,x=0;

cin>>n;
	if(n>=1 || n<=100){
		for(int u = 1;u<=n;u++){
			com[u]=u;
		}
		cin>>p;
		if(p>=0 || p<=n){
			int arr[p];
			for( i=0;i<p;i++){
				cin>>pa;
				if(pa<1 || pa>n){
					break;
				}else{
					arr[i]=pa;
				
				}
			}
			cin>>y;
			for (j=0;j<y;j++){
				cin>>pa2;
				if(pa2<1 || pa2>n){
					break;
				}else{
					arr2[j]=pa2;
				}
			}
			
			for(int o =0;o<p;o++)
    		{
    			arr3[o]=arr[o];
    		}
    		int f=p;
    		for(int r=0;r<y;r++)
    		{
    			arr3[f++]=arr2[r];
    		}
    		
    	
			sort (arr3, arr3 +(p+y));
			
			int v_aux[p+y];
			
        for (int q=0;q<(p+y);q++) {
                cont=0;
                num=arr3[q];
                v_aux[z]=num;
                z++;
                for (int s=0;s<(p+y);s++){
                        if ( v_aux[s] == num )
                                cont++;}

                if ( cont == 1 ) {
                        x++;
                }
        }
       
            if(x==n){
				cout<<"I become the guy."<<endl;
			}
            else{
				cout<<"Oh, my keyboard!"<<endl;
			}

		}
	}
	

	
	

return 0;
}
