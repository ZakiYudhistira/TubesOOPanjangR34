#include <iostream>
#include "MatrixException.hpp"
using namespace std;


char const * MatrixException :: what() const noexcept{
    return "Matrix Exception";
}

char const * IndexOutOfRange :: what() const noexcept{
    return "Index out of range";
}

char const * ElementNotFound :: what() const noexcept{
    return "Element not found";
}