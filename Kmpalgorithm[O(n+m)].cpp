#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,p;
    cin>>s>>p;
    int i=1,j=0;
    vector<int> vec,patsearch;
    vec.push_back(0);
    while(i<p.length())
    {
        if(p[i]==p[j])
        {
            vec.push_back(j+1);
            j++;
            i++;
        }
        else
        {
            if(j==0)
            {
                vec.push_back(0);
                i++;
            }
            else
            {
                j=vec.at(j-1);
            }
        }
    }
    j=0;
    for(i=0;i<s.length();i++)
    {
       if(s[i]==p[j])
       {
           j++;
       }
       else
       {
           if(j-1<=0)
            j=0;
           else
           j=vec.at(j-1);
       }
       if(j==p.length())
       {
           patsearch.push_back(i-j);
           j=vec.at(j-1);
       }
    }
    cout<<patsearch.size()<<"patterns are found"<<endl;
    vector<int>::iterator it;
    it=patsearch.begin();
    while(it!=patsearch.end())
    {
        for(i=*it+1;i<=*it+p.length();i++)
            cout<<i<<":"<<s[i]<<" ";
        cout<<endl;
        it++;
    }
}
