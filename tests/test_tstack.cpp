// Copyright 2024 Gleb Zaharov

#include <gtest.h>
#include "../lib_tstack/tstack.h"

TEST(TStack, push) {
  TStack<int> stack(10);

  for (int i = 0; i < 10; i++)
    stack.push(i);

  EXPECT_THROW(stack.push(10), std::logic_error);
}

TEST(TStack, pop) {
  TStack<int> stack(10);

  for (int i = 0; i < 10; i++)
    stack.push(i);

  for (int i = 9; i >= 0; i--)
    ASSERT_EQ(i, stack.pop());

  EXPECT_THROW(stack.pop(), std::logic_error);
}

TEST(TStack, is_empty) {
  TStack<int> stack(10);
  ASSERT_EQ(true, stack.is_empty());

  for (int i = 0; i < 10; i++) {
    stack.push(i);
    ASSERT_EQ(false, stack.is_empty());
  }

  for (int i = 0; i < 10; i++)
    stack.pop();

  ASSERT_EQ(true, stack.is_empty());
}
