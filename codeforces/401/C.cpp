#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int arr[(int)1e6+5];
int main(){
	fastio
	int n,m;
	cin >> n >> m;
	if(2*(n+1)<m||(n-1)>m){
		cout << -1 << "\n";
		return 0;
	}
	for(int i = 1;i < n;i++) arr[i]++;
	m-=n-1;
	for(int i = 0;i <= n;i++){
		while(m&&arr[i]<2) m--, arr[i]++;
	}
	for(int i = 0;i < arr[0];i++) cout << 1;
	for(int i = 1;i <= n;i++){
		cout << 0;
		for(int j = 0;j < arr[i];j++) cout << 1;
	}
}