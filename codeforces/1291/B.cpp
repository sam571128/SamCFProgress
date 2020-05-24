#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0;i < n;i++) cin >> v[i];
		int prefixEnd = -1, suffixEnd = n;
		for(int i = 0;i < n;i++){
			if(v[i] < i) break;
			prefixEnd = i;
		}
		for(int i = n-1;i >= 0;i--){
			if(v[i] < n-1-i) break;
			suffixEnd = i;
		}
		if(suffixEnd<=prefixEnd){
			cout << "Yes" << "\n";
		}else{
			cout << "No" << "\n";
		}
	}
}