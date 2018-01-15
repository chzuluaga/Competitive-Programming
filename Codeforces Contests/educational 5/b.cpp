#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string a, b, A, B;
  
  cin >> a >> b;
  
  for(int i = 0; i < (int)a.size(); i ++){
		if(a[i] != '0'){
			A = a.substr(i);
			break;
		}
	}
	for(int i = 0; i < (int) b.size(); i ++){
		if(b[i] != '0'){
			B = b.substr(i);
			break;
		}
	}
	
	//cout << A << " " << B << endl;
	int sza = A.size();
	int szb = B.size();
	if(sza > szb)
		cout << ">\n";
		else
			if(sza < szb)
				cout << "<\n";
				else{
						bool f = false;
						for(int i = 0; i < sza; i ++){
							if(A[i] != B[i]){
								if(A[i] > B[i])
									cout << ">\n";
								else
									cout << "<\n";
								f = true;
								break;
							}
						}
						if(!f)
							cout << "=\n";
				}
	
  return 0;
}
