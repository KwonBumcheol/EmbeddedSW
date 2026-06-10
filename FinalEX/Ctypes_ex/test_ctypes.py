import ctypes
import pathlib

if __name__ == "__main__":
    libname = pathlib.Path().absolute() / "libcpp_intgr.so"

    clib = ctypes.CDLL(str(libname))

    clib.print_primes.argtypes = [ctypes.c_int]
    clib.print_primes.restype = None

    # 3의 배수
    # clib.print_multiples_of_three.argtypes = [ctypes.c_int]
    # clib.print_multiples_of_three.restype = None

    clib.print_odd_even.argtypes = [ctypes.c_int]
    clib.print_odd_even.restype = None

    clib.print_primes(20)
    clib.print_multiples_of_three(20)
    clib.print_odd_even(7)
    clib.print_odd_even(8)