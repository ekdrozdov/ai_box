#pragma once
#include <iostream>
#include "energy.h"
#include "Resource.h"
#include "node.h"

class Tester
{
  public:
    static bool run_all_tests();
    static void include_test();

  private:
    static bool make_failure(const std::string &message);
};