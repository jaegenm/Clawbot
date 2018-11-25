#include "main.h"
#include "chassis.h"

void chassisSet(int left, int right) {
  motorSet(2, left);
  motorSet(3, right);
}
