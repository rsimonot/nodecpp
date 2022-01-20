{
    "targets": [{
        "target_name": "nodecpp",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "cppsrc/main.cpp",
            "cppsrc/lib.cpp",
            "<!(find ~/ -name 'wiringPi.c')",
            "<!(find ~/ -name 'softPwm.c')",
            "<!(find ~/ -name 'softTone.c')",
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
