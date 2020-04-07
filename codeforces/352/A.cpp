#include <bits/stdc++.h>

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
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/
int main(){
	fastio
	int t;
	cin >> t;
	int cf = 0;
	int cz = 0;
	while(t--){
		cini(temp);
		cf+=(temp==5);
		cz+=(temp==0);
	} 
	if(cz==0){
		cout << -1;
		return 0;
	}
	if(cf<9){
		cout << 0;
		return 0;		
	}else{
		while(cf>=9){
			for(int i = 0;i < 9;i++){
				cout<< 5;
			}
			cf-=9;
		}
		for(int i = 0;i < cz;i++){
			cout << 0;
		}
	}
	return 0;
	
}
