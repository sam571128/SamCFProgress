#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define pf pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/
int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1;i <= sqrt(n);i++){
			if(n%i==0){
				if(log2(n/i+1)==floor(log2(n/i+1))){
					cout << i << "\n";
					break;
				}
				if(i!=1&&log2(i+1)==floor(log2(i+1))){
					cout << n/i << "\n";
					break;
				}
			}
		}
	} 
}
