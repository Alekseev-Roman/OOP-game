#ifndef MOVABLE_H
#define MOVABLE_H

class Movable{
public:
	virtual ~Movable() = default;
	virtual bool move(int pos_x, int pos_y) = 0;
};

#endif // MOVABLE_H
