#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	int m;
	cin >> m;
	int arr2[m];
	for(int i = 0;i < m;i++){
		cin >> arr2[i];
	}
	int ma = 0;
	int occur = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(arr2[j]%arr[i]==0&&arr2[j]/arr[i]==ma)occur++;
			if(arr2[j]%arr[i]==0&& arr2[j]/arr[i] > ma){
				ma = arr2[j] / arr[i];
				occur = 1;
			}
		}
	}
	cout << occur << "\n";
}
