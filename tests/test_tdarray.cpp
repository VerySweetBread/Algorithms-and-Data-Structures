// Copyright 2024 Gleb Zaharov

#include <gtest.h>
#include "../lib_tdarray/tdarray.h"

TEST(TestTDArray, push_back) {
  TArchive<int> archive;
  archive.push_back(5);
  archive.push_back(10);
  archive.push_back(15);

  ASSERT_EQ(5, archive.get(0));
  ASSERT_EQ(10, archive.get(1));
  ASSERT_EQ(15, archive.get(2));
  ASSERT_EQ(3, archive.len());
}

TEST(TestTDArray, push_front) {
  TArchive<int> archive;
  archive.push_front(5);
  archive.push_front(10);
  archive.push_front(15);

  ASSERT_EQ(5, archive.get(2));
  ASSERT_EQ(10, archive.get(1));
  ASSERT_EQ(15, archive.get(0));
  ASSERT_EQ(3, archive.len());
}

TEST(TestTDArray, pop_back) {
  int array[2] = {5, 10};
  TArchive<int> archive(array, 2);
  ASSERT_EQ(10, archive.pop_back());
  ASSERT_EQ(5, archive.pop_back());
  ASSERT_EQ(0, archive.len());
  EXPECT_THROW(archive.pop_back(), std::logic_error);
}

TEST(TestTDArray, pop_front) {
  int array[2] = {5, 10};
  TArchive<int> archive(array, 2);
  ASSERT_EQ(5, archive.pop_front());
  ASSERT_EQ(10, archive.pop_front());
  ASSERT_EQ(0, archive.len());
  EXPECT_THROW(archive.pop_front(), std::logic_error);
}

TEST(TestTDArray, insert) {
  int array[3] = {3, 4, 5};
  int init_array[3] = {1, 2, 6};
  TArchive<int> archive(init_array, 3);

  archive.insert(array, 3, 2);

  ASSERT_EQ(6, archive.len());
  for (int i = 0; i < 6; i++)
    ASSERT_EQ(i+1, archive.get(i));

  archive.insert(0, 0);

  ASSERT_EQ(7, archive.len());
  for (int i = 0; i < 6; i++)
    ASSERT_EQ(i, archive.get(i));
}

TEST(TestTDArray, count_value) {
  int array[10] = {1, 2, 3, 1, 2, 0, 2, 5, 7, 2};
  TArchive<int> archive(array, 10);
  ASSERT_EQ(4, archive.count_value(2));
}

TEST(TestTDArray, overflow) {
  TArchive<int> archive;
  for (int i = 0; i < 30; i++)
    archive.push_back(i);
  for (int i = 0; i < 30; i++)
    ASSERT_EQ(i, archive.get(i));
  ASSERT_EQ(30, archive.len());
}

TEST(TestTDArray, overoverflow) {
  TArchive<int> archive;
  for (int i = 0; i < MAX_CAPACITY; i++)
    archive.push_back(i);
  EXPECT_THROW(archive.push_back(1), std::logic_error);
}

TEST(TestTDArray, clear) {
  TArchive<int> archive;
  archive.push_back(1);
  for (int i = 0; i < 30; i++)
    archive.push_back(0);

  archive.clear();
  ASSERT_EQ(0, archive.len());

  archive.push_front(2);
  ASSERT_EQ(2, archive.get(0));
}

TEST(TestTDArray, remove_all) {
  TArchive<int> archive;
  archive.push_back(1);
  for (int i = 0; i < 30; i++)
    archive.push_back(0);
  archive.push_back(2);

  archive.remove_all(0);
  ASSERT_EQ(2, archive.len());

  ASSERT_EQ(1, archive.get(0));
  ASSERT_EQ(2, archive.get(1));
}
