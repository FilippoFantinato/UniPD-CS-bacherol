#ifndef MOVEEXCEPTION_H
#define MOVEEXCEPTION_H

#include <stdexcept>
#include <string>

class MoveException : public std::runtime_error
{
private:
	u_int x, y;

public:
	explicit MoveException(u_int x, u_int y);
};

#endif // MOVEEXCEPTION_H
