#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	vector<int> ans(n,-1);
	bool numbers[n];
	memset(numbers,false,sizeof numbers);
	for(int i = 0; i < n;i++) cin >> arr[i];
	for(int i = 1; i < n;i++){
		if(arr[i]!=arr[i-1]){
			ans[i] = arr[i-1];
			numbers[arr[i-1]] = 1;
		}
	}
	numbers[arr[n-1]] = 1;
	int tmp = 0;
	for(int i =	0;i < n;i++){
		while(numbers[tmp]) tmp++;
		if(ans[i]==-1){
			ans[i] = tmp;
			numbers[tmp] = 1;
		} 
		cout << ans[i] << " ";
	}
}