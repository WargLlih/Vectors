#include "./vectors.hpp"

#include <stdio.h>

//_____________________________ Point __________________________________________
vectors::Point::Point(double x, double y) {
  this->x = x;
  this->y = y;
}

//_____________________________ Point __________________________________________
void vectors::Vector::toString() {
  printf("(%.2lf, %.2lf) (%.2lf, %.2lf)\n", this->origin.x, this->origin.y,
         this->end.x, this->end.y);
}

//______________________________________________________________________________
Vector VectorAdd(Vector* v1, Vector* v2) {
  Vector result;

  result.origin.x = v1->origin.x + v2->origin.x;
  result.origin.y = v1->origin.y + v2->origin.y;

  result.end.x = v1->end.x + v2->end.x;
  result.end.y = v1->end.y + v2->end.y;

  return result;
}

//______________________________________________________________________________
Vector VectorMul(Vector* v, double k) {
  Vector result;

  result.origin.x = v->origin.x * k;
  result.origin.y = v->origin.y * k;

  result.end.x = v->end.x * k;
  result.end.y = v->end.y * k;

  return result;
}

//______________________________________________________________________________
bool VectorIsEqual(Vector* v1, Vector* v2) {
  double origin_offset_x = v2->origin.x - v1->origin.x;
  double origin_offset_y = v2->origin.y - v1->origin.y;

  if ((v1->end.x + origin_offset_x) == v2->end.x &&
      (v1->end.y + origin_offset_y) == v2->end.y) {
    return true;
  }

  return false;
}