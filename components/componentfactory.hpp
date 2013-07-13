#ifndef COMPONENTFACTORY_HPP
#define COMPONENTFACTORY_HPP

#include <utils/factorywithautoid.hpp>

#include "component.hpp"

typedef utils::FactoryWithAutoId<Component, Component::type_key, utils::VectorStorageWithFlagId> ComponentFactory;

#endif // COMPONENTFACTORY_HPP
