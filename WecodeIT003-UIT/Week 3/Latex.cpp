#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(const string&s){
  stack<char> kt;
  for (char c : s){
    if ( c =='[' || c == '{' || c == '('){
      kt.push(c);
    }
    else if( c ==']' || c == '}' || c == ')'){
      if (kt.empty()) return 0;
        char tmp = kt.top();
      if ((c ==']' && tmp != '[') || (c =='}' && tmp != '{') || (c == ')' && tmp != '('))
          return 0;
          kt.pop();
    }
  }
  if (kt.empty()) return 1;
  return 0;
}


int main(){
  string s;
  getline(cin,s);
  if (check(s) == 1) cout << "1"; 
  else cout << "0";
  return 0;
}
