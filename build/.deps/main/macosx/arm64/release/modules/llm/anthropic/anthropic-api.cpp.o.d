{
    depfiles_gcc = "build/.objs/main/macosx/arm64/release/modules/llm/anthropic/anthropic-api.cpp.o:   modules/llm/anthropic/anthropic-api.cpp   modules/llm/anthropic/anthropic-api.h   modules/llm/anthropic/chat-request.h modules/utils/meta.h   modules/llm/anthropic/chat-response.h\
",
    values = {
        "/opt/homebrew/opt/llvm/bin/clang",
        {
            "-Qunused-arguments",
            "-isysroot",
            "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-Imodules",
            "-Isrc",
            "-DPOCO_STATIC=ON",
            "-DPOCO_UNBUNDLED",
            "-DPCRE2_STATIC",
            "-DXML_STATIC",
            "-DBOOST_UT_DISABLE_MODULE",
            "-isystem",
            "/Users/meetai/.xmake/packages/c/cli11/v2.4.1/8b96b195229b4c28937091b624092663/include",
            "-isystem",
            "/Users/meetai/.xmake/packages/s/spdlog/v1.14.1/1e1f4c01d19643f6ad631fed432ecb5e/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/poco744d1943c5754/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/pcre2636bd3eb76a88/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/bzip2b6bf407195be9/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/expatfe0587454985f/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/sqlita112ff224b68b/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/libpq27cb0af70a7f5/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/libmy619e1a3483e83/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/libmy619e1a3483e83/p/include/mysql",
            "-isystem",
            "/Users/meetai/.conan2/p/b/opens4f133d87dbaa8/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/zlib884cf424d1015/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/zstdbc9074843771b/p/include",
            "-isystem",
            "/Users/meetai/.conan2/p/b/lz44cdfffebf3614/p/include",
            "-isystem",
            "/Users/meetai/.xmake/packages/t/toml++/v3.4.0/f81af7dfe6dd430d888b6aae5b3e17cc/include",
            "-isystem",
            "/Users/meetai/.xmake/packages/r/reflect-cpp/@default/4dbd676f60274c039cd8bc439ce0e961/include",
            "-isystem",
            "/Users/meetai/.conan2/p/match7103f0dee9f29/p/include",
            "-isystem",
            "/Users/meetai/.xmake/packages/b/boost_ut/v2.0.1/5a4ea961591d475a83072de0ceee9f96/include",
            "-isystem",
            "/Users/meetai/.conan2/p/pfre7dfd128145d1/p/include",
            "-std=c++20",
            "-fno-delayed-template-parsing",
            "-DNDEBUG"
        }
    },
    files = {
        "modules/llm/anthropic/anthropic-api.cpp"
    }
}