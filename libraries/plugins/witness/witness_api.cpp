
#include <fc/filesystem.hpp>
#include <fc/optional.hpp>
#include <fc/variant_object.hpp>
#include <fc/smart_ref_impl.hpp>

#include <graphene/app/application.hpp>

#include <graphene/chain/block_database.hpp>
#include <graphene/chain/database.hpp>
#include <graphene/chain/witness_object.hpp>

#include <graphene/utilities/key_conversion.hpp>

#include <graphene/witness/witness.hpp>
#include <graphene/witness/witness_api.hpp>

namespace graphene { namespace witness {

namespace detail {

class witness_api_impl
{
   public:
      witness_api_impl( graphene::app::application& _app );

      void set_private_keys( const std::vector<std::string>& keys );
      void clear_private_keys();
      std::shared_ptr< graphene::witness_plugin::witness_plugin > get_plugin();

      graphene::app::application& app;
};

witness_api_impl::witness_api_impl( graphene::app::application& _app ) : app( _app )
{}


void witness_api_impl::set_private_keys( const std::vector<std::string>& keys )
{
   ilog("private keys set");
}

void witness_api_impl::clear_private_keys()
{
   ilog("private keys cleared");
}

std::shared_ptr< graphene::witness_plugin::witness_plugin > witness_api_impl::get_plugin()
{
   return app.get_plugin< graphene::witness_plugin::witness_plugin >( "witness" );
}

} // detail

witness_api::witness_api( graphene::app::application& app )
{
   my = std::make_shared< detail::witness_api_impl >(app);
}

void witness_api::set_private_keys( const std::vector<std::string>& keys )
{
   my->set_private_keys(keys);
}

void witness_api::clear_private_keys()
{
   my->clear_private_keys();
}



} } // graphene::witness
