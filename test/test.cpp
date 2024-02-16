#include "../quaternion.h"
#include <assert.h>

void test_operators() {
  quaternion<double>x {5.5, 7.6, 1.3, 10.3};
  quaternion<double>y {3.1245, 4.4, 9, 7.643};
  assert((x+=y).accessReal() == 8.6245);
  assert(x.accessI()== 12);
  assert(x.accessJ()== 10.3);
  assert(x.accessK()== 17.943);
  x-=y;
  assert(x.accessReal() == 5.5);
  assert(x.accessI()== 7.6);
  assert(x.accessJ()== 1.3);
  assert(x.accessK()== 10.3);
  
}



int main(int argc, char** argv) {

  test_operators();

  return 0;

}
