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
	// �÷��̾�� �ٴں� ���� �浹
	RECT temp;
	for (int i = 0; i < MAX_GROUNDBLOCKNUM; i++)
	{
		if (IntersectRect(&temp, &Cplayer->marioRect(), &Cblock->groundblockRect(i)))
		{
			// ���� �߽���
			blockCenter = { (Cblock->groundblockRect(i).left + Cblock->groundblockRect(i).right) / 2,
				(Cblock->groundblockRect(i).top + Cblock->groundblockRect(i).bottom) / 2 };

			// �浹�� ������ �߽���
			tempCenter = { (temp.left + temp.right) / 2,
				(temp.top + temp.bottom) / 2 };


			if (i == 10)
			{
				// ���� ���������� �̵�
			}

			else
			{
				// �÷��̾ ������ �ε��� ��
				if (tempCenter.y < blockCenter.y &&
					Cplayer->marioRect().bottom < Cblock->groundblockRect(i).top + 30 &&
					Cplayer->getmarioJumpPower() < 0)
				{
					Cplayer->setmarioY(Cblock->groundblockRect(i).top - 63);
					Cplayer->setmarioGravity(0);
					Cplayer->setmarioJumpPower(0);
					Cplayer->setmarioJump(false);
				}

				// �÷��̾ �Ʒ����� �ε��� ��
				if (tempCenter.y > blockCenter.y &&
					Cplayer->marioRect().top + 10 > Cblock->groundblockRect(i).bottom)
				{
					Cplayer->setmarioY(Cblock->groundblockRect(i).bottom - 5);
					Cplayer->setmarioJumpPower(0);
				}

				// �÷��̾ ���ʿ��� �ε��� ��
				if (tempCenter.x < blockCenter.x &&
					Cplayer->marioRect().right < Cblock->groundblockRect(i).left + 10)
					Cplayer->setmarioX(Cblock->groundblockRect(i).left - 50);

				// �÷��̾ �����ʿ��� �ε��� ��
				if (tempCenter.x > blockCenter.x &&
					Cplayer->marioRect().left + 10 > Cblock->groundblockRect(i).right)
					Cplayer->setmarioX(Cblock->groundblockRect(i).right - 8);
			}			
		}
	}


	// �÷��̾�� �� ���� �浹
	for (int i = 0; i < MAX_CLOUDNUM + MAX_THREEBLOCKNUM + MAX_PORTALNUM + MAX_FALLINGBLOCKNUM; i++)
	{
		// ��Ż�� ��
		if (i == 7 || i == 8)
		{
			if (IntersectRect(&temp, &Cplayer->marioRect(), &Cblock->blockRect(i)))
			{
				if (KEYMANAGER->isOnceKeyDown(VK_UP))
				{
					Cplayer->setmarioX(2980);
					Cplayer->setmarioY(649);
				}
			}
		}
		// ��Ż �ƴ� ��
		else
		{
			if (IntersectRect(&temp, &Cplayer->marioRect(), &Cblock->blockRect(i)))
			{
				// ���� �߽���
				blockCenter = { (Cblock->blockRect(i).left + Cblock->blockRect(i).right) / 2,
					(Cblock->blockRect(i).top + Cblock->blockRect(i).bottom) / 2 };

				// �浹�� ������ �߽���
				tempCenter = { (temp.left + temp.right) / 2,
					(temp.top + temp.bottom) / 2 };


				// �÷��̾ ������ �ε��� ��
				if (tempCenter.y < blockCenter.y &&
					Cplayer->marioRect().bottom < Cblock->blockRect(i).top + 20 &&
					Cplayer->getmarioJumpPower() < 0)
				{
					Cplayer->setmarioY(Cblock->blockRect(i).top - 63);
					Cplayer->setmarioGravity(0);
					if (i == 9 || i == 10 || i == 11)
					{
						Cplayer->setmarioJumpPower(-10.f);

						if(i == 11)
							Cplayer->setmarioJumpPower(-30.f);


						if (Cplayer->marioRect().left > Cblock->blockRect(i).left)
							Cblock->setTrapOn(i - 9);
					}
						
					else
						Cplayer->setmarioJumpPower(0.f);
					Cplayer->setmarioJump(false);
				}

				// �÷��̾ �Ʒ����� �ε��� ��
				if (tempCenter.y > blockCenter.y &&
					Cplayer->marioRect().top + 10 > Cblock->blockRect(i).bottom)
				{
					Cplayer->setmarioY(Cblock->blockRect(i).bottom - 5);
					Cplayer->setmarioJumpPower(0);
				}

				// �÷��̾ ���ʿ��� �ε��� ��
				if (tempCenter.x < blockCenter.x &&
					Cplayer->marioRect().right < Cblock->blockRect(i).left + 20)
					Cplayer->setmarioX(Cblock->blockRect(i).left - 50);

				// �÷��̾ �����ʿ��� �ε��� ��
				if (tempCenter.x > blockCenter.x &&
					Cplayer->marioRect().left + 20 > Cblock->blockRect(i).right)
					Cplayer->setmarioX(Cblock->blockRect(i).right - 8);
			}
		}
	}
	

	// ���� �ٴں� ���� �浹
	if (Cmob->getmushroomisDead() == false)
	{
		for (int i = 0; i < MAX_GROUNDBLOCKNUM; i++)
		{
			if (IntersectRect(&temp, &Cmob->mushroomRect(), &Cblock->groundblockRect(i)))
			{
				// ���� �߽���
				blockCenter = { (Cblock->groundblockRect(i).left + Cblock->groundblockRect(i).right) / 2,
					(Cblock->groundblockRect(i).top + Cblock->groundblockRect(i).bottom) / 2 };

				// �浹�� ������ �߽���
				tempCenter = { (temp.left + temp.right) / 2,
					(temp.top + temp.bottom) / 2 };


				// �÷��̾ ������ �ε��� ��
				if (tempCenter.y < blockCenter.y &&
					Cmob->mushroomRect().bottom < Cblock->groundblockRect(i).top + 30)
				{
					Cmob->setmushroomY(Cblock->groundblockRect(i).top - 72);
					Cmob->setmobGravity(0);
				}
			}
		}
	}


	// �÷��̾�� ���� �浹

	// ������ ��
	if (Cmob->getmushroomisDead() == false)
	{
		if (IntersectRect(&temp, &Cplayer->marioRect(), &Cmob->mushroomRect()))
		{
			// ���� �߽���
			blockCenter = { (Cmob->mushroomRect().left + Cmob->mushroomRect().right) / 2,
				(Cmob->mushroomRect().top + Cmob->mushroomRect().bottom) / 2 };

			// �浹�� ������ �߽���
			tempCenter = { (temp.left + temp.right) / 2,
				(temp.top + temp.bottom) / 2 };


			// �÷��̾ ������ �ε��� ��, ���� ���κа� �浹�� ��
			if (tempCenter.y < blockCenter.y &&
				Cplayer->marioRect().bottom < Cmob->mushroomRect().top + 10 &&
				abs(((Cplayer->marioRect().left + Cplayer->marioRect().right) / 2) - blockCenter.x) < 20)
			{
				Cplayer->setmarioY(Cmob->mushroomRect().top - 63);
				Cplayer->setmarioJumpPower(9.0f);
				Cplayer->setmarioJump(false);
				Cmob->setmushroomisDead(true);
			}

			// �÷��̾ ������ �ε������� ���� ���κ��� �ƴ϶� ���κа� �浹�� ��
			if (tempCenter.y < blockCenter.y &&
				Cplayer->marioRect().bottom < Cmob->mushroomRect().top + 10 &&
				abs(((Cplayer->marioRect().left + Cplayer->marioRect().right) / 2) - blockCenter.x) > 20)
			{
				Cplayer->marioEnd();
				Cplayer->marioEndMotion();
			}

			// �÷��̾ �Ʒ����� �ε��� ��
			if (tempCenter.y > blockCenter.y &&
				Cplayer->marioRect().top + 10 > Cmob->mushroomRect().bottom)
			{
				Cplayer->marioEnd();
				Cplayer->marioEndMotion();
			}

			// �÷��̾ ���ʿ��� �ε��� ��
			if (tempCenter.x < blockCenter.x &&
				Cplayer->marioRect().right < Cmob->mushroomRect().left + 10)
			{
				Cplayer->marioEnd();
				Cplayer->marioEndMotion();
			}
				

			// �÷��̾ �����ʿ��� �ε��� ��
			if (tempCenter.x > blockCenter.x &&
				Cplayer->marioRect().left + 10 > Cmob->mushroomRect().right)
			{
				Cplayer->marioEnd();
				Cplayer->marioEndMotion();
			}	
		}
	}
}


// �¿�� �з����� ���
/*
void collision::keepCollision(player * Cplayer, block * Cblock, mob * Cmob)
{
	if (collisionOccur == true)
	{
		if (collisionType == LEFT)
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
			
		if (collisionType == RIGHT)
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
*/