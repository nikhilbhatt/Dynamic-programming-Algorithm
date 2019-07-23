#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define v vector<int>
#define f(i,n) for(int i=0;i<n;i++)
int main()
{
    int i,j,n,wt,x;
    cin>>n;
    v vec;
    f(i,n)
    {
        cin>>x;
        vec.pb(x);
    }
    cin>>wt;
    int a[n+1][wt+1];
    f(i,n)
    {
        f(j,wt+1)
        {
            if(j==0)
                a[i][j]=1;             //initial condition when we don't select any of
            else                        // the element and make the sum zero but the permutation become 1.
            if(i==0)
            {
                if(j<vec.at(i))
                    a[i][j]=0;
                else
                    if(j%vec.at(i)==0)
                      a[i][j]=1;
                      else
                        a[i][j]=0;
            }
            else
            if(j<vec.at(i))
                {
                    a[i][j]=a[i-1][j];
                }
                else
                {
                    a[i][j]=a[i-1][j]+a[i][j-vec.at(i)];
                }

        }
    }
    f(i,n)  //display every block of code
    {
        f(j,wt+1)
             {
                 cout<<a[i][j]<<" ";
             }
             cout<<endl;
    }
    cout<<"ans="<<a[n-1][wt];
}
