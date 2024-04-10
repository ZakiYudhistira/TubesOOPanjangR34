#ifndef EXCEPTION_CUSTOM
#define EXCEPTION_CUSTOM

#include <exception>

class Exception: public std::exception {
    public:
    virtual char const * what() const noexcept;
};

class ExceptionFileNotFound: public Exception {
    public:
    char const * what() const noexcept override;
};

class GuldenNotEnough: public Exception {
    public:
    char const * what() const noexcept override;
};

class TypeNotFound: public Exception {
    public:
    char const * what() const noexcept override;
};

class InvalidType: public Exception {
    public:
    char const * what() const noexcept override;
};

#endif


