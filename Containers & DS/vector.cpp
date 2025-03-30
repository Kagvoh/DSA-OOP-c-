#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>S;
    for(int i=0;i<=5;i++){
        S.push_back(i);
        cout << "I love You"<< endl;
        cout <<" size :" << S.size() << endl;
        cout << "capacity :"<< S.capacity()<< endl;
        cout << "max_size :"<< S.max_size()<< endl;
    }
    // for (auto it = S.begin(); it != S.end(); it++){
    //     cout << *it << "I love you"<<endl ;
    // }
    return 0;
}