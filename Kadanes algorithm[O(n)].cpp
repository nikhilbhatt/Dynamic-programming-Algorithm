#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,ans,sum,x,max_sum,temp,temp_sum,start,end;
    cin>>n;
    vector<int> vec;
    for(i=0;i<n;i++)
    {
        cin>>x;
        vec.push_back(x);
    }
    max_sum=vec.at(0);
    temp_sum=0;
    start=0;
    end=0;    //these three variables are just to print subarrray.
    temp=0;
    for(i=0;i<n;i++)
    {
        temp_sum+=vec.at(i);
        if(temp_sum>max_sum)
            {
                max_sum=temp_sum;
                start=temp;
                end=i;
            }
        if(temp_sum<=0)
            {
                temp_sum=0;
                temp=i+1;
            }
    }
    for(i=start;i<=end;i++)
        cout<<vec.at(i)<<" ";
    cout<<"max sum="<<max_sum<<endl;
}
