#ifndef UPDATEPOLICIES_HPP
#define UPDATEPOLICIES_HPP

#include "entitymanager.hpp"

#include <utils/safepointer.hpp>

template<class T> class OneByOnePolicy
{
protected:
    void dispatchEntitiesForUpdate(double dt)
    {
        T& s = static_cast<T&>(*this);
        EntityManager::for_each([&s, dt](EntityManager::EntityId entity, EntityManager::type_entity_key key)
        {
            if((key & s.requirement()) != s.requirement()) return;
            static_cast<OneByOnePolicy<T>&>(s).do_update(entity, dt);
        });
    }

    virtual void do_update(EntityManager::EntityId entity, double dt) =0;
};

template<class T> class ListPolicy
{
public:
    using type_list_entities = std::list<EntityManager::EntityId>;
protected:
    void dispatchEntitiesForUpdate(double dt)
    {
        T& s = static_cast<T&>(*this);
        type_list_entities lst;
        EntityManager::for_each([&lst, &s](EntityManager::EntityId entity, EntityManager::type_entity_key key)
        {
            if((key & s.requirement()) != s.requirement()) return;
            lst.push_back(entity);

        });
        static_cast<ListPolicy<T>&>(s).do_update(std::move(lst), dt);
    }

    virtual void do_update(type_list_entities&& entities, double dt) =0;
};

#endif // UPDATEPOLICIES_HPP
