#include <pybind11/pybind11.h>
#include "cpp_intgr.hpp"
PYBIND11_MODULE(pybind11_example, m) {
    m.doc() = "pybind11 example plugin";
    m.def("cpp_function", &integrate,
          "A function that calculates integration");
}