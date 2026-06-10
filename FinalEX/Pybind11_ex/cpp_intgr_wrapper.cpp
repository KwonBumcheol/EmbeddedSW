#include <pybind11/pybind11.h>
#include "cpp_intgr.hpp"

PYBIND11_MODULE(pybind11_example, m) {
    m.doc() = "pybind11 example plugin";

    m.def("print_primes", &print_primes,
          "Print prime numbers up to n");
// 3의 배수
//     m.def("print_multiples_of_three", &print_multiples_of_three,
//           "Print multiples of three up to n");

    m.def("print_odd_even", &print_odd_even,
          "Print whether n is odd or even");
}