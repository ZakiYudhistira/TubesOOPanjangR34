#ifndef __EXCEPTION_CUSTOM__
#define __EXCEPTION_CUSOTM__

#include <exception>
using namespace std;

class Exception: std::exception {
    // ?
    public:
    virtual char const * what() const noexcept override {
        return "Normal Exception";
    }
};

class ExceptionFileNotFound: public Exception {
    public:
    char const * what() const noexcept override { 
        return "File not found!"; 
    }
};

class GuldenNotEnough: public Exception {
    public:
    char const * what() const noexcept override { 
        return "Gulden anda tidak cukup" ; 
    }
};

class TypeNotFound: public Exception {
    public:
    char const * what() const noexcept override { 
        return "There is no such type, only peternak or petani" ; 
    }
};
#endif


