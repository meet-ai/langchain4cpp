package("main")
    set_kind("binary")
    set_description("The main package")
    add_deps("strutil")
    add_deps("cli11")
    add_deps("spdlog")
    add_deps("conan::poco/1.13.3", {configs={settings="compiler.cppstd=20"}})
    add_deps("toml++")
    add_deps("conan::matchit/1.0.1", {configs={settings="compiler.cppstd=20"}})

    add_urls("https://github.com/myrepo/foo.git")
    add_versions("1.0", "<shasum256 or gitcommit>")

    on_install(function (package)
        local configs = {}
        if package:config("shared") then
            configs.kind = "shared"
        end
        import("package.tools.xmake").install(package, configs)
    end)

    on_test(function (package)
        -- TODO check includes and interfaces
        -- assert(package:has_cfuncs("foo", {includes = "foo.h"})
    end)
