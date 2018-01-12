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
```

Mostly this repo has some light hacks that made the node build compatible with the Android native toolchain.
