#include <iostream>
using namespace std;

void Nhap(int n, int a[]){
  for (int i = 0; i < n ; i++){
    cin >> a[i];
  }
}

void Insertion_sort(int n, int a[]){
  int pos;
  for (int i = 1; i < n; i++){
    pos = i - 1;
    int value = a[i];
    while (pos >= 0 && a[pos] > value){
      a[pos + 1] = a[pos];
      pos--;
      for (int i =0 ; i < n; i++){
        cout << a[i] << " ";
      }
      cout << endl;
    }
      a[pos + 1] = value;
      for (int i =0 ; i < n; i++){
        cout << a[i] << " ";
      }
      cout << endl;
  }
}

int a[100001];
int main(){
  int n;
  cin >> n;
  Nhap(n,a);
  Insertion_sort(n,a);
}