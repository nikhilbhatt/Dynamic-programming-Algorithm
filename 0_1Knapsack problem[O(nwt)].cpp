//no need to sort the values and weights.

#include <bits/stdc++.h>

using namespace std;
void knapsack(vector<int> &,vector<int> &,int);
int main()
{
    int wt,n,i,x;
    cin>>n>>wt;  
    vector<int> w,val;
    for(i=0;i<n;i++) //enter n weight 
    {
        cin>>x;
        w.push_back(x);
    }
    for(i=0;i<n;i++)  //enter n values
    {
        cin>>x;
        val.push_back(x);
    }
    knapsack(val,w,wt);
}
void knapsack(vector<int> &val,vector<int> &w,int wt)
{
   
    int i,j,temp,a[val.size()+1][wt+1];  // memoization table
    for(i=0;i<=val.size();i++)
    {
        for(j=0;j<=wt;j++)
        {
            if(i==0||j==0)
                a[i][j]=0;
            else
              if(w.at(i-1)<=j)
                 a[i][j]=a[i-1][j]>(val.at(i-1)+a[i-1][j-w.at(i-1)])?a[i-1][j]:(val.at(i-1)+a[i-1][j-w.at(i-1)]);
                   //val.at(i-1)+a[i-1][j-w.at(i-1)]=effect of adding the new value+ effect of remaining sum value)
                   //max(a[i-1][j],val.at(i-1)+a[i-1][j-w.at(i-1)]);
                   //updating value of i,j using previous values.
           else
            a[i][j]=a[i-1][j];

        }
    }
    cout<<a[val.size()][wt]<<endl; //final value of 2d array i.e.Table
    int weight[val.size()+1]={0},sx=0;
    temp=a[val.size()][wt];
    for(i=val.size()-1;i>=0;i--)
    {
        sx=0;
        for(j=0;j<=wt;j++)
        {
            if(a[i][j]==temp)
            {
                sx=1;
                break;
            }
        }
        if(sx==0)
        {
            weight[i]=1;
            temp=temp-val.at(i);
        }
        //if(temp<0)
            //break;

    }
    for(i=0;i<val.size();i++)
        cout<<weight[i]<<" ";
}

