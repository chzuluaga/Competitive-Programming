#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
typedef long long ll;

int toNum(string pal){
  char * cstr = new char [pal.length()+1];
  strcpy (cstr, pal.c_str());
  return atoi(cstr);
}

const int MAX = 200005;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, t;
  string s,fs, sc;
  
  cin >> n >> t >> s;
  
  bool f = false;
  
  for(int i = 0; i < n; i++){
		if(s[i] == '.'){
			f = true;
			continue;
		}
		if(f)
			sc += s[i];
		else
			fs += s[i];
			
	}
	
	//cout << fs << " " << sc << endl;
  int ipart = toNum(fs);
  
  stack< pii > st;
  int last = sc.size() - 1;
  for(int i = 0; i < (int)sc.size(); i ++){
		int cur = sc[i] - '0';
		st.push(mp(cur, i));
		if(cur >= 5){
			last = i;
			break;
		}
	}
	while(!st.empty() && t){
		pii cur = st.top();
		st.pop();
		//cout << "tope es " << cur.first << " " << cur.second << endl;
		if(cur.first < 5){
			sc[cur.second] = (char)(cur.first + '0');
			continue;
		}
		t --;
		last --;
		if(st.empty()){
			ipart ++;
			sc[cur.second] = '0';
		}else{
			sc[cur.second] = '0';
			pii nxt = st.top();
			st.pop();
			nxt.first ++;
			st.push(nxt);
			sc[nxt.second] = (char)(nxt.first + '0');
		}
	}
	
	cout << ipart;
	
	for(int i = 0; i <= last; i ++){
		if(i == 0)	cout << '.';
			cout << sc[i];
	}
	cout << '\n';
	
	
  
  return 0;
}
