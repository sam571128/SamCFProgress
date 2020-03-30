#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		cini(n);
		cins(x);
		string a = "";
		string b = "";
		bool ch = 0;
		for(int i = 0;i < n;i++){
			if(x[i]=='2'){
				if(ch){
					a.push('0');
					b.push('2');
				}else{
					a.push('1');
					b.push('1');
				}
			}else if(x[i]=='1'){
				a.push('0');
				b.push('1');
				if(!ch){
					ch = 1;
					swap(a,b);
				}
			}else{
				a.push('0');
				b.push('0');
			}
		}
		cout << a << "\n" << b << "\n";
	}
}