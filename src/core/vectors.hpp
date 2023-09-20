#pragma once

#include "../types/typdes.hpp"

namespace vectors {

class Point {
 public:
  double x, y;

 public:
  Point(double x, double y);
};

class Vector {
  Point origin;
  Point end;

 public:
  // toString prints the vector object as a string representation in stdout.
  void toString();

  // add: sum up the "self" vector and "v" vector togher and returns its sum.
  Vector add(Vector* v);

  // multiply the "self" vector by a real number k.
  Vector multiply(double k);

  // isEqual compare two vector, the "self" vector is equal to v and,
  // return true if they are equal, else returns false.
  bool isEqual(Vector* v);
};
}  // namespace vectors
