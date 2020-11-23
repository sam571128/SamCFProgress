#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int a,b,c,d,e,f;
	cout << "XOR " << 1 << " " << 2 << endl; 
	cin >> a;
	cout << "AND " << 1 << " " << 2 << endl;
	cin >> b;
	cout << "XOR " << 2 << " " << 3 << endl;
	cin >> c;
	cout << "AND " << 2 << " " << 3 << endl;
	cin >> d;
	e = a^c;
	cout << "AND " << 1 << " " << 3 << endl; 
	cin >> f;

	int sum1 = a+2*b, sum2 = c+2*d, sum3 = e+2*f; 
	int arr[n];
	arr[2] = (sum1+sum2+sum3)/2-sum1;
	arr[0] = (sum1+sum2+sum3)/2-sum2;
	arr[1] = (sum1+sum2+sum3)/2-sum3;
	for(int i = 3;i < n;i++){
		cout << "XOR " << 1 << " " << i+1 << endl;
		int res;
		cin >> res;
		arr[i] = (res^arr[0]);
	}
	cout << "! ";
	for(int i = 0; i < n;i++) cout << arr[i] << " ";	
}