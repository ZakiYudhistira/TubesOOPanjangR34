#include <iostream>
#include "FFException.hpp"
using namespace std;

char const * FFException :: what() const noexcept{
    return "Farm / Field Exception";
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

char const * InsufficientSpace :: what() const noexcept{
    return "Insufficient inventory space";
}

char const * NotHarvestAble :: what() const noexcept{
    retutn "Not harvestable";
}