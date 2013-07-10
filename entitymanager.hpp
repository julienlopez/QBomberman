#ifndef __ENTITYMANAGER_HPP__
#define __ENTITYMANAGER_HPP__

#include <utils/singleton.hpp>

#include "components/component.hpp"

#include <cstdint>
#include <list>
#include <memory>
#include <map>

class EntityManager : public utils::Singleton<EntityManager>
{
	typedef uint64_t type_id;
	typedef uint16_t type_key;

	static type_key geTkey(type_id id);

private:
	struct Entity
	{
		type_key key;
        std::list<std::unique_ptr<Component>> components;
	};

    typedef std::map<type_id, Entity> type_map;

    type_map m_entities;
};

#endif
