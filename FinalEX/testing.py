import pybind11_example

if __name__ == "__main__":
    n = 20

    pybind11_example.print_primes(n)
    pybind11_example.print_multiples_of_three(n)
    pybind11_example.print_odd_even(n)