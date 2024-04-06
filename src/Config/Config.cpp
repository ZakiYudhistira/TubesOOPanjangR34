#include "Config.hpp"

std::ostream& Config::showConfig(std::ostream& os){
    os << std::setw(2) << "id" << ' '
        << std::setw(10) << "code_name" << ' '
        << std::setw(15) << "object_name" << ' '
        << std::setw(5) << "price" << ' '
        << std::setw(19) << "weight_to_harvest" << '\n';
    return os;
}