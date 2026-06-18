#include <iostream>
#include <ostream>
using namespace std;

class Vector {
public:
  int x, y;
  Vector(int x, int y) : x(x), y(y) {}
  Vector operator+(const Vector &b) { return Vector(x + b.x, y + b.y); }

  friend ostream &operator<<(ostream &os, const Vector &v) {
    os << "(" << v.x << "," << v.y << ")";
    return os;
  }
};

int main() {
  Vector a(1, 2), b(3, 4);
  cout << a << "\n";
  cout << b << "\n";
}
