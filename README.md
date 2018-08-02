# Node.js Android lib

This repo lets you build `libnode.so` for Android (`arm64`).

You only need this if you want to build an Android app that runs a true native `node` via the Java Native Interface, and you know what you're doing.

If you just want to use `node` on your Android, get it on `Termux`. If you just want to run some JS, use `WebView`.

## Instructions

1. Get an Android `arm64` device. I use a Pixel.
1. Get [Termux](https://termux.com/).
1. Get a shell into Termux.
1. `git clone` this repo
1. `cd` into this repo
1. Run:

```sh
./configure --shared
LDFLAGS="-llog" make -j2 # this will take like an hour
file ./out/Release/lib.target/libnode.so.59 # this is your output library; copy it somewhere

g++ node.cpp -std=c++14 -L./out/Release/lib.target -l:libnode.so.59 -I. -I./deps/v8/include -I./deps/uv/include -o ./out/Release/node.so # build node binary stub
LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$(pwd)/out/Release/obj.target" ./out/Release/node.so # start node

patchelf --replace-needed libnode.so.59 libnode.so ./out/Release/node.so # need this if libnode soname is changed
readelf -d ./out/Release/node.so # list soname dependencies
```

Mostly this repo has some light hacks that made the node build compatible with the Android native toolchain.