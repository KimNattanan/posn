#include<bits/stdc++.h>
using namespace std;

int cc[1000005],nc;

void f(vector<int> &v){
  unordered_map<int,int> mp;
  for(auto &e:A) if(!mp[e]) cc[++nc]=e, e=mp[e]=nc;
  for(auto &e:B) if(!mp[e]) cc[++nc]=e, e=mp[e]=nc;
}
