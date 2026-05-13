import invoke
invoke.run(
    "g++ -O3 -Wall -Werror -shared -std=c++11 -fPIC "
    "`python3 -m pybind11 --includes` "
    "-I /usr/include/python3.13 -I . "
    "{0} "
    "-o {1}`python3.13-config --extension-suffix` "
    "-L. -lcpp_intgr -Wl,-rpath,."
    .format("cpp_intgr_wrapper.cpp", "pybind11_example"))