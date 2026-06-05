#include <pybind11/pybind11.h>
#include "cpp_intgr.hpp"
PYBIND11_MODULE(pybind11_example, m) { // python 모듈명 = pybind11_example = .so 파일 이름도 맞춰야함 / m = py::module 오브젝트
    m.doc() = "pybind11 example plugin"; // python 모듈 설명문 = docstring
    m.def("cpp_function", &integrate,
          "A function that calculates integration"); // 파이썬에 사용될 함수 바인딩(파이썬 함수 이름, 함수주소, docstring)
}