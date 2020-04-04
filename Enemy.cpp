#include "Enemy.h"

#include "Tower.h"

#include "GameManager.h"

#include "UI.h"

Enemy::Enemy(sf::Vector2f position) 
{

	std::cout << "Enemy()\n";

	collisionRect.setSize(sf::Vector2f(1, 1));
	
	toDie = false;
	health = 50;
	toDraw = true;
	id = 'x';
	texture = SMapper->getTexture(id);
	
	speed = 1.f;
	moveDirection = 4;

	sprite.setTexture(texture);
	sprite.setRotation(90);

	this->position = position;
	sprite.setPosition(this->position);

	sf::Vector2f neworigin((sprite.getGlobalBounds().width / 2), (sprite.getGlobalBounds().height / 2));
	sprite.setOrigin(neworigin);
	collisionRect.setOrigin(neworigin);
	collisionRect.setPosition(sprite.getPosition().x, sprite.getPosition().y);
}

void Enemy::CheckDirection()
{
	//std::cout << "CheckDirection()\n";

	for (auto& obj : ObjectsVector) 
	{
		if (dynamic_cast<Chunk*>(obj)) 
		{
			auto c = dynamic_cast<Chunk*>(obj);

			if (collisionRect.getGlobalBounds().intersects(c->getCollisionRect().getGlobalBounds())) 
			{
				this->setDirection(c->getTurnDirection());
			}
		}
	}
}

void Enemy::setDirection(int _dir_id) 
{
	//std::cout << "setDirection()\n";

	this->moveDirection = _dir_id;
	updateRotation();
}

void Enemy::getDamage(int _damage) 
{
	//std::cout << "Got Damage\n";

	this->health -= _damage;
	if (this->health <= 0) { Die(); }
}

void Enemy::Die() 
{
	toDie = true;
}

void Enemy::updateRotation() 
{

	//std::cout << "updateRotation()\n";

	switch (moveDirection)
	{
	case 1: sprite.setRotation(0);
		break;
	case 2: sprite.setRotation(180);
		break;
	case 3: sprite.setRotation(270);
		break;
	case 4: sprite.setRotation(90);
		break;
	default:
		sprite.setRotation(0);
		break;
	}
}
// 1 - UP , 2 - DOWN, 3 - LEFT, 4 - RIGHT   0 - default


//TODO:
// Optimize MoveDirection

void Enemy::DeleteTagged() 
{
	for (int i = ObjectsVector.size() - 1; i > 0; i--) 
	{
		if (dynamic_cast<Enemy*>(ObjectsVector[i]))
		{
			auto ref = dynamic_cast<Enemy*>(ObjectsVector[i]);

			if (ref->toDie == true) 
			{
				std::cout << "Ship Dead\n";
				ObjectsVector.erase(ObjectsVector.begin() + i);
				GManager->getPlayer().getMoney() += Price;
				UIManager->UpdateUI();
				
				// Call Remap Targets Function
				
				Tower::RemapTargets();
				
			}
		}
	}
}



void Enemy::Draw(sf::RenderWindow& window)
{

	if ((int)this->sprite.getPosition().x % 25 == 0 && (int)this->sprite.getPosition().y % 25 == 0) 
	{
		CheckDirection();
	}

	float toX = 0;
	float toY = 0;

	switch (this->moveDirection)
	{
	case 1: {toX = 0; toY = speed * -1; }
		  break;
	case 2: {toX = 0; toY = speed; }
		  break;
	case 3: {toX = speed * -1; toY = 0; }
		  break;
	case 4: {toX = speed; toY = 0; }
		  break;
	default: 
		toX = speed;
		toY = 0;
		break;
	}


	this->sprite.move(toX, toY);
	this->position = sprite.getPosition();
	this->collisionRect.setPosition(position.x + 25, position.y + 25);


	//Delete Tagged
	DeleteTagged();

	window.draw(this->sprite);
}

