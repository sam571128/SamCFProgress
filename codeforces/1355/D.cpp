#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,s;
	cin >> n >> s;
	if(2*n>s){
		cout << "NO\n";
	}else{
		cout << "YES\n";
		for(int i = 0;i < n-1;i++){
			cout << 2 << " ";
		}
		cout << s-2*(n-1) << "\n" << 1 << "\n";
	}
}