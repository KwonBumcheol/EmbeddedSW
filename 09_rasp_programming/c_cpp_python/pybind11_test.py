# pybind11 활용
import pybind11_example
if __name__ == "__main__":
    x = 0
    y = 1.5708
    n = 100000
    # cpp_intgr_wrapper.cpp - m.def("cpp_function", &integrate, "A function that calculates integration");
    # 기존 함수 이름 double integrate (double a, double b, int n) -> cpp_function 변경된 걸 호출해서 사용
    answer = pybind11_example.cpp_function(x, y, n) 
    print(f"    In Python: return val {answer:.5f}")