#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int h;
	cin >> h;
	int arr[h+1];
	bool isPer = true;
	for(int i = 0;i <= h;i++){
		cin >> arr[i];
		if(i!=0&&arr[i-1]!=1&&arr[i]!=1){
			isPer = false;
		}
	}
	if(isPer){
		cout << "perfect\n";
		return 0;
	}
	cout << "ambiguous\n";
	int now = 0;
	for(int i = 0;i <= h;i++){
		for(int j = 0;j < arr[i];j++) cout << now << " ";
		now += arr[i];
	}
	cout << "\n";
	now = 0;
	for(int i = 0;i <= h;i++){
		if(i!=0&&arr[i-1]!=1&&arr[i]!=1){
			for(int j = 0;j < arr[i]-1;j++) cout << now << " ";
			cout << now-1 << "\n";
		}else{
			for(int j = 0;j < arr[i];j++) cout << now << " ";
		}
		now += arr[i];
	}
}