import ctypes
import pathlib

if __name__ == "__main__":
    # libname = pathlib.Path().absolute() / "c_intgr.so" # 1번 c
    libname = pathlib.Path().absolute() / "cpp_intgr.so" # 2번 c++
    clib = ctypes.CDLL(libname) # 라이브러리 로드
    clib.integrate.restype = ctypes.c_double # return type 전달
    answer = clib.integrate( # c함수 호출
        ctypes.c_double(0), # 매개변수 wrapping
        ctypes.c_double(1.5708),
        100000
    )
    print(f"    In Python: return val {answer:.5f}")