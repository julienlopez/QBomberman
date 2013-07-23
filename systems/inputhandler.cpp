#include "inputhandler.hpp"
#include <entitymanager.hpp>

InputHandler::InputHandler()
{}

//namespace
//{
//    std::string toStr(QBomberMan::KEYS  key)
//    {
//        switch(key)
//        {
//        case QBomberMan::UP: return "up";
//        case QBomberMan::DOWN: return "down";
//        case QBomberMan::LEFT: return "left";
//        case QBomberMan::RIGHT: return "right";
//        default: return "none";
//        }
//    }
//}

#include <QDebug>
void InputHandler::setCurrentKey(QBomberMan::KEYS currentKey)
{
//    qDebug() << "InputHandler::setCurrentKey() : " << toStr(currentKey).c_str();
    m_currentKey = currentKey;
}

void InputHandler::do_update(Entity& entity, double)
{
//    if(m_currentKey == InputToVelocity::NONE) return;
    Velocity& v = EntityManager::getComponent<Velocity>(entity);
    InputToVelocity& i2v = EntityManager::getComponent<InputToVelocity>(entity);
    v.m_vector = i2v.key2Velocity(m_currentKey);
    if(v.m_vector != PointF())
        qDebug() << v.m_vector.x() << ", " << v.m_vector.y();
}
