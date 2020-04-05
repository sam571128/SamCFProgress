#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int a;
		cin >> a;
		int b = 0,c = 0,d = 0;
		int index = 1;
		while(a--){
			int temp;
			cin >> temp;
			if(temp%2==0){
				b = index;
			}else if(!c){
				c = index;
			}else if(!d){
				d = index;
			}
			index++;
		}
		if(b){
			cout << "1\n" << b << "\n";
		}else if(c&&d){
			cout << "2\n" << c << " " << d << "\n";
		}else{
			cout << "-1\n";
		}
		
	}
}
