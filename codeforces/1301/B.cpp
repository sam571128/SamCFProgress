#include<bits/stdc++.h>
using namespace std;

const int maxx=1e5+100;
int a[maxx];
vector<int>p;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      p.clear();
      int n;cin>>n;
      for(int i=1;i<=n;i++) cin>>a[i];
      for(int i=1;i<=n;i++) if(a[i]!=-1 && (a[i-1]==-1 || a[i+1]==-1)) p.push_back(a[i]);
      sort(p.begin(),p.end());
      int m,k;
      if(p.empty()) k=0;
      else k=(p[0]+p[p.size()-1])/2;
      m=0;
      for(int i=1;i<=n;i++){
          if(a[i]==-1) a[i]=k;
          if(i>=2) m=max(m,abs(a[i]-a[i-1]));
      }
      cout<<m<<" "<<k<<endl;
    }
    return 0;
}