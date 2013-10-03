#include <QApplication>
#include "mainwindow.hpp"

#include <utils/point.hpp>
#include "static_tests/test_parameter_traits.hpp"
#include "entitycreator.hpp"

void initEntitiesTest()
{
    for(int x = 1; x < 10; x += 2)
        for(int y = 1; y < 10; y += 2)
            EntityCreator::createTileEntity("images/tile3.png", x, y, true);
    std::list<Point> holes = {Point(0, 0), Point(0, 1), Point(1, 0), Point(10, 10), Point(10, 9), Point(9, 10),
                              Point(0, 10), Point(0, 9), Point(1, 10), Point(10, 0), Point(10, 1), Point(9, 0)};
    for(int x = 0; x < 11; x++)
        for(int y = 0; y < 11; y++)
        {
            if(std::find(holes.begin(), holes.end(), Point(x, y)) == holes.end() && (x%2 != 1 || y%2 != 1))
                EntityCreator::createTileEntity("images/tile1.png", x, y, false);
        }
    EntityCreator::spawnPlayer();

    EntityCreator::createWallEntity(-1, -1);
    EntityCreator::createWallEntity(11, -1);
    EntityCreator::createWallEntity(11, 11);
    EntityCreator::createWallEntity(-1, 11);
    for(int i = 0; i < 11; i++)
    {
        EntityCreator::createWallEntity(-1, i);
        EntityCreator::createWallEntity(11, i);
        EntityCreator::createWallEntity(i, -1);
        EntityCreator::createWallEntity(i, 11);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    initEntitiesTest();

    MainWindow w;
    w.show();
    
    return a.exec();
}
