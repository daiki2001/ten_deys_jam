#include "Player.h"
#include <DxLib.h>
#include "Input.h"

Player::Player() :
	posX(0),
	posY(0),
	speed(0),
	maxSpeed(0),
	direction(Player::Direction::LEFT),
	turnFlag(false),
	playerGraph{},
	turnEffect{},
	curveEffect{},
	curvePoint{}
{
}

void Player::Init(int posX, int posY, int maxSpeed, int direction)
{
	this->posX = posX;
	this->posY = posY;
	this->speed = maxSpeed;
	this->maxSpeed = maxSpeed;
	this->direction = direction;
	this->turnFlag = false;

	LoadDivGraph("Resources/Sprite-0002.png", 4, 4, 1, 16, 16, playerGraph);
	curvePoint.Init();
}

void Player::Update(Map* map)
{
	if (Input::IsKeyTrigger(KEY_INPUT_SPACE) == true)
	{
		turnFlag = !turnFlag;
	}

	if (Input::IsKey(KEY_INPUT_B) == true)
	{
		speed--;

		if (speed < 1)
		{
			speed = 1;
		}
	}
	else
	{
		speed++;

		if (speed > maxSpeed)
		{
			speed = maxSpeed;
		}
	}

	curvePoint.Update(posX, posY, direction, turnFlag, map);

	switch (Collision(map))
	{
	case 3:
		if (direction == Player::Direction::LEFT)
		{
			curveEffect.Init(posX, posY, direction, false);
			direction++;
			direction %= 4;
		}
		else if (direction == Player::Direction::UP)
		{
			curveEffect.Init(posX, posY, direction, true);
			direction--;

			if (direction < 0)
			{
				direction += 4;
			}

			direction %= 4;
		}
		break;
	case 4:
		if (direction == Player::Direction::UP)
		{
			curveEffect.Init(posX, posY, direction, false);
			direction++;
			direction %= 4;
		}
		else if (direction == Player::Direction::RIGHT)
		{
			curveEffect.Init(posX, posY, direction, true);
			direction--;

			if (direction < 0)
			{
				direction += 4;
			}

			direction %= 4;
		}
		break;
	case 5:
		if (direction == Player::Direction::DOWN)
		{
			curveEffect.Init(posX, posY, direction, false);
			direction++;
			direction %= 4;
		}
		else if (direction == Player::Direction::LEFT)
		{
			curveEffect.Init(posX, posY, direction, true);
			direction--;

			if (direction < 0)
			{
				direction += 4;
			}

			direction %= 4;
		}
		break;
	case 6:
		if (direction == Player::Direction::RIGHT)
		{
			curveEffect.Init(posX, posY, direction, false);
			direction++;
			direction %= 4;
		}
		else if (direction == Player::Direction::DOWN)
		{
			curveEffect.Init(posX, posY, direction, true);
			direction--;

			if (direction < 0)
			{
				direction += 4;
			}

			direction %= 4;
		}
		break;
	case Status::JUNCTION:
		if (turnFlag == true)
		{
			curveEffect.Init(posX, posY, direction, false);
			turnFlag = false;
			direction++;
			direction %= 4;
		}
		break;
	case 8:
		if (turnFlag == true)
		{
			if (direction == Player::Direction::DOWN || direction == Player::Direction::RIGHT)
			{
				curveEffect.Init(posX, posY, direction, false);
				turnFlag = false;
				direction++;
				direction %= 4;
			}
		}
		else
		{
			if (direction == Player::Direction::DOWN)
			{
				turnEffect.Init(posX, posY, direction);
				direction = Player::Direction::UP;
			}
		}
		break;
	case 9:
		if (turnFlag == true)
		{
			if (direction == Player::Direction::UP || direction == Player::Direction::LEFT)
			{
				curveEffect.Init(posX, posY, direction, false);
				turnFlag = false;
				direction++;
				direction %= 4;
			}
		}
		break;
	case 10:
		if (turnFlag == true)
		{
			if (direction == Player::Direction::RIGHT || direction == Player::Direction::UP)
			{
				curveEffect.Init(posX, posY, direction, false);
				turnFlag = false;
				direction++;
				direction %= 4;
			}
		}
		else
		{
			if (direction == Player::Direction::RIGHT)
			{
				turnEffect.Init(posX, posY, direction);
				direction = Player::Direction::LEFT;
			}
		}
		break;
	case 11:
		if (turnFlag == true)
		{
			if (direction == Player::Direction::LEFT || direction == Player::Direction::DOWN)
			{
				curveEffect.Init(posX, posY, direction, false);
				turnFlag = false;
				direction++;
				direction %= 4;
			}
		}
		else
		{
			if (direction == Player::Direction::LEFT)
			{
				turnEffect.Init(posX, posY, direction);
				direction = Player::Direction::RIGHT;
			}
		}
		break;
	case Status::WALL:
		turnEffect.Init(posX, posY, direction);
		direction += 2;
		direction %= 4;
		break;
	default:
		break;
	}

	if (posX < 0 && direction == Player::Direction::LEFT)
	{
		posX = 16 * MAP_WIDTH + posX;
	}
	else if (posX > 16 * (MAP_WIDTH - 1) && direction == Player::Direction::RIGHT)
	{
		posX = (16 * (MAP_WIDTH - 1)) - posX;
	}
	if (posY < 0 && direction == Player::Direction::UP)
	{
		posY = 16 * MAP_HEIGHT + posY;
	}
	else if (posY > 16 * (MAP_HEIGHT - 1) && direction == Player::Direction::DOWN)
	{
		posY = (16 * (MAP_HEIGHT - 1)) - posY;
	}

	Move();
	turnEffect.Update();
	curveEffect.Update();
}

void Player::Draw(int offsetX, int offsetY)
{
	turnEffect.Draw(offsetX, offsetY);
	curveEffect.Draw(offsetX, offsetY);
	curvePoint.Draw(offsetX, offsetY);
	DrawGraph(posX + offsetX, posY + offsetY, playerGraph[direction], true);
}

int Player::Collision(Map* map)
{
	// マイナスを消してplayerX,playerYに代入する
	int playerX = MAP_WIDTH * 16 + posX;
	int playerY = MAP_HEIGHT * 16 + posY;
	// playerX,playerYをマップ内に収まるようする
	playerX %= MAP_WIDTH * 16;
	playerY %= MAP_HEIGHT * 16;

	for (size_t y = 0; y < MAP_HEIGHT; y++)
	{
		if (playerY < (y + 1) * 16 && playerY + 16 - 1 > y * 16)
		{
			for (size_t x = 0; x < MAP_WIDTH; x++)
			{
				if (playerX < (x + 1) * 16 && playerX + 16 - 1 > x * 16)
				{
					return map->map[y][x];
				}
			}
		}
	}
}

void Player::Move()
{
	switch (direction)
	{
	case Player::Direction::LEFT:
		posX -= speed;
		posY /= 16;
		posY *= 16;
		break;
	case Player::Direction::RIGHT:
		posX += speed;
		posY /= 16;
		posY *= 16;
		break;
	case Player::Direction::UP:
		posY -= speed;
		posX /= 16;
		posX *= 16;
		break;
	case Player::Direction::DOWN:
		posY += speed;
		posX /= 16;
		posX *= 16;
		break;
	default:
		break;
	}
}
