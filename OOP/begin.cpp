// #include <iostream>

// using namespace std;

// class Student {
// public:
//     string name;
//     int age;
//     Student(string n, int a){
//      name = n;
//      age = a;
//     }
//     Student(string name, int age){
//       this->name = name;
//       this->age = age;
//     }
//     void display(){
//       cout << "Name: " << name << endl;
//       cout << "Age: " << age << endl;
//     }
// };
// int main() {
//     Student s1("Long", 24);
//     Student s2("Kien", 29);
//     s1.display();
//     s2.display();
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
	int id;
	string name;
	int age;
	string address;
public:
    void set_id(int id){
        this->id = id;
    }
    void set_name(string name){
        this->name = name;
    }
    void set_age(int age){
        this->age = age; 
    }
    void set_address(string address){
        this->address = address;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getAddress(){
        return address;
    }
};

int main() {
	Person p;
  p.set_id(1001);
  p.set_name("Quynh");
  p.set_age(24);
  p.set_address("Ha Noi");
	cout << "Id: " << p.getId() << endl;
	cout << "Name: " << p.getName() << endl;
	cout << "Age: " << p.getAge() << endl;
	cout << "Address: " << p.getAddress() << endl;
	return 0;
}
