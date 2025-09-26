#include<bits/stdc++.h>
using namespace std;

int cc[1000005],nc;

void compress(vector<int> &v){
  unordered_map<int,int> mp;
  for(auto &e:v) if(!mp[e]) cc[++nc]=e, e=mp[e]=nc;
}
