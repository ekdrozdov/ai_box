#include "tester.h"

bool make_failure(const std::string &message)
{
    std::cout << message << std::endl;
    return false;
}

// Place unit tests here and include them in run_all_tests function.
// bool test_Resource()
// {
//     {
//         Resource ec;
//         if (ec.is_allowed("water"))
//         {
//             return make_failure("Resource.is_allowed unallowed energy error");
//         }
//         ec.allow_state("water");
//         if (!ec.is_allowed("water"))
//         {
//             return make_failure("Resource.is_allowed allowed energy error");
//         }
//     }

//     {
//         Resource ec;
//         ec.allow_state("water");
//         if (ec.add("water", 10.) != 10.)
//         {
//             return make_failure("Resource.add capacity limit error");
//         }
//         ec.set
//     }

//     return true;
// }

// bool test_energy()
// {
//     {
//         Energy_state es;
//         if (es.state != "water")
//         {
//             return make_failure("Energy_state() shold set state = water");
//         }
//     }

//     {
//         Energy_state es("earth");
//         if (es.state != "earth")
//         {
//             return make_failure("Energy_state(\"earth\") shold set state = earth");
//         }
//     }

//     {
//         Energy e;
//         if (e.get_count() != 0. || e.get_state().state != "water")
//         {
//             return make_failure("Energy() should set count = 0, state = water");
//         }
//     }

//     {
//         Energy e = Energy(10.1);
//         if (e.get_count() != 10.1 || e.get_state().state != "water")
//         {
//             return make_failure("Energy(10.1) should set count = 10.1, state = water");
//         }
//     }

//     {
//         Energy e = Energy(10.1, Energy_state("earth"));
//         if (e.get_count() != 10.1 || e.get_state().state != "earth")
//         {
//             return make_failure("Energy(10.1) should set count = 10.1, state = water");
//         }
//     }

//     {
//         Energy e = Energy(10.1, Energy_state("earth"));
//         if (e.set_count(5.5) != 0. || e.get_count() != 15.6 || e.get_state().state != "earth")
//         {
//             return make_failure("Energy.set_count common error");
//         }

//         if (e.set_count(0.) != 0. || e.get_count() != 0. || e.get_state().state != "earth")
//         {
//             return make_failure("Energy.set_count zero error");
//         }

//         if (e.set_count(1.) != 1. || e.get_state().state != "earth")
//         {
//             return make_failure("Energy.set_count negative error");
//         }
//     }

//     {
//         Energy e = Energy(10.1, Energy_state("earth"));
//         e.inc(5.5);
//         if (e.get_count() != 15.6 || e.get_state().state != "earth")
//         {
//             return make_failure("Energy.inc common error");
//         }
//         e.set_count(10.);
//         if (e.inc(-100.) != 90 || e.get_count() != 0.0 || e.get_state().state != "earth")
//         {
//             return make_failure("Energy.inc negative error");
//         }
//     }

//     return true;
// }

bool Tester::run_all_tests()
{
    // // TODO: setup unit-test framework
    // bool result = true;
    // // if (!test_energy())
    // //     result = false;

    // if (!test_Resource())
    //     result = false;

    // return result;
    return true;
}