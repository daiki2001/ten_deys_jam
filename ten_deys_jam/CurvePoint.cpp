#include "CurvePoint.h"
#include <DxLib.h>
#include "Player.h"

CurvePoint::CurvePoint() :
	posX(0),
	posY(0),
	direction(Player::Direction::UP),
	turnRightFlag(false),
	frame(0),
	animation(0),
	graphArray{},
	drawFlag(false)
{
}

void CurvePoint::Init()
{
	posX = 0;
	posY = 0;
	direction = Player::Direction::UP;
	turnRightFlag = false;
	frame = 0;
	animation = 0;
	drawFlag = false;

	LoadDivGraph("Resources/turnEffect.png", 9, 9, 1, 48, 48, graphArray);
}

void CurvePoint::Update(int posX, int posY, int direction, bool turnFlag, Map* map)
{
	// ‹È‚ª‚ê‚éêŠ‚Ì’Tõ
	int mapchip = 0;

	this->posX = posX / 16;
	this->posY = posY / 16;
	this->direction = direction;

	switch (this->direction)
	{
	case Player::Direction::UP:
		do
		{
			switch (mapchip = map->map[this->posY][this->posX])
			{
			case 3:
				this->drawFlag = true;
				this->turnRightFlag = true;
				break;
			case 4:
				this->drawFlag = true;
				this->turnRightFlag = false;
				break;
			case Status::JUNCTION:
			case 9:
			case 10:
				if (turnFlag == true)
				{
					this->drawFlag = true;
					this->turnRightFlag = false;
					break;
				}
			default:
				this->posY--;

				if (this->posY < 0)
				{
					this->posY += MAP_HEIGHT;
				}
				break;
			}
		} while (mapchip != 3 && mapchip != 4 && mapchip != 9 && mapchip != 10 &&
			mapchip != Status::JUNCTION && mapchip != Status::WALL);
		break;
	case Player::Direction::LEFT:
		do
		{
			switch (mapchip = map->map[this->posY][this->posX])
			{
			case 3:
				this->drawFlag = true;
				this->turnRightFlag = false;
				break;
			case 5:
				this->drawFlag = true;
				this->turnRightFlag = true;
				break;
			case Status::JUNCTION:
			case 9:
			case 11:
				if (turnFlag == true)
				{
					this->drawFlag = true;
					this->turnRightFlag = false;
					break;
				}
			default:
				this->posX--;

				if (this->posX < 0)
				{
					this->posX += MAP_WIDTH;
				}
				break;
			}
		} while (mapchip != 3 && mapchip != 5 && mapchip != 9 && mapchip != 11 &&
			mapchip != Status::JUNCTION && mapchip != Status::WALL);
		break;
	case Player::Direction::DOWN:
		do
		{
			switch (mapchip = map->map[this->posY][this->posX])
			{
			case 5:
				this->drawFlag = true;
				this->turnRightFlag = false;
				break;
			case 6:
				this->drawFlag = true;
				this->turnRightFlag = true;
				break;
			case Status::JUNCTION:
			case 8:
			case 11:
				if (turnFlag == true)
				{
					this->drawFlag = true;
					this->turnRightFlag = false;
					break;
				}
			default:
				this->posY++;

				if (this->posY >= MAP_HEIGHT)
				{
					this->posY -= MAP_HEIGHT;
				}
				break;
			}
		} while (mapchip != 5 && mapchip != 6 && mapchip != 8 && mapchip != 11 &&
			mapchip != Status::JUNCTION && mapchip != Status::WALL);
		break;
	case Player::Direction::RIGHT:
		do
		{
			switch (mapchip = map->map[this->posY][this->posX])
			{
			case 4:
				this->drawFlag = true;
				this->turnRightFlag = true;
				break;
			case 6:
				this->drawFlag = true;
				this->turnRightFlag = false;
				break;
			case Status::JUNCTION:
			case 8:
			case 10:
				if (turnFlag == true)
				{
					this->drawFlag = true;
					this->turnRightFlag = false;
					break;
				}
			default:
				this->posX++;

				if (this->posX >= MAP_WIDTH)
				{
					this->posX -= MAP_WIDTH;
				}
				break;
			}
		} while (mapchip != 4 && mapchip != 6 && mapchip != 8 && mapchip != 10 &&
			mapchip != Status::JUNCTION && mapchip != Status::WALL);
		break;
	default:
		break;
	}

	this->posX *= 16;
	this->posY *= 16;
	this->frame++;

	if (this->frame % 3 == 0)
	{
		this->animation++;
		this->animation %= 9;
	}
}

void CurvePoint::Draw(int offsetX, int offsetY)
{
	if (drawFlag == true)
	{
		if (turnRightFlag == true)
		{
			if (direction == Player::Direction::UP || direction == Player::Direction::DOWN)
			{
				DrawRotaGraph(
					posX + offsetX + 8,
					posY + offsetY + 8,
					1.0,
					2 * DX_PI / 4 * (direction + 1),
					graphArray[animation],
					true,
					true);
			}
			else
			{
				DrawRotaGraph(
					posX + offsetX + 8,
					posY + offsetY + 8,
					1.0,
					2 * DX_PI / 4 * (direction - 1),
					graphArray[animation],
					true,
					true);
			}
		}
		else
		{
			DrawRotaGraph(
				this->posX + offsetX + 8,
				this->posY + offsetY + 8,
				1.0,
				(2 * DX_PI) - (2 * DX_PI / 4 * (direction + 1)),
				graphArray[animation],
				true,
				false);
		}
	}

	drawFlag = false;
}
