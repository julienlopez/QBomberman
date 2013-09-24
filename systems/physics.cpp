#include "physics.hpp"
#include <components/screenposition.hpp>
#include <components/velocity.hpp>

#include <cassert>

#include <QRect>
#include <QDebug>

namespace
{
double cutIfGreaterThanPointEight(double d)
{
    return (abs(d)>0.6?0:d);
}
}

void Physics::do_update(ListPolicy::type_list_entities&& entities, double)
{
    static constexpr double size = 1.;
    for(ListPolicy::type_list_entities::iterator i = entities.begin(); i != entities.end(); ++i)
    {
        ListPolicy::type_list_entities::iterator j = i;
        ++j;
        for(; j != entities.end(); ++j)
        {
            ScreenPosition& pos1 = EntityManager::getComponent<ScreenPosition>(**i);
            ScreenPosition& pos2 = EntityManager::getComponent<ScreenPosition>(**j);
            QRectF rect1(pos1.pos().x(), pos1.pos().y(), size, size);
            QRectF rect2(pos2.pos().x(), pos2.pos().y(), size, size);

#if QT_VERSION >= 0x050000
            QRectF overlap = rect1.intersected(rect2);
#else
            QRectF overlap = rect1.intersect(rect2);
#endif

            if(overlap.isEmpty()) continue;
            bool canMove1 = EntityManager::hasComponent<Velocity>(**i);
            bool canMove2 = EntityManager::hasComponent<Velocity>(**j);
            if(canMove1 == canMove2)
            {
                assert(0 && "not done yet");
            }
            else
            {
                double dx = cutIfGreaterThanPointEight(overlap.width());
                double dy = cutIfGreaterThanPointEight(overlap.height());
                if(rect1.x() < rect2.x()) dx = -dx;
                if(rect1.y() < rect2.y()) dy = -dy;
                if(canMove1)
                {
                    pos1.move(PointF(dx, dy));
                }
                else
                {
                    pos2.move(PointF(-dx, -dy));
                }
            }
        }
    }
}
