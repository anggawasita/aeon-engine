#include "stdafx.h"

namespace aeon
{

aeon_initialize_singleton(aeon::model_codec_manager);

model_codec_manager::model_codec_manager()
{

}

model_codec_manager::~model_codec_manager()
{

}

void model_codec_manager::register_codec(model_codec_ptr codec)
{
    if (!codec)
        return;

    const std::string &name = codec->get_type_name();
    registered_codecs_[name] = codec;
}

model_ptr model_codec_manager::decode(const std::string &name,
                                      stream_ptr stream)
{
    auto codec = registered_codecs_.find(name);

    // Could not find the codec?
    if (codec == registered_codecs_.end())
    {
        console::error("ModelCodecManager: Could not decode stream. "
            "Unknown decoder: '%s'", name.c_str());
        return nullptr;
    }

    return codec->second->decode(stream);
}

} /* namespace aeon */
