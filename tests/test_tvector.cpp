// Copyright 2024 Gleb Zaharov

#include <gtest.h>
#include "../lib_tvector/tvector.h"

TEST(TestTVector, equality) {
  int a[3] = {1, 2, 3};
  int b[3] = {2, 4, 6};
  int c[5] = {1, 3, 5, 7, 9};

  TVector<int> A1(a, 3);
  TVector<int> A2(a, 3);
  TVector<int>  B(b, 3);
  TVector<int>  C(c, 5);

  ASSERT_EQ(true, A1 == A2);
  ASSERT_EQ(false, A1 == B);
  ASSERT_EQ(false, B == C);
}
