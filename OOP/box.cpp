#include <iostream>
#include <ostream>

using namespace std;

class Box
{
private:
  int length, breadth, height;

public:
  Box()
  {
    length = 0;
    breadth = 0;
    height = 0;
  }
  Box(int l, int b, int h)
  {
    length = l;
    breadth = b;
    height = h;
  }
  Box(Box &C)
  {
    length = C.length;
    breadth = C.breadth;
    height = C.height;
  }
  long long getlength()
  {
    return length;
  }
  long long getBreadth()
  {
    return breadth;
  }
  long long getHeight()
  {
    return height;
  }
  long long CalculateVolume()
  {
    long long run = getlength() * getBreadth() * getHeight();
    return run;
  }
  bool operator<(Box &b)
  {
    if (b.length > length)
      return 1;
    else if (b.height > breadth && b.length == length)
      return 1;
    else if (b.height > height && b.breadth == breadth && b.length == length)
      return 1;
    else
      return 0;
  }
  friend ostream &operator<<(std::ostream &out, Box &box)
  {
    out << box.length;
    out << box.breadth;
    out << box.height;
    return out;
  }
};
  ostream &operator<<(std::ostream &out, Box &box)
  {
    out << box.getlength();
    out << box.getBreadth();
    out << box.getHeight();
    return out;
  }

void check2()
{
  int n;
  cin >> n;
  Box temp;
  for (int i = 0; i < n; i++)
  {
    int type;
    cin >> type;
    if (type == 1)
    {
      cout << temp << endl;
    }
    if (type == 2)
    {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      temp = NewBox;
      cout << temp << endl;
    }
    if (type == 3)
    {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      if (NewBox < temp)
      {
        cout << "Lesser\n";
      }
      else
      {
        cout << "Greater\n";
      }
    }
    if (type == 4)
    {
      cout << temp.CalculateVolume() << endl;
    }
    if (type == 5)
    {
      Box NewBox(temp);
      cout << NewBox << endl;
    }
  }
}

int main()
{
  check2();
}