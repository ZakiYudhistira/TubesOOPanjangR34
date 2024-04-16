#include "Exception.hpp"

char const *ExceptionFileNotFound::what() const noexcept
{
    return "File not found!";
}

char const *GuldenNotEnough::what() const noexcept
{
    return "Gulden anda tidak cukup";
}

char const *InventoryFullException::what() const noexcept
{
    return "Inventory FULL!";
}

char const *QuantityNotEnoughException::what() const noexcept
{
    return "Quantity Not Enough!";
}

char const *InventoryNotAvailableException::what() const noexcept
{
    return "Inventory Error";
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

char const *InvalidName::what() const noexcept
{
    return "Name must be unique!";
}

char const *invalidCommand::what() const noexcept
{
    return "Invalid command!";
}

char const *RecipeNotFound::what() const noexcept
{
    return "You don't have that recipe!";
}

char const *MaterialNotEnough::what() const noexcept
{
    return "You don't have enough material";
}

char const *ItemNotFound::what() const noexcept
{
    return "Invalid item!";
}

char const *AnimalNotFound::what() const noexcept
{
    return "There is no animal!";
}

char const *PlantNotFound::what() const noexcept
{
    return "There is no plant!";
}

char const *NoFoodFound::what() const noexcept
{
    return "You have no food for this!";
}

char const *ProhibitedSellingException::what() const noexcept
{
    return "Anda tidak dapat menjual bangunan!";
}

char const *ProhibitedBuyingException::what() const noexcept
{
    return "Anda tidak dapat membeli bangunan!";
}

char const *InvalidInput::what() const noexcept
{
    return "Invalid Input!";
}