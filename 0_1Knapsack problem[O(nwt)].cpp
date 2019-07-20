#include <bits/stdc++.h>

using namespace std;
void knapsack(vector<int> &,vector<int> &,int);
int main()
{
    int wt,n,i,x;
    cin>>n;
    vector<int> w,val;
    for(i=0;i<n;i++)
    {
        cin>>x;
        val.push_back(x);
    }
    for(i=0;i<n;i++)
    {
        cin>>x;
        w.push_back(x);
    }
    cin>>wt;
    knapsack(val,w,wt);
}
void knapsack(vector<int> &val,vector<int> &w,int wt)
{
    int i,j,temp,a[val.size()+2][wt+2];
    for(i=0;i<=val.size();i++)
    {
        for(j=0;j<=wt;j++)
        {
            if(i==0||j==0)
                a[i][j]=0;
            else
              if(w.at(i-1)<=j)
                 a[i][j]=a[i-1][j]>(val.at(i-1)+a[i-1][j-w.at(i-1)])?a[i-1][j]:(val.at(i-1)+a[i-1][j-w.at(i-1)]);
           else
            a[i][j]=a[i-1][j];

        }
    }
    cout<<a[val.size()][wt];
}

