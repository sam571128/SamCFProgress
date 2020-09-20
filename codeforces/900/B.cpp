#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int ans = -1;
	for(int i = 1; i <= 1000; i++){
		a = a * 10;
		if(a / b == c){	
			ans = i; 
			break; 
		}
		a = a % b;
	}
	cout << ans << "\n";
}