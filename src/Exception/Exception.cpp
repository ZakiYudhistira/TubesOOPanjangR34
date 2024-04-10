#include "Exception.hpp"

char const * Exception::what() const noexcept {
    return "Default Exception";
}

char const * ExceptionFileNotFound::what() const noexcept {
    return "File not found!";
}

char const * GuldenNotEnough::what() const noexcept { 
    return "Gulden anda tidak cukup" ; 
}

char const * TypeNotFound::what() const noexcept { 
    return "There is no such type, only peternak or petani" ; 
}

char const * InvalidType::what() const noexcept { 
    return "Invalid Input Type" ; 
}

