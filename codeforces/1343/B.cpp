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
		if(n%4!=0){
			cout << "NO\n";
		}else{
			cout << "YES\n";
			for(int i = 2;i <= n;i+=2){
				cout << i << " ";
			}
			for(int i = 1;i <= n;i+=2){
				if(i==n-1){
					cout << i+n/2 << "\n";
				}else{
					cout << i << " ";
				}
			}
		}
	} 
}
