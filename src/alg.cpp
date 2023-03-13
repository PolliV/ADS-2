// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return value;
  } else if (n % 2 == 0) {
    return pown(value * value, n / 2);
  } else {
    return pown(value * value, n / 2) * value;
  }
}

uint64_t fact(uint16_t n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double summi = 0;
  for (int i = 0; i <= count; i++) {
    summi += calcItem(x, count - i);
  }
  return summi;
}

double sinn(double x, uint16_t count) {
  double summi = 0;
  for (int i = 1; i <= count; i++) {
    summi += pown(-1, i - 1) * calcItem(x, 2 * i - 1);
  }
  return summi;
}

double cosn(double x, uint16_t count) {
  double summi = 0;
  for (int i = 1; i <= count; i++) {
    summi += pown(-1, i - 1) * calcItem(x, 2 * i - 2);
  }
  return summi;
}
