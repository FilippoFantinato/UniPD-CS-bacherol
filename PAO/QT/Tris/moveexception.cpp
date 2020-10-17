#include "moveexception.h"

MoveException::MoveException(u_int x, u_int y) : std::runtime_error("Exception: The movement (" + std::to_string(x) + ", " + std::to_string(y) + ") cannot be done"), x(x), y(y)
{

}
