#include "Tower.h"
#include "GameManager.h"
#include "UI.h"

//LVLUPS WILL INCREASE SPEED OF BULLET AND INCREASE RADIUS

 Tower::Tower(sf::Vector2f _position) 
{
	 chosen = false;
	 target = nullptr;
	 ratio = 1.f;
	 turnRatio = 0.3f;
	 toShoot = false;
	 damage = 10;
	 toDraw = true;

     id = 't'; 
	 texture = SMapper->getTexture(id);
	 sprite.setTexture(texture);

	 Place(_position);

	 sf::Vector2f newOrigin((sprite.getGlobalBounds().width / 2), (sprite.getGlobalBounds().height / 2));
	 sprite.setOrigin(newOrigin);

	 constructRadiusShape();

}

 void Tower::Place(sf::Vector2f _position)
{
	_position.x = (int)(_position.x / 50) * 50;
	_position.y = (int)(_position.y / 50) * 50;


	//Костыль, из-за отличия в origin Chank`a и Tower`а

	_position.x += 25;
	_position.y += 25;

	position = _position;
	sprite.setPosition(position);

}
 void Tower::constructRadiusShape() 
 {
	 radius.setFillColor(sf::Color(135, 206, 250, 100));
	
	 radius.setPosition(position.x, position.y);
	 setRadius(100);

	 drawRadius = true;
 }

 void Tower::Draw(sf::RenderWindow& window) 
 {
	 window.draw(sprite);
	 
	 for (int i = 0; i < bulletVector.size(); i++) 
	 {
		 if (bulletVector[i].hasTarget()) 
		 {
			 bulletVector[i].MoveTo(bulletVector[i].getTargetPosition());
		 }
		 else { bulletVector[i].Move(); }

		 bulletVector[i].Draw(window);
	 }
	 // ratio changed for turnRatio!
	 if (ratioClock.getElapsedTime().asSeconds() >= ratio)
	 {
		 this->Shoot();
	 }
	 if (turnClock.getElapsedTime().asSeconds() >= turnRatio) 
	 {
		 CheckForEnemy();
	 }
	 if (chosen) 
	 {
		 window.draw(radius);
	 }
	 //if (drawRadius) { window.draw(radius); }

	 DestroyTaggedBullets();
 }

 void Tower::CheckForEnemy() 
 {
	 for (auto& obj : ObjectsVector)
	 {
		 if (dynamic_cast<Enemy*>(obj)) 
		 {
			// Собираем информацию о всех врагах в радиусе
			// Смотрим какой ближе всего || Смотрим какой был заспавнен раньше
			// Стреляем
			// Если враг в которого стреляли вышел из радиуса, убираем таргет на него и снова ищем нового врага
			// Пуля должна научится запоминать свой Таргет, и всегда долетать до него

			 if (radius.getGlobalBounds().contains(obj->getSprite().getPosition()))		
			 {
				 target  = dynamic_cast<Enemy*>(obj);
				 toShoot = true;
				 RotateTo(target->getPosition());
			 }
		 }
	 }
	 if (target != nullptr && radius.getGlobalBounds().contains(target->getSprite().getPosition()) == false)
	 {
		 toShoot = false;
		 target = nullptr;
		 sprite.setRotation(0);
	 }
 }
 void Tower::Shoot() 
 {
	 ratioClock.restart();
	 if (toShoot && target != nullptr)
	 {
		 bulletVector.push_back(Bullet(this->position.x, this->position.y, target));
	 }
 }


 void Tower::Upgrade() 
 {
	 if (GManager->getPlayer().getMoney() >= Tower::UpgradePrice)
	 {
		 GManager->getPlayer().getMoney() -= Tower::UpgradePrice;
		 ratio -= 0.2;
		 damage += 5;
		 setRadius(radius.getRadius() + 20);
		 sprite.setColor(sf::Color::Yellow);
		 
		 UIManager->UpdateUI();
	 }
 }

 void Tower::RemapTargets() 
 {

	 for (auto& o : ObjectsVector) 
	 {
		 if (dynamic_cast<Tower*>(o)) 
		 {
			 bool found = false;
			 Tower* tower = dynamic_cast<Tower*>(o);

			 for (auto& e : ObjectsVector) 
			 {
				 if (dynamic_cast<Enemy*>(e)) 
				 {
					 Enemy* enemy = dynamic_cast<Enemy*>(e);

					 if (tower->getSprite().getGlobalBounds().contains(enemy->getPosition())) 
					 {
						 found = true;
						 tower->target = enemy;
						 tower->toShoot = true;
						 tower->RotateTo(enemy->getPosition());
					 }
				 }
			 }

			 if (found != true) 
			 {
				 tower->target = nullptr;
				 tower->toShoot = false;
				 tower->getSprite().setRotation(0);
			 }
		 }
	 }

	 //for (auto a : ObjectsVector)
	 //{
		// if (dynamic_cast<Tower*>(a))
		// {
		//	 bool found = false;
		//	 Tower* t = dynamic_cast<Tower*>(a);

		//	 for (auto b : ObjectsVector)
		//	 {
		//		 if (dynamic_cast<Enemy*>(b))
		//		 {
		//			 Enemy* en = dynamic_cast<Enemy*>(b);

		//			 if (t->getRadius().getGlobalBounds().contains(b->getSprite().getPosition()))
		//			 {
		//				 found = true;
		//				 
		//			 }
		//		 }
		//	 }
		//	 if (found != true)
		//	 {
		//		 t->getSprite().setRotation(0);
		//		 
		//	 }
		// }
	 //}
 }


//
	// ~ Setters
//

 void Tower::setRadius(float _radius) 
 {
	 this->radius.setRadius(_radius);
	 this->radius.setOrigin(radius.getRadius(), radius.getRadius());
 }
 void Tower::setPosition(sf::Vector2f _position)
 {
	 position = _position;
	 this->sprite.setPosition(position);
 }
 void Tower::RotateTo(sf::Vector2f _position)
 {
	 const float pi = 3.14159265;

	 //set a proper origin for sprite

	 //rotate to mouse position
	 float dx = this->position.x - _position.x;
	 float dy = this->position.y - _position.y;

	 float rotation = (atan2(dy, dx) * 180 / pi);

	 this->sprite.setRotation(rotation + 270);
 }

//
	// ~ Getters
//

 sf::CircleShape& Tower::getRadius() { return radius; }
 std::vector<Bullet>& Tower::getBulletVector() { return bulletVector; }
 void Tower::DestroyTaggedBullets() 
 {
	 if (bulletVector.size() == 1 && bulletVector[bulletVector.size() - 1].isDying()) 
	 { 
		 
		 bulletVector.clear(); 
	 }
	 // Lol this thing fixed issue omgwtf

	 for (int i = bulletVector.size() - 1; i >= 0; --i) 
	 {
		 if (bulletVector[i].isDying()) 
		 {
			
			 bulletVector.erase(bulletVector.begin() + i);
			 continue;
		 }
		 if (bulletVector[i].getClock().getElapsedTime().asSeconds() >= bulletVector[i].getLifeTime()) 
		 {
			
			 bulletVector.erase(bulletVector.begin() + i);
		 }


	 }
 }