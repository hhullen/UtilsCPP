#include <gtest/gtest.h>

#include "../lib/str_plus.h"

using hhullen::Str;
using hhullen::StrList;

TEST(StrPlus, Split_normal) {
  Str test_1("qwe r ty");

  StrList result;
  result = hhullen::StrPlus::Split(test_1, ' ');
  EXPECT_EQ(result[0], Str("qwe"));
  EXPECT_EQ(result[1], Str("r"));
  EXPECT_EQ(result[2], Str("ty"));
}

TEST(StrPlus, Split_many_spaces_between) {
  Str test_1("qwe       r       ty");

  StrList result;
  result = hhullen::StrPlus::Split(test_1, ' ');
  EXPECT_EQ(result[0], Str("qwe"));
  EXPECT_EQ(result[1], Str("r"));
  EXPECT_EQ(result[2], Str("ty"));
}

TEST(StrPlus, Split_many_spaces_at_all) {
  Str test_1("     qwe       r       ty    ");

  StrList result;
  result = hhullen::StrPlus::Split(test_1, ' ');
  EXPECT_EQ(result[0], Str("qwe"));
  EXPECT_EQ(result[1], Str("r"));
  EXPECT_EQ(result[2], Str("ty"));
}

TEST(StrPlus, MakeUpper) {
  Str test_1("  qwe  r  ty  ");
  Str test_2("  QWE  R  TY  ");

  hhullen::StrPlus::MakeUpper(test_1);
  EXPECT_EQ(test_1, Str("  QWE  R  TY  "));
  hhullen::StrPlus::MakeUpper(test_2);
  EXPECT_EQ(test_2, Str("  QWE  R  TY  "));
}

TEST(StrPlus, MakeLower) {
  Str test_1("  qwe  r  ty  ");
  Str test_2("  QWE  R  TY  ");

  hhullen::StrPlus::MakeLower(test_1);
  EXPECT_EQ(test_1, Str("  qwe  r  ty  "));
  hhullen::StrPlus::MakeLower(test_2);
  EXPECT_EQ(test_2, Str("  qwe  r  ty  "));
}

TEST(StrPlus, GetUpper) {
  Str test_1("  qwe  r  ty  ");
  Str test_2("  QWE  R  TY  ");

  Str result = hhullen::StrPlus::GetUpper(test_1);
  EXPECT_EQ(result, Str("  QWE  R  TY  "));
  result = hhullen::StrPlus::GetUpper(test_2);
  EXPECT_EQ(result, Str("  QWE  R  TY  "));
}

TEST(StrPlus, GetLower) {
  Str test_1("  qwe  r  ty  ");
  Str test_2("  QWE  R  TY  ");

  Str result = hhullen::StrPlus::GetLower(test_1);
  EXPECT_EQ(result, Str("  qwe  r  ty  "));
  result = hhullen::StrPlus::GetLower(test_2);
  EXPECT_EQ(result, Str("  qwe  r  ty  "));
}

TEST(StrPlus, IsUpper) {
  Str test_1("  qwe  r  ty  ");
  Str test_2("  QWE  R  TY  ");

  EXPECT_FALSE(hhullen::StrPlus::IsUpper(test_1));
  EXPECT_TRUE(hhullen::StrPlus::IsUpper(test_2));
}

TEST(StrPlus, IsLower) {
  Str test_1("  qwe  r  ty  ");
  Str test_2("  QWE  R  TY  ");

  EXPECT_TRUE(hhullen::StrPlus::IsLower(test_1));
  EXPECT_FALSE(hhullen::StrPlus::IsLower(test_2));
}

TEST(StrPlus, Validate_int_false) {
  Str test_1("-123z4e+10as");

  EXPECT_FALSE(hhullen::StrPlus::IsValid(test_1, hhullen::StrPlus::Type::Int));
}

TEST(StrPlus, IsValid_int_true) {
  Str test_1("-1234e+10");

  EXPECT_TRUE(hhullen::StrPlus::IsValid(test_1, hhullen::StrPlus::Type::Int));
}

TEST(StrPlus, IsValid_float_false) {
  Str test_1("-123z4e+10as");

  EXPECT_FALSE(
      hhullen::StrPlus::IsValid(test_1, hhullen::StrPlus::Type::Float));
}

TEST(StrPlus, IsValid_float_true) {
  Str test_1("-12.34e+10");

  EXPECT_TRUE(hhullen::StrPlus::IsValid(test_1, hhullen::StrPlus::Type::Float));
}

TEST(StrPlus, IsValid_uint_false) {
  Str test_1("-123z4e+10as");

  EXPECT_FALSE(hhullen::StrPlus::IsValid(test_1, hhullen::StrPlus::Type::UInt));
}

TEST(StrPlus, IsValid_uint_true) {
  Str test_1("1234e+10");

  EXPECT_TRUE(hhullen::StrPlus::IsValid(test_1, hhullen::StrPlus::Type::UInt));
}
