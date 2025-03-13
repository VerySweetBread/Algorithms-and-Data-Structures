// Copyright 2024 Gleb Zaharov

#include <gtest.h>
#include "../lib_tlist/tlist.h"

TEST(TList, add_front) {
  TList<int> list;
  list.add_front(5);
  list.add_front(10);

  ASSERT_EQ(5, list.get(1));
  ASSERT_EQ(10, list.get(0));
  ASSERT_EQ(2, list.get_len());
}

TEST(TList, add_back) {
  TList<int> list;
  list.add_back(5);
  list.add_back(10);

  ASSERT_EQ(5, list.get(0));
  ASSERT_EQ(10, list.get(1));
  ASSERT_EQ(2, list.get_len());
}
