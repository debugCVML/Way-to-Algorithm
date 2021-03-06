// MIT License
// Copyright 2017 zhaochenyou16@gmail.com

#include "ACAutomation.hpp"
#include <iostream>
#include <cassert>
using namespace std;

#define TEST_MAX 1024

struct Test {
  string text;
  vector<string> str;
  unordered_map<string, vector<int>> pos;
} tests[] = {
  {
    "asdfasdfasdfasdf",
    { "asdf", },
    {
      { "asdf", { 0, 4, 8, 12 } },
    },
  },
  {
    "asdfasdfasdfasdf",
    { "asdf", },
    {
      { "asdf", { 0, 4, 8, 12 } },
    },
  }
};

int main(void) {
  for (int i = 0; i < sizeof(tests) / sizeof(Test); i++) {
    Test &t = tests[i];

    ACAutomation *ac = ACAutomationNew(t.str);
    assert(ACAutomationMatch(ac, t.text) == t.pos);
    ACAutomationFree(ac);
  }
  return 0;
}

