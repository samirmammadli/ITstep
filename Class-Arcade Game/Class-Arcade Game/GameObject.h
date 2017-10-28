
#include "IInteractive.h"

class GameObject
{
protected:
	Position position;
public:
	virtual ~GameObject() = 0 {}
	virtual void setPosition(int x, int y) { this->position.x = x; this->position.y = y; }
	virtual Position getPosition() { return this->position; }
};
