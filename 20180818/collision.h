#pragma once

#define ABC 10
class player;
class block;
class mob;

class collision
{
private:
	POINT	blockCenter;
	POINT	tempCenter;

	bool	collisionOccur;
	int		collisionType;
	int		collisionKeepTime;
	


public:
	collision();
	~collision();

	void	collsioninit();
	void	Collisions(player* Cplayer, block* Cblock, mob* Cmob);

	void	keepCollision(player* Cplayer, block* Cblock, mob* Cmob);
};

