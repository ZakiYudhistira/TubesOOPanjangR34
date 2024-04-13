#include <iostream>
#include "FieldException.hpp"
using namespace std;

char const * FieldException :: what() const noexcept{
    return "Field Exception";
}

char const * NoHarvestObject :: what() const noexcept{
    return "No object available for harvest";
}

char const * HarvestOutOfBounds :: what() const noexcept{
    return "Index out of bounds";
}

char const * HarvestCountInvalid :: what() const noexcept{
    return "Harvest count invalid";
}

char const * InvalidObject :: what() const noexcept{
    return "Wrong object";
}