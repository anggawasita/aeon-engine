/*
 * ROBIN DEGEN; CONFIDENTIAL
 *
 * 2012 - 2015 Robin Degen
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

#ifndef streamlistener_h__
#define streamlistener_h__

namespace aeon
{

class console_stream_listener : public console::listener
{
public:
    console_stream_listener(aeon::streams::stream_ptr stream);
    ~console_stream_listener();

    void on_log_message(double time_diff, console::log_level level,
                        const std::string &message);

private:
    aeon::streams::stream_ptr stream_;
};

} // namespace aeon

#endif // streamlistener_h__