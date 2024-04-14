#include "Exception.hpp"

char const *Exception::what() const noexcept
{
    return "Default Exception";
}

char const *ExceptionFileNotFound::what() const noexcept
{
    return "File not found!";
}

char const *GuldenNotEnough::what() const noexcept
{
    return "Gulden anda tidak cukup";
}

char const *TypeNotFound::what() const noexcept
{
    return "There is no such type, only peternak or petani";
}

char const *InvalidType::what() const noexcept
{
    return "Invalid Input Type";
}

char const *IsNotFood::what() const noexcept
{
    return "Food not found!";
}

char const * InvalidName::what() const noexcept {
    return "Name must be unique!" ;
}
 

char const *invalidCommand::what() const noexcept
{
    return "Invalid command!";
}

char const *RecipeNotFound::what() const noexcept {
    return "You don't have that recipe!" ;
}

char const *MaterialNotEnough::what() const noexcept {
    return "You don't have enough material" ;
}

char const *ItemNotFound::what() const noexcept {
    return "Invalid item!" ;
}