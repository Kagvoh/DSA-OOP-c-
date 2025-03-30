#include <iostream>
using namespace std;

void Nhap(int n, int a[]){
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
}

int output[100001]; 
void Count(int n, int a[]){
  int count[10] = {0};
  for (int i = 0 ; i < n; i++){
    count[a[i]]++;
  }
  for (int i = 1 ; i < 10; i++){
    count[i] += count[i-1];
  }
  for (int i = n - 1; i >= 0; i--){
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--;
  }
  for (int i = 0 ; i < n; i++){
    a[i] = *(output + i);
  }
}

int a[100001];
int main(){
  int n;
  cin >> n;
  Nhap(n,a);
  Count(n,a);
  for (int i = 0 ; i < n; i++){
      cout << a[i] << " ";
  }
  return 0;
}