#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int n,m,a,b;
	cin >> n >> m >> a >> b;
	if (m * a <= b)
        cout << n * a << "\n";
    else 
        cout << (n/m) * b + min((n%m) * a, b) << "\n";
 
    return 0;
}