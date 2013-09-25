#ifndef FACTORYWITHAUTOID_HPP
#define FACTORYWITHAUTOID_HPP

#include <utils/singleton.hpp>
#include <utils/defaultfactoryerrorpolicy.hpp>
#include <utils/defaultfactorystoragepolicies.hpp>

#include <functional>
#include <cassert>

BEGIN_NAMESPACE_UTILS

/**
 * \class FactoryWithAutoId factorywithautoid.hpp utils/factorywithautoid.hpp
 * \brief The FactoryWithAutoId class provides a generic factory which create its own id for each class as they are added to the factory.
 *
 * Unlike the basic Factory class, which requires the id to be passed along when you register a new class, the FactoryWithAutoId
 * generates one on its own via its Storage policy.
 */
template<	class AbstractProduct,
            class IdentifierType,
            template<class, class, class> class Storage = SimpleVectorStorage,
            class ProductCreator = std::function<AbstractProduct*()>,
            template<class, class> class FactoryErrorPolicy = DefaultFactoryErrorPolicy
            >
class FactoryWithAutoId :   public FactoryErrorPolicy<IdentifierType, AbstractProduct>,
                            protected Storage<IdentifierType, AbstractProduct, ProductCreator>,
                            protected Singleton<FactoryWithAutoId<AbstractProduct, IdentifierType, Storage, ProductCreator, FactoryErrorPolicy> >
{
public:
    typedef FactoryErrorPolicy<IdentifierType, AbstractProduct> error_policy;
    typedef Storage<IdentifierType, AbstractProduct, ProductCreator> storage_policy;
    friend class Singleton<FactoryWithAutoId>;

    static AbstractProduct* create(typename const_parameter_trait<IdentifierType>::type id)
    {
        FactoryWithAutoId& inst = FactoryWithAutoId::instance();
        std::size_t pos = storage_policy::pos2id(id);
        if(pos >= inst.m_containr.size()) return error_policy::onUnknownType(id);
        return inst.m_containr[pos]();
    }

    static IdentifierType registerProduct(ProductCreator creator)
    {
        FactoryWithAutoId& inst = FactoryWithAutoId::instance();
        std::size_t pos = inst.m_containr.size();
        assert(pos < AbstractProduct::nbMax);
        inst.m_containr.push_back(creator);
        IdentifierType res = storage_policy::pos2id(pos);
        return res;
    }

private:
    FactoryWithAutoId() = default;
};

END_NAMESPACE_UTILS

#endif // FACTORYWITHAUTOID_HPP
