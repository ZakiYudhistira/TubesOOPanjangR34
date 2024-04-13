#ifndef EXCEPTION_FIELD
#define EXCEPTION_FIELD

#include <exception>

class FieldException : public std :: exception {
    public:
    virtual char const * what() const noexcept;
};

class NoHarvestObject : public FieldException {
    public:
    virtual char const * what() const noexcept;
};

#endif