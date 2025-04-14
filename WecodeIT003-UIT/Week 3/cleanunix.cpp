#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string CleanUnix(string s){
  stack<string> st;
  string tmp;
  for (int i = 0 ; i < s.size(); i++){
    if (s[i] == '/') continue;
    tmp = "";
    while (i < s.size() && s[i] != '/'){
      tmp += s[i];
      i++;
    }
    if (tmp == ".." && !st.empty()) st.pop();
    else if (tmp != ".") st.push(tmp);
  }
  vector<string> v;
  while (!st.empty()){
    v.push_back(st.top());
    st.pop();
  }
  reverse(v.begin(),v.end());
  string ans;
  if (s[0] == '/') ans = "/";
  else ans = "./";
  for (int i = 0 ; i < v.size(); i++){
    ans += v[i];
    if(i != v.size() - 1) ans += '/'; 
  } 
  if (ans.back() == '/' && ans.size() > 1) ans.pop_back();
  return ans;
}

int main(){
  string s;
  cin >> s;
  cout << CleanUnix(s);
}