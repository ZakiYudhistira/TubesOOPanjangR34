#include <iostream>
#include "FieldException.hpp"
using namespace std;

char const * FieldException :: what() const noexcept{
    return "Field Exception";
}

char const * NoHarvestObject :: what() const noexcept{
    return "No object available for harvest";
}
