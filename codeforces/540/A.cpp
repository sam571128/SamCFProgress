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
typedef vector<string> vs; 

int main(){
	fastio
	int temp;
	cin >> temp;
	string a,b;
	cin >> a >> b;
	int sum = 0;
	for(int i = 0; i < temp;i++){
		sum += min(min(abs(a[i]-b[i]),abs(b[i]+10-a[i])),min(abs(a[i]-b[i]),abs(a[i]+10-b[i])));
	}
	cout << sum;
	return 0;
}