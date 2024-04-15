#ifndef EXCEPTION_CUSTOM
#define EXCEPTION_CUSTOM

#include <exception>
using namespace std;


class ExceptionFileNotFound : public exception {
public:
    const char *what() const noexcept override;
};

class GuldenNotEnough : public exception {
public:
    const char *what() const noexcept override;
};

class InventoryFullException: public exception{
public:
    const char *what() const noexcept override;
};

class QuantityNotEnoughException: public exception{
public:
    const char *what() const noexcept override;
};

class InventoryNotAvailableException: public exception{
    const char *what() const noexcept override;
};

class TypeNotFound : public exception {
public:
    const char *what() const noexcept override;
};

class InvalidType : public exception {
public:
    const char *what() const noexcept override;
};

class IsNotFood : public exception
{
public:
    const char *what() const noexcept override;
};

class invalidCommand : public exception
{
public:
    const char *what() const noexcept override;
};

class InvalidName: public exception {
    public :
    const char * what() const noexcept override;
};

class RecipeNotFound: public exception {
    public :
    const char * what() const noexcept override;
};

class MaterialNotEnough: public exception { // ini ga kepake coba tanya Vanson
    public :
    const char * what() const noexcept override;
};

class ItemNotFound: public exception {
    public :
    char const * what() const noexcept override;
};

class AnimalNotFound: public exception {
    public :
    char const * what() const noexcept override;
};

class PlantNotFound: public exception {
    public :
    char const * what() const noexcept override;
};

class NoFoodFound: public exception {
    public :
    char const * what() const noexcept override;
};

#endif
