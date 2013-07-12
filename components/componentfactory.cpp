#include "componentfactory.hpp"

#include <cassert>

Component* ComponentFactory::create(type_key id)
{
    ComponentFactory& inst = instance();
    if(id >= inst.m_containr.size()) return 0;
    return inst.m_containr[id]();
}

//#include <iostream>
//using namespace std;

ComponentFactory::type_key ComponentFactory::registerProduct(type_callback creator)
{
    ComponentFactory& inst = instance();
    type_key res = inst.m_containr.size();
    assert(res < Component::nbMaxComponents);
    inst.m_containr.push_back(creator);
//    cerr << "registered a type at " << res << endl;
    return res;
}
