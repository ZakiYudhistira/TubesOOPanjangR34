#ifndef EXCEPTION_MATRIX
#define EXCEPTION_MATRIX

#include <exception>

class MatrixException : public std :: exception {
    public:
    virtual char const * what() const noexcept;
};

class IndexOutOfRange : public MatrixException {
    public:
    virtual char const * what() const noexcept;
};

class ElementNotFound : public MatrixException {
    public:
    virtual char const * what() const noexcept;
};

class FilledSpace : public MatrixException {
    public:
    virtual char const * what() const noexcept;
};

class EmptySpace : public MatrixException {
    public:
    virtual char const * what() const noexcept;
};

#endif