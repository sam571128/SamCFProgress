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

int checkprime(int a){
	for(int i = 2;i <= sqrt(a);i++){
		if(a%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	fastio
	int a,b;
	cin >> a >> b;
	for(int i = a + 1;i < b;i++){
		if(checkprime(i)){
			cout << "NO";
			return 0;
		}
	}
	cout << (checkprime(b) ? "YES" : "NO");
}
