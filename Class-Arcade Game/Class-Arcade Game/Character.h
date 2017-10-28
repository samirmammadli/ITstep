#include "Trap.h"



class Character : public GameObject, public IAttacking, public IMovable
{
protected:
	int hp;
	State state;
public:
	virtual ~Character() = 0 {}
	virtual void attack(Character &target) override {};
	virtual void shoot(Character &target) override {};
	virtual void setHp(int hp) { this->hp = hp; }
	virtual void setState(State state) { this->state = state; }
	virtual void move(Direction dir) 
	{
		Position temp = position;
		if (dir == Direction::Up)  position.y--; 
		else if (dir == Direction::Down) position.y++;
		else if (dir == Direction::Left) position.x--;
		else if (dir == Direction::Right) position.x++; 

		if (Map::get().getCell(position.x, position.y) == MapCell::Wall)
			position = temp;
	}
};

