#include<bits/stdc++.h>
using namespace std;
int minjump(vector<int> &);
int main()
{
    int n,i,x,min_jump;
    vector<int> vec;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    min_jump=minjump(vec);
    cout<<min_jump<<endl;
}
int minjump(vector<int> &nvc)
{
    int temp,n=nvc.size(),i=0,jump=1,ladder,maxreach;
    if(n==1)
        return 0;   //we are already at the end
    if(nvc.at(i)<=0)
        return -1;   //we can't reach at the end
    ladder=nvc.at(0);
    maxreach=nvc.at(i)+i;
    for(i=1;i<n;i++)
    {
        if(i==n-1)
           return jump;
        temp=nvc.at(i)+i;
        maxreach=maxreach>temp?maxreach:temp;
        ladder--;
        if(ladder==0)
        {
            if(i>=maxreach)
                return -1;
            jump++;
            ladder=maxreach-i;
        }
    }
    return jump;
}
