import ctypes
import pathlib

if __name__ == "__main__":
    # libname = pathlib.Path().absolute() / "c_intgr.so" # 1번 c - 현재 python 파일이 실행되는 폴더에서 c_intgr.so 파일 경로를 만듦
    libname = pathlib.Path().absolute() / "cpp_intgr.so" # 2번 c++
    clib = ctypes.CDLL(libname) # 라이브러리 로드 -> python
    clib.integrate.restype = ctypes.c_double # return type 전달(double)
    answer = clib.integrate( # c/c++ 함수 호출
        ctypes.c_double(0), # 매개변수 wrapping
        ctypes.c_double(1.5708),
        100000
    )
    print(f"    In Python: return val {answer:.5f}")