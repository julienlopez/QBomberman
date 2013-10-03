#ifndef ENTITYCREATOR_HPP
#define ENTITYCREATOR_HPP

class ScreenPosition;

#include <string>

class EntityCreator
{
public:
    EntityCreator() = delete;

    static void createTileEntity(const std::string& fileName, int x, int y, bool hard);

    static void spawnPlayer();

    static void createWallEntity(int x, int y);

    static void createBomb(const ScreenPosition& position, double lifeTime);
};

#endif // ENTITYCREATOR_HPP
