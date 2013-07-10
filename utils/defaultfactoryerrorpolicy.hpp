#ifndef __DEFAULTFACTORYERRORPOLICY__
#define __DEFAULTFACTORYERRORPOLICY__

#include <utils/parametertrait.hpp>

#include <stdexcept>

BEGIN_NAMESPACE_UTILS

template<class IdentifierType, class ProductType> class DefaultFactoryErrorPolicy
{
public:
	class Exception : public std::exception
	{
	public:
        Exception(typename parameter_trait<IdentifierType>::const_reference id) : std::exception(), m_unknownId(id)
		{}
		
		virtual const char* what()
		{
			return "Type inconnu passé à la factory.";
		}
		
        typename parameter_trait<IdentifierType>::const_reference getId() const
		{
			return m_unknownId;
		}
		
	private:
		IdentifierType m_unknownId;
	};
	
protected:
    static ProductType* onUnknownType(typename parameter_trait<IdentifierType>::const_reference id)
	{
		throw Exception(id);
	}
};

END_NAMESPACE_UTILS

#endif
