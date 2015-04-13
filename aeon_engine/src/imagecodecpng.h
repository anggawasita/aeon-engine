/*
 * ROBIN DEGEN; CONFIDENTIAL
 *
 * 2012 - 2014 Robin Degen
 * All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains the property of
 * Robin Degen and its suppliers, if any. The intellectual and technical
 * concepts contained herein are proprietary to Robin Degen and its suppliers
 * and may be covered by U.S. and Foreign Patents, patents in process, and are
 * protected by trade secret or copyright law. Dissemination of this
 * information or reproduction of this material is strictly forbidden unless
 * prior written permission is obtained from Robin Degen.
 */

#ifndef imagecodecpng_h__
#define imagecodecpng_h__

namespace aeon
{

class image_codec_png : public image_codec
{
public:
    image_codec_png();
    virtual ~image_codec_png();

    virtual image_ptr decode(stream_ptr stream);
    virtual std::string get_type_name() const;    
};

} /* namespace aeon */

#endif /* imagecodecpng_h__ */