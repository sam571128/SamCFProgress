#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	cini(a);
	vi f;
	vi s;
	vi t;
	for(int i = 1;i <= a;i++){
		cini(temp);
		if(temp==1){
			f.push(i);
		}else if(temp==2){
			s.push(i);
		}else{
			t.push(i);
		}
	}
	int count = min(min(f.size(),s.size()),min(s.size(),t.size()));
	cout << count << "\n";
	if(count == 0)return 0;
	for(int i = 0;i < count ;i++){
		cout << f[i] << " " << s[i] << " " << t[i] << "\n";
	}
}