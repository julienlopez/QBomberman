#include <QApplication>
#include "mainwindow.hpp"

#include "static_tests/test_parameter_traits.hpp"


#include "entitymanager.hpp"
#include "components/tileposition.hpp"
#include "components/graphic.hpp"
#include "components/screenposition.hpp"
#include "components/velocity.hpp"
#include "components/inputtovelocity.hpp"

Entity::type_list_components createTileEntity(const std::string& fileName, int x, int y)
{
    Entity::type_list_components res;
    TilePosition* pos = new TilePosition(Point(x, y));
    res.push_back(Entity::up_component(pos));
    Graphic* graphic = new Graphic(fileName);
    res.push_back(Entity::up_component(graphic));
    return res;
}

Entity::type_list_components spawnPlayer()
{
    Entity::type_list_components res;
    ScreenPosition* pos = new ScreenPosition(PointF(.5, .5));
    res.push_back(Entity::up_component(pos));
    Graphic* graphic = new Graphic("images/player.png");
    res.push_back(Entity::up_component(graphic));
    res.push_back(Entity::up_component(new Velocity));
    res.push_back(Entity::up_component(new InputToVelocity));
    return res;
}

void initEntitiesTest()
{
    for(int x = 1; x < 10; x += 2)
        for(int y = 1; y < 10; y += 2)
            EntityManager::addEntity(createTileEntity("images/tile3.png", x, y));
    std::list<Point> holes = {Point(0, 0), Point(0, 1), Point(1, 0), Point(10, 10), Point(10, 9), Point(9, 10),
                              Point(0, 10), Point(0, 9), Point(1, 10), Point(10, 0), Point(10, 1), Point(9, 0)};
    for(int x = 0; x < 11; x++)
        for(int y = 0; y < 11; y++)
        {
            if(std::find(holes.begin(), holes.end(), Point(x, y)) == holes.end() && (x%2 != 1 || y%2 != 1))
                EntityManager::addEntity(createTileEntity("images/tile1.png", x, y));
        }
    EntityManager::addEntity(spawnPlayer());
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    initEntitiesTest();

    MainWindow w;
    w.show();
    
    return a.exec();
}
