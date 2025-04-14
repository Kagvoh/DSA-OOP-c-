#include <iostream>
#include <stack>
#include <string>

using namespace std;

int check(const string &s){
  int dem1 = 0, dem2 = 0;
  stack<char> kt;
  for (char c : s){
    kt.push(c);
  }
  while(!kt.empty()){
   if (kt.top() == '(') 
    dem1++;
   else if (kt.top() == ')') 
    dem2++;
   kt.pop();
  }
  return dem1 >= dem2 ? (dem1 - dem2) : (dem2 - dem1); 
}

int main(){
  string s;
  getline(cin,s);
  cout << check(s);
}