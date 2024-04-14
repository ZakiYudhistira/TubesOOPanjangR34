#ifndef EXCEPTION_FIELD
#define EXCEPTION_FIELD

#include <exception>

class FFException : public std :: exception {
    public:
    virtual char const * what() const noexcept;
};

class NoHarvestObject : public FFException {
    public:
    virtual char const * what() const noexcept;
};

class HarvestOutOfBounds : public FFException {
    public:
    virtual char const * what() const noexcept;
};

class HarvestCountInvalid : public FFException {
    public:
    virtual char const * what() const noexcept;
};

class InvalidObject : public FFException {
    public:
    virtual char const * what() const noexcept;
};

class InsufficientSpace : public FFException {
    public:
    virtual char const * what() const noexcept;
};
#endif