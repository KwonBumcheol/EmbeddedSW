import pybind11_example
if __name__ == "__main__":
    x = 0
    y = 1.5708
    n = 100000
    answer = pybind11_example.cpp_function(x, y, n)
    print(f"    In Python: return val {answer:.5f}")