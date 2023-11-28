#include "quaternion.h"
#include <iostream>

template <class Type> Type  mkcopy(Type obj) {
	return obj; }

int main(){
  Quaternion q(1,2,3,4);
  Quaternion zero;
  Quaternion c = mkcopy(q);
  zero.print();
  q.print();
  c.print();
  Quaternion b;
  b = c;
  b = Quaternion(1,2,3,4);
  b.print();
  Quaternion add(9,8,7,6);
  b += add;
  b.print();
  Quaternion d = Quaternion(1,1,1,1) + Quaternion(6,6,6,6);
  d.print();
  return 0;
}
