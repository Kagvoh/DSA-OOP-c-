#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void Nhap(DATHUC &B, double heso, int somu){
  DONTHUC *New = new DONTHUC(heso,somu);
  Node *Newnode = new Node(New);
  if (!B.head){
    B.head = B.tail = Newnode;
  }
  else{
    B.tail->next = Newnode;
    B.tail = Newnode;
  }
}

void Xuat(DATHUC &B){
  Node *tmp = B.head;
  bool first = true;
  while (tmp != nullptr){
    double hs = tmp->data->heso;
    int sm = tmp->data->somu;
    
    if (hs == 0){
      tmp = tmp->next;
      continue;
    }

    if(!first){
      if(hs > 0){
        cout << "+";
      }
    }
    if (abs(hs) != 1 || sm == 0){
      cout << hs;
    }
    else if(hs == -1){
      cout << "-";
    }
    if (sm > 1){
      cout << "x^" << sm; 
    }
    else if( sm == 1) cout << "x";
    first = false;
    tmp = tmp->next;
  }
  if (first) cout << "0";
}

double TinhDaThuc(DATHUC &B, double x){
  double s = 0;
  Node *tmp = B.head;
  while (tmp != nullptr){
    double hs = tmp->data->heso;
    int sm = tmp->data->somu;
    s+=hs*pow(x,sm);
    tmp = tmp->next;
  }
  return s;
}

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
