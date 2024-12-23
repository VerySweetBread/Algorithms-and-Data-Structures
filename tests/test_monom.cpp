// Copyright 2024 Gleb Zaharov

#include <gtest.h>
#include "../lib_monom/cmonom.h"

TEST(CMonom, plus) {
  // x + x = 2x
  CMonom a(1, 1, 0, 0);
  CMonom b(1, 1, 0, 0);
  CMonom c = a + b;

  ASSERT_EQ(c.get_coef(), 2);
  ASSERT_EQ(c.get_p1(), 1);
  ASSERT_EQ(c.get_p2(), 0);
  ASSERT_EQ(c.get_p3(), 0);


  // y^2z + 2y^2z = 3y^2z
  a = CMonom(1, 0, 2, 1);
  b = CMonom(2, 0, 2, 1);
  c = a + b;

  ASSERT_EQ(c.get_coef(), 3);
  ASSERT_EQ(c.get_p1(), 0);
  ASSERT_EQ(c.get_p2(), 2);
  ASSERT_EQ(c.get_p3(), 1);
}


TEST(CMonom, minus) {
  // 2x - x = x
  CMonom a(2, 1, 0, 0);
  CMonom b(1, 1, 0, 0);
  CMonom c = a - b;

  ASSERT_EQ(c.get_coef(), 1);
  ASSERT_EQ(c.get_p1(), 1);
  ASSERT_EQ(c.get_p2(), 0);
  ASSERT_EQ(c.get_p3(), 0);


  // 3y^2z = y^2z = 2y^2z
  a = CMonom(3, 0, 2, 1);
  b = CMonom(1, 0, 2, 1);
  c = a - b;

  ASSERT_EQ(c.get_coef(), 2);
  ASSERT_EQ(c.get_p1(), 0);
  ASSERT_EQ(c.get_p2(), 2);
  ASSERT_EQ(c.get_p3(), 1);
}

TEST(CMonom, plus_throw) {
  // x + xz = ?
  CMonom a(1, 1, 0, 0);
  CMonom b(1, 1, 0, 1);

  EXPECT_THROW(a + b, std::logic_error);

  // y^2z + 2xyz = ?
  a = CMonom(1, 0, 2, 1);
  b = CMonom(2, 1, 1, 1);
  EXPECT_THROW(a + b, std::logic_error);
}

TEST(CMonom, minus_throw) {
  // x - xz = ?
  CMonom a(1, 1, 0, 0);
  CMonom b(1, 1, 0, 1);

  EXPECT_THROW(a - b, std::logic_error);

  // y^2z - 2xyz = ?
  a = CMonom(1, 0, 2, 1);
  b = CMonom(2, 1, 1, 1);
  EXPECT_THROW(a - b, std::logic_error);
}

TEST(CMonom, mul) {
  // 2x * yz = 2xyz
  CMonom a = CMonom(2, 1, 0, 0);
  CMonom b = CMonom(1, 0, 1, 1);
  CMonom c = a * b;

  ASSERT_EQ(c.get_coef(), 2);
  ASSERT_EQ(c.get_p1(), 1);
  ASSERT_EQ(c.get_p2(), 1);
  ASSERT_EQ(c.get_p3(), 1);

  // 2x * 3x^2yz^5 = 6x^3yz^5
  a = CMonom(2, 1, 0, 0);
  b = CMonom(3, 2, 1, 5);
  c = a * b;

  ASSERT_EQ(c.get_coef(), 6);
  ASSERT_EQ(c.get_p1(), 3);
  ASSERT_EQ(c.get_p2(), 1);
  ASSERT_EQ(c.get_p3(), 5);
}

TEST(CMonom, div) {
  // 2xyz / yz = 2x
  CMonom a = CMonom(2, 1, 1, 1);
  CMonom b = CMonom(1, 0, 1, 1);
  CMonom c = a / b;

  ASSERT_EQ(c.get_coef(), 2);
  ASSERT_EQ(c.get_p1(), 1);
  ASSERT_EQ(c.get_p2(), 0);
  ASSERT_EQ(c.get_p3(), 0);

  // 6x^3yz^5 / 3x^2yz^5 = 2x
  a = CMonom(6, 3, 1, 5);
  b = CMonom(3, 2, 1, 5);
  c = a / b;

  ASSERT_EQ(c.get_coef(), 2);
  ASSERT_EQ(c.get_p1(), 1);
  ASSERT_EQ(c.get_p2(), 0);
  ASSERT_EQ(c.get_p3(), 0);
}

TEST(CMonom, unaryminus) {
  CMonom a = CMonom(2, 3, 5, 1);
  CMonom b = -a;

  ASSERT_EQ(b.get_coef(), -2);
  ASSERT_EQ(b.get_p1(), 3);
  ASSERT_EQ(b.get_p2(), 5);
  ASSERT_EQ(b.get_p3(), 1);
}

TEST(CMonom, eq_plus) {
  // x + x = 2x
  CMonom a(1, 1, 0, 0);
  CMonom b(1, 1, 0, 0);
  a += b;

  ASSERT_EQ(a.get_coef(), 2);
  ASSERT_EQ(a.get_p1(), 1);
  ASSERT_EQ(a.get_p2(), 0);
  ASSERT_EQ(a.get_p3(), 0);


  // y^2z + 2y^2z = 3y^2z
  a = CMonom(1, 0, 2, 1);
  b = CMonom(2, 0, 2, 1);
  a += b;

  ASSERT_EQ(a.get_coef(), 3);
  ASSERT_EQ(a.get_p1(), 0);
  ASSERT_EQ(a.get_p2(), 2);
  ASSERT_EQ(a.get_p3(), 1);
}


TEST(CMonom, eq_minus) {
  // 2x - x = x
  CMonom a(2, 1, 0, 0);
  CMonom b(1, 1, 0, 0);
  a -= b;

  ASSERT_EQ(a.get_coef(), 1);
  ASSERT_EQ(a.get_p1(), 1);
  ASSERT_EQ(a.get_p2(), 0);
  ASSERT_EQ(a.get_p3(), 0);


  // 3y^2z = y^2z = 2y^2z
  a = CMonom(3, 0, 2, 1);
  b = CMonom(1, 0, 2, 1);
  a -= b;

  ASSERT_EQ(a.get_coef(), 2);
  ASSERT_EQ(a.get_p1(), 0);
  ASSERT_EQ(a.get_p2(), 2);
  ASSERT_EQ(a.get_p3(), 1);
}

TEST(CMonom, eq_plus_throw) {
  // x + xz = ?
  CMonom a(1, 1, 0, 0);
  CMonom b(1, 1, 0, 1);

  EXPECT_THROW(a += b, std::logic_error);

  // y^2z + 2xyz = ?
  a = CMonom(1, 0, 2, 1);
  b = CMonom(2, 1, 1, 1);
  EXPECT_THROW(a += b, std::logic_error);
}

TEST(CMonom, eq_minus_throw) {
  // x - xz = ?
  CMonom a(1, 1, 0, 0);
  CMonom b(1, 1, 0, 1);

  EXPECT_THROW(a -= b, std::logic_error);

  // y^2z - 2xyz = ?
  a = CMonom(1, 0, 2, 1);
  b = CMonom(2, 1, 1, 1);
  EXPECT_THROW(a -= b, std::logic_error);
}

TEST(CMonom, eq_mul) {
  // 2x * yz = 2xyz
  CMonom a = CMonom(2, 1, 0, 0);
  CMonom b = CMonom(1, 0, 1, 1);
  a *= b;

  ASSERT_EQ(a.get_coef(), 2);
  ASSERT_EQ(a.get_p1(), 1);
  ASSERT_EQ(a.get_p2(), 1);
  ASSERT_EQ(a.get_p3(), 1);

  // 2x * 3x^2yz^5 = 6x^3yz^5
  a = CMonom(2, 1, 0, 0);
  b = CMonom(3, 2, 1, 5);
  a *= b;

  ASSERT_EQ(a.get_coef(), 6);
  ASSERT_EQ(a.get_p1(), 3);
  ASSERT_EQ(a.get_p2(), 1);
  ASSERT_EQ(a.get_p3(), 5);
}

TEST(CMonom, eq_div) {
  // 2xyz / yz = 2x
  CMonom a = CMonom(2, 1, 1, 1);
  CMonom b = CMonom(1, 0, 1, 1);
  a /= b;

  ASSERT_EQ(a.get_coef(), 2);
  ASSERT_EQ(a.get_p1(), 1);
  ASSERT_EQ(a.get_p2(), 0);
  ASSERT_EQ(a.get_p3(), 0);

  // 6x^3yz^5 / 3x^2yz^5 = 2x
  a = CMonom(6, 3, 1, 5);
  b = CMonom(3, 2, 1, 5);
  a /= b;

  ASSERT_EQ(a.get_coef(), 2);
  ASSERT_EQ(a.get_p1(), 1);
  ASSERT_EQ(a.get_p2(), 0);
  ASSERT_EQ(a.get_p3(), 0);
}
