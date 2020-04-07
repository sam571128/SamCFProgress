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
	int n,k;
	cin >> n >> k;
	for(int i = n;i > n - k;i--){
		cout << i << " ";
	}
	for(int i = 1;i <= n-k;i++){
		cout << i << " ";
	}
	return 0;
}
