#include <iostream>
#include "MatrixException.hpp"
using namespace std;

char const * MatrixInvalid :: what() const noexcept{
    return "Matrix invalid";
}

char const * MatrixException :: what() const noexcept{
    return "Matrix Exception";
}

char const * IndexOutOfRange :: what() const noexcept{
    return "Index out of range";
}

char const * ElementNotFound :: what() const noexcept{
    return "Element not found";
}

char const * FilledSpace :: what() const noexcept{
    return "Block filled";
}

char const * EmptySpace :: what() const noexcept{
    return "Block empty";
}

char const * MatrixFull :: what() const noexcept{
    return "Matrix full";
}