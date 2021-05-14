#include <iostream>
using namespace std;
class test{int code;static int count; public: void showcode(){cout<<"code="<<code;} static void showcount(){cout<<"count="<<count;}};
int test::count;
int main() {
  test t;
  t.showcode(); t.showcount();
  return 0;
}
