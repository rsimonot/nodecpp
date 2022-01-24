{
    "targets": [{
        "target_name": "nodecpp",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "cppsrc/main.cpp",
            "cppsrc/lib.cpp",
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
            "include"
        ],
        'libraries': [
            "<!(pwd)/include/wiringPi.a"
        ],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
