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
		string arr[n];
		for(int i = 0;i < n;i++) cin >> arr[i];
		bool check = true;
		for(int i = 0;i < n-1;i++){
			for(int j = 0;j < n-1;j++){
				if(arr[i][j]=='1'){
					if(arr[i+1][j]!='1'&&arr[i][j+1]!='1') check = false;
				}
			}
		}
		cout << (check ? "YES\n" : "NO\n");
	}
}