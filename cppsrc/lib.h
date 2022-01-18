#include <wiringPi.h>
#include <stdio.h>
#include <string>
#include <napi.h>

namespace led
{
    std::string ledBlink();
    Napi::String ledWrapped(const Napi::CallbackInfo& info);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
}