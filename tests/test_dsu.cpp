// Copyright 2024 Gleb Zaharov

#include <gtest.h>
#include "../lib_dsu/dsu.h"

TEST(DSU, make_set) {
  DSU dsu;
  dsu.make_set(1);

  EXPECT_NO_THROW (dsu.make_set(2));
  EXPECT_THROW(dsu.make_set(1), std::invalid_argument);
}

TEST(DSU, find) {
  DSU dsu;
  dsu.make_set(1);
  dsu.make_set(2);

  ASSERT_EQ(1, dsu.find(1));
  ASSERT_EQ(2, dsu.find(2));
  EXPECT_THROW(dsu.find(20), std::invalid_argument);
}
