#ifndef SYSTEMFACTORY_HPP
#define SYSTEMFACTORY_HPP

#include <utils/factorywithautoid.hpp>

#include "system.hpp"

typedef utils::FactoryWithAutoId<System, System::type_key> SystemFactory;

#endif // SYSTEMFACTORY_HPP
