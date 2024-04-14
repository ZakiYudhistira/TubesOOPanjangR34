#ifndef EXCEPTION_CUSTOM
#define EXCEPTION_CUSTOM

#include <exception>

class Exception : public std::exception
{
public:
    virtual char const *what() const noexcept;
};

class ExceptionFileNotFound : public Exception
{
public:
    char const *what() const noexcept override;
};

class GuldenNotEnough : public Exception
{
public:
    char const *what() const noexcept override;
};

class TypeNotFound : public Exception
{
public:
    char const *what() const noexcept override;
};

class InvalidType : public Exception
{
public:
    char const *what() const noexcept override;
};

class IsNotFood : public Exception
{
public:
    char const *what() const noexcept override;
};

class invalidCommand : public Exception
{
public:
    char const *what() const noexcept override;
};

class InvalidName: public Exception {
    public :
    char const * what() const noexcept override;
};

class RecipeNotFound: public Exception {
    public :
    char const * what() const noexcept override;
};

class MaterialNotEnough: public Exception { // ini ga kepake coba tanya Vanson
    public :
    char const * what() const noexcept override;
};

class ItemNotFound: public Exception {
    public :
    char const * what() const noexcept override;
};

class AnimalNotFound: public Exception {
    public :
    char const * what() const noexcept override;
};

class NoFoodFound: public Exception {
    public :
    char const * what() const noexcept override;
};

#endif
