#include<bits/stdc++.h>
#define ll long long
#define f(n) for(int i=0;i<n;i++)
#define F(i,x,n) for(int i=x;i<n;i++)
#define last std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define vi vector<int>
#define vd vector<double>
#define deb(x) cout<<#x<<" "<<x<<endl   //nice
using namespace std;
bool decr(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}
int main()
{
      last
      ll n,i,j,ans=0,tweight,profit=0;
      double x,y;
      vd vw,vp;
      vector<pair<double,int>> vpl;
      cin>>n>>tweight;
      f(n)
      {
          cin>>x;
          vw.pb(x);
      }
      f(n)
      {
          cin>>x;
          vp.pb(x);
      }
      f(n)
      {
          y=vp.at(i)/vw.at(i);
          vpl.push_back(make_pair(y,i));
      }
      sort(vpl.begin(),vpl.end(),decr);
      f(n)
      {
          if(tweight>vw.at(vpl[i].second))
          {
              profit=profit+vp.at(vpl[i].second);
              deb(vp.at(vpl[i].second));
              tweight=tweight-vw.at(vpl[i].second);
              deb(tweight);
          }
          else
          {
              profit+=tweight*vpl[i].first;
              deb(vpl[i].first);
              break;
          }
      }
    cout<<profit<<endl;
}
