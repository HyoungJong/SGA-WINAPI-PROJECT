#include "Game.h"
#include "collision.h"
#include "player.h"
#include "block.h"
#include "mob.h"



collision::collision()
{
}


collision::~collision()
{
}

void collision::collsioninit()
{
	collisionOccur = false;
	collisionType = 0;
	collisionKeepTime = 0;
}

void collision::Collisions(player * Cplayer, block * Cblock, mob * Cmob)
{
	// 플레이어와 바닥블럭 간의 충돌
	RECT temp;
	for (int i = 0; i < MAX_GROUNDBLOCKNUM; i++)
	{
		if (IntersectRect(&temp, &Cplayer->marioRect(), &Cblock->groundblockRect(i)))
		{
			// 블럭의 중심점
			blockCenter = { (Cblock->groundblockRect(i).left + Cblock->groundblockRect(i).right) / 2,
				(Cblock->groundblockRect(i).top + Cblock->groundblockRect(i).bottom) / 2 };

			// 충돌한 면적의 중심점
			tempCenter = { (temp.left + temp.right) / 2,
				(temp.top + temp.bottom) / 2 };


			// 플레이어가 위에서 부딪힐 때
			if (tempCenter.y < blockCenter.y &&
				Cplayer->marioRect().bottom < Cblock->groundblockRect(i).top + 30 &&
				Cplayer->getmarioJumpPower() < 0)
			{
				Cplayer->setmarioY(Cblock->groundblockRect(i).top - 63);
				Cplayer->setmarioGravity(0);
				Cplayer->setmarioJumpPower(0);
				Cplayer->setmarioJump(false);
			}

			// 플레이어가 아래에서 부딪힐 때
			if (tempCenter.y > blockCenter.y &&
				Cplayer->marioRect().top + 10 > Cblock->groundblockRect(i).bottom)
			{
				Cplayer->setmarioY(Cblock->groundblockRect(i).bottom - 5);
				Cplayer->setmarioJumpPower(0);
			}

			// 플레이어가 왼쪽에서 부딪힐 때
			if (tempCenter.x < blockCenter.x &&
				Cplayer->marioRect().right < Cblock->groundblockRect(i).left + 10)
				Cplayer->setmarioX(Cblock->groundblockRect(i).left - 50);

			// 플레이어가 오른쪽에서 부딪힐 때
			if (tempCenter.x > blockCenter.x &&
				Cplayer->marioRect().left + 10 > Cblock->groundblockRect(i).right)
				Cplayer->setmarioX(Cblock->groundblockRect(i).right - 8);
		}
	}


	// 플레이어와 블럭 간의 충돌
	for (int i = 0; i < 1; i++)
	{
		if (IntersectRect(&temp, &Cplayer->marioRect(), &Cblock->blockRect(i)))
		{
			// 블럭의 중심점
			blockCenter = { (Cblock->blockRect(i).left + Cblock->blockRect(i).right) / 2,
				(Cblock->blockRect(i).top + Cblock->blockRect(i).bottom) / 2 };

			// 충돌한 면적의 중심점
			tempCenter = { (temp.left + temp.right) / 2,
				(temp.top + temp.bottom) / 2 };


			// 플레이어가 위에서 부딪힐 때
			if (tempCenter.y < blockCenter.y &&
				Cplayer->marioRect().bottom < Cblock->blockRect(i).top + 10 &&
				Cplayer->getmarioJumpPower() < 0)
			{
				Cplayer->setmarioY(Cblock->blockRect(i).top - 63);
				Cplayer->setmarioGravity(0);
				//Cplayer->setmarioJumpPower(0);
				Cplayer->setmarioJump(false);
			}

			// 플레이어가 아래에서 부딪힐 때
			if (tempCenter.y > blockCenter.y &&
				Cplayer->marioRect().top + 10 > Cblock->blockRect(i).bottom)
			{
				Cplayer->setmarioY(Cblock->blockRect(i).bottom - 5);
				Cplayer->setmarioJumpPower(0);
			}

			// 플레이어가 왼쪽에서 부딪힐 때
			if (tempCenter.x < blockCenter.x &&
				Cplayer->marioRect().right < Cblock->blockRect(i).left + 10)
				Cplayer->setmarioX(Cblock->blockRect(i).left - 50);

			// 플레이어가 오른쪽에서 부딪힐 때
			if (tempCenter.x > blockCenter.x &&
				Cplayer->marioRect().left + 10 > Cblock->blockRect(i).right)
				Cplayer->setmarioX(Cblock->blockRect(i).right - 8);
		}
	}
	

	// 몹과 바닥블럭 간의 충돌
	if (Cmob->getmushroomisDead() == false)
	{
		for (int i = 0; i < MAX_GROUNDBLOCKNUM; i++)
		{
			if (IntersectRect(&temp, &Cmob->mushroomRect(), &Cblock->groundblockRect(i)))
			{
				// 블럭의 중심점
				blockCenter = { (Cblock->groundblockRect(i).left + Cblock->groundblockRect(i).right) / 2,
					(Cblock->groundblockRect(i).top + Cblock->groundblockRect(i).bottom) / 2 };

				// 충돌한 면적의 중심점
				tempCenter = { (temp.left + temp.right) / 2,
					(temp.top + temp.bottom) / 2 };


				// 플레이어가 위에서 부딪힐 때
				if (tempCenter.y < blockCenter.y &&
					Cmob->mushroomRect().bottom < Cblock->groundblockRect(i).top + 30)
				{
					Cmob->setmushroomY(Cblock->groundblockRect(i).top - 72);
					Cmob->setmobGravity(0);
				}
			}
		}
	}


	// 플레이어와 몹과 충돌

	// 버섯일 때
	if (Cmob->getmushroomisDead() == false)
	{
		if (IntersectRect(&temp, &Cplayer->marioRect(), &Cmob->mushroomRect()))
		{
			// 블럭의 중심점
			blockCenter = { (Cmob->mushroomRect().left + Cmob->mushroomRect().right) / 2,
				(Cmob->mushroomRect().top + Cmob->mushroomRect().bottom) / 2 };

			// 충돌한 면적의 중심점
			tempCenter = { (temp.left + temp.right) / 2,
				(temp.top + temp.bottom) / 2 };


			// 플레이어가 위에서 부딪힐 때
			if (tempCenter.y < blockCenter.y &&
				Cplayer->marioRect().bottom < Cmob->mushroomRect().top + 10 &&
				abs(((Cplayer->marioRect().left + Cplayer->marioRect().right) / 2) - blockCenter.x) < 20)
			{
				Cplayer->setmarioY(Cmob->mushroomRect().top - 63);
				Cplayer->setmarioJumpPower(9.0f);
				Cplayer->setmarioJump(false);
				Cmob->setmushroomisDead(true);
			}

			// 플레이어가 아래에서 부딪힐 때
			if (tempCenter.y > blockCenter.y &&
				Cplayer->marioRect().top + 10 > Cmob->mushroomRect().bottom)
			{
				Cplayer->setmarioY(Cmob->mushroomRect().bottom - 5);
				Cplayer->setmarioJumpPower(0);
			}

			// 플레이어가 왼쪽에서 부딪힐 때
			if (tempCenter.x < blockCenter.x &&
				Cplayer->marioRect().right < Cmob->mushroomRect().left + 10)
			{
				Cplayer->setmarioX(Cmob->mushroomRect().left - 50);
				collisionOccur = true;
				collisionType = LEFT;
			}
				

			// 플레이어가 오른쪽에서 부딪힐 때
			if (tempCenter.x > blockCenter.x &&
				Cplayer->marioRect().left + 10 > Cmob->mushroomRect().right)
			{
				Cplayer->setmarioX(Cmob->mushroomRect().right - 8);
				collisionOccur = true;
				collisionType = LEFT;
			}
				
		}
	}

	keepCollision(Cplayer, Cblock, Cmob);
}

void collision::keepCollision(player * Cplayer, block * Cblock, mob * Cmob)
{
	if (collisionOccur == true)
	{
		if (collisionType = LEFT)
		{
			collisionKeepTime++;

			Cplayer->setmarioX(Cplayer->getmarioX() - 7);
			Cplayer->setmarioJumpPower(2.0f);

			if (collisionKeepTime == 20)
			{
				collisionKeepTime = 0;
				collisionOccur = false;
			}
				
		}
			
		if (collisionType = RIGHT)
		{
			collisionKeepTime++;

			Cplayer->setmarioX(Cplayer->getmarioX() + 7);
			Cplayer->setmarioJumpPower(2.0f);

			if (collisionKeepTime == 20)
			{
				collisionKeepTime = 0;
				collisionOccur = false;
			}
		}
			
	}
}
