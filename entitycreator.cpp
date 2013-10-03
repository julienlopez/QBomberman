#include "entitycreator.hpp"
#include "entitymanager.hpp"
#include "components/graphic.hpp"
#include "components/screenposition.hpp"
#include "components/velocity.hpp"
#include <components/player.hpp>
#include <components/collisionbox.hpp>
#include <components/lifetime.hpp>
#include <components/explosionimpact.hpp>

void EntityCreator::createTileEntity(const std::string& fileName, int x, int y, bool hard)
{
    Entity::type_list_components res;
    Entity::up_component pos(new ScreenPosition(PointF(x+.5, y+.5)));
    res.push_back(std::move(pos));
    Entity::up_component graphic(new Graphic(fileName));
    res.push_back(std::move(graphic));
    res.push_back(Entity::up_component(new CollisionBox));
    res.push_back(Entity::up_component(new ExplosionImpact(hard?ExplosionImpact::Hard:ExplosionImpact::Soft)));
    EntityManager::addEntity(std::move(res));
}

void EntityCreator::spawnPlayer()
{
    Entity::type_list_components res;
    Entity::up_component pos(new ScreenPosition(PointF(.5, .5)));
    res.push_back(std::move(pos));
    Graphic* graphic = new Graphic("images/player.png");
    res.push_back(Entity::up_component(graphic));
    res.push_back(Entity::up_component(new Velocity));
    res.push_back(Entity::up_component(new Player));
    res.push_back(Entity::up_component(new CollisionBox));
    EntityManager::addEntity(std::move(res));
}

void EntityCreator::createWallEntity(int x, int y)
{
    Entity::type_list_components res;
    Entity::up_component pos(new ScreenPosition(PointF(x+.5, y+.5)));
    res.push_back(std::move(pos));
    res.push_back(Entity::up_component(new CollisionBox));
    EntityManager::addEntity(std::move(res));
}

void EntityCreator::createBomb(const ScreenPosition& position, double lifeTime)
{
    Entity::type_list_components lst;
    ScreenPosition* p = static_cast<ScreenPosition*>(position.clone());
    PointF point = p->pos();
    point.setX(floor(point.x())+.5);
    point.setY(floor(point.y())+.5);
    p->move(point - p->pos());
    Entity::up_component pos(p);
    lst.push_back(std::move(pos));
    Entity::up_component graphic(new Graphic("images/bomb.png"));
    lst.push_back(std::move(graphic));
    Entity::up_component lt(new LifeTime(lifeTime));
    lst.push_back(std::move(lt));
    EntityManager::addEntity(std::move(lst));
}
