#include "aeon/aeon.h"
#include "aeon/resources/resource.h"
#include "aeon/resources/resourcemanager.h"
#include "aeon/console/console.h"

namespace aeon
{

resource::resource(resource_manager *creator, const std::string &name, 
    std::uint64_t handle)
:
creator_(creator),
name_(name),
handle_(handle),
state_(state::empty)
{

}

resource::~resource()
{

}

bool resource::__load(stream_ptr stream)
{
    if (state_ != state::empty)
    {
        console::warning("[Resource]: Load called on resource while in wrong "
            "state: %u", (int) state_.load());
        return false;
    }

    bool result = __load_impl(stream);

    if(result)
        state_ = state::ready_for_finalize;

    return result;
}

bool resource::__unload()
{
    if(state_ != state::loaded)
    {
        console::warning("[Resource]: Unload called on resource while in "
            "wrong state: %u", (int) state_.load());
        return false;
    }

    state_ = state::unloading;
    return true;
}

bool resource::__finalize()
{
    if (state_ != state::ready_for_finalize)
    {
        console::warning("[Resource]: Finalize called on resource while in "
            "wrong state: %u", (int) state_.load());
        return false;
    }

    bool result = __finalize_impl();

    if(result)
        state_ = state::loaded;

    return result;
}

} //namespace aeon
