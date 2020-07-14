#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int grid[10][10];
int main(){
    fastio
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            char tmp;
            cin >> tmp;
            if(tmp=='X') grid[i][j]=1;
            else if(tmp=='O') grid[i][j] = 2;
        }
    }
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<=5;j++)
        {
            int p=0;
            for (int k=0;k<5;k++)
            {
                if (grid[i][j+k]==2)
                {
                    p=10;
                }
                if (!grid[i][j+k])
                {
                    p++;
                }
            }
            if (p<=1)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    for (int i=0;i<=5;i++)
    {
        for (int j=0;j<10;j++)
        {
            int p=0;
            for (int k=0;k<5;k++)
            {
                if (grid[i+k][j]==2)
                {
                    p=10;
                }
                if (!grid[i+k][j])
                {
                    p++;
                }
            }
            if (p<=1)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    for (int i=4;i<10;i++)
    {
        for (int j=0;j<=5;j++)
        {
            int p=0;
            for (int k=0;k<5;k++)
            {
                if (grid[i-k][j+k]==2)
                {
                    p=10;
                }
                if (grid[i-k][j+k]==0)
                {
                    p++;
                }
            }
            if (p<=1)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    for (int i=0;i<=5;i++)
    {
        for (int j=0;j<=5;j++)
        {
            int p=0;
            for (int k=0;k<5;k++)
            {
                if (grid[i+k][j+k]==2)
                {
                    p=10;
                }
                if (grid[i+k][j+k]==0)
                {
                    p++;
                }
            }
            if (p<=1)
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
}