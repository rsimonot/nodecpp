#include <napi.h>
#include "lib.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  exports.Set(
    "ledblink",
    Napi::Function::New(env, ledBlink)
  );
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)