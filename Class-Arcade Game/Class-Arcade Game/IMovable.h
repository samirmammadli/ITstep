
#include "Structures.h"
class IMovable
{
protected:
	Direction direction;
public:
	virtual void move(Direction dir) = 0 {};
};
