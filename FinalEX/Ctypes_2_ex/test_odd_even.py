import ctypes
import pathlib

if __name__ == "__main__":
    libname = pathlib.Path().absolute() / "libodd_even.so"

    clib = ctypes.CDLL(str(libname))

    clib.print_odd_even.argtypes = [ctypes.c_int]
    clib.print_odd_even.restype = None

    clib.print_odd_even(7)
    clib.print_odd_even(8)