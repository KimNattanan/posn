#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b,int &x,int &y){
  if(b==0){
    x=1, y=0;
    return a;
  }
  int g = gcd(b,a%b,y,x);
  y -= x*(a/b);
  return g;
}
