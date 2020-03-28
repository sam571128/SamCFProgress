#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
using namespace std;

int main(){
	fastio
	string figures[] = {"Tetrahedron","Cube","Octahedron","Dodecahedron","Icosahedron"};
	int faces[] = {4,6,8,12,20};
	int a;
	cin >> a;
	int sum=0;
	while(a--){
		string a;
		cin >> a;
		for(int i = 0;i < 5;i++){
			if(a==figures[i]){
				sum+=faces[i];
				break;
			}
		}
	}
	cout << sum;
}