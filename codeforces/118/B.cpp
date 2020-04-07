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
	int a;
	cin >> a;
	for(int i = 0;i <= a ;i++){
		for(int j = 0;j < 2*(a-i);j++){
			cout << " ";
		}
		for(int j = 0;j <= i;j++){
			cout << j;
			if(i!=0) cout << " "; 
		}
		for(int j = i-1;j >= 0;j--){
			cout << j;
			if(j!=0) cout << " ";
		}
		cout << "\n";
	}
	for(int i = a-1;i >= 0 ;i--){
		for(int j = 0;j < 2*(a-i);j++){
			cout << " ";
		}
		for(int j = 0;j <= i;j++){
			cout << j;
			if(i!=0) cout << " "; 
		}
		for(int j = i-1;j >= 0;j--){
			cout << j;
			if(j!=0) cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
