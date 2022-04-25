#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void merge(ll k,ll l,ll m,ll ct,vector<vector<ll>>& v4,vector<ll>& v5)
 {
    ll y[m-1];
    ll xt[m-1];
    ll it,tn,tj,tmpit,minv;
    tn=0;
    tj=0;
    for(it=0;it<m-1;it++)
     {
      y[it]=0;
      xt[it]=0;
     }

    for(it=k;it<=l;it++)
     tn+=(v4[it]).size();
    while(tj<tn)
     {
      minv=1000000000;
      for(it=k;it<=l;it++)
       {
        if((y[it-k])*ct+xt[it-k]<v4[it].size())
         {
          if(xt[it-k]==ct)
           {
            xt[it-k]=0;
            y[it-k]++;
            if((v4[it])[((y[it-k])*ct+xt[it-k])]<minv)
             {
              minv=(v4[it])[((y[it-k])*ct+xt[it-k])];
              tmpit=it;
             }
           }
          else
           {
            if((v4[it])[((y[it-k])*ct+xt[it-k])]<minv)
             {
              minv=(v4[it])[((y[it-k])*ct+xt[it-k])];
              tmpit=it;
             }
           }
         }
       }
      v5.push_back(minv);
      xt[tmpit-k]++;
      tj++;
     }
 }

int main()
 {
  ll b,c,n,np,j,i,val,pgno,npnew,x;
  cin>>b;
  cin>>c;
  cin>>n;
  np=ceil(float(n)/float(c));
  pgno=-1;
  x=0;
  npnew=ceil(float(np)/float(b));
  vector<vector<ll>> v(npnew);
  for(j=0;j<n;j++)
   {
    if(j%(b*c)==0)
     pgno++;
    cin>>val;
    (v[pgno]).push_back(val);
   }
  for(j=0;j<npnew;j++)
   sort((v[j]).begin(),(v[j]).end());

  vector<vector<ll>> v6(np);
  while(npnew!=1)
   {
    np=npnew;
    npnew=ceil(float(np)/float(b-1));
    vector<vector<ll>> v2(np);
    if(x==0)
     {
      for(j=0;j<np;j++)
       for(i=0;i<v[j].size();i++)
         (v2[j]).push_back((v[j])[i]);
      x=1;
     }
    else
     {
      for(j=0;j<np;j++)
       for(i=0;i<v6[j].size();i++)
        (v2[j]).push_back((v6[j])[i]);
     }
    vector<vector<ll>> v3(npnew);
    for(j=0;j<npnew;j++)
     {
      if((j+1)*(b-1)-1<v2.size())
       merge(j*(b-1),(j+1)*(b-1)-1,b,c,v2,v3[j]);
      else
       {
        if(j*(b-1)<v2.size())
         merge(j*(b-1),v2.size()-1,b,c,v2,v3[j]);
       }
     }
    for(j=0;j<np;j++)
     v6[j].clear();
    for(j=0;j<npnew;j++)
     for(i=0;i<v3[j].size();i++)
      (v6[j]).push_back((v3[j])[i]);
 
    if(npnew==1)
     {
      for(j=0;j<npnew;j++)
       for(i=0;i<n;i++)
        cout<<(v3[j])[i]<<endl;
     }
   }
  for(j=0;j<npnew;j++)
   for(i=0;i<n;i++)
    if(x==0)
      cout<<(v[j])[i]<<endl;
  return 0;
}