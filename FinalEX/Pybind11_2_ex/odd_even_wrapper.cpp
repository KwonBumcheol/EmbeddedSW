#include <pybind11/pybind11.h>
#include "odd_even.hpp"

PYBIND11_MODULE(odd_even_module, m) {
    m.doc() = "odd even pybind11 module";

    m.def("print_odd_even", &print_odd_even,
          "Print whether n is odd or even");
}