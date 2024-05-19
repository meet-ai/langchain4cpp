package("userver")
    add_deps("cmake")
    add_deps("boost")

    add_urls("https://github.com/userver-framework/userver.git")
    add_versions("v2.0","v2.0")

    on_install(function (package)
        local configs = {}
        if package:config("shared") then
            configs.kind = "shared"
        end
        import("package.tools.cmake").install(package, configs)
    end)

    on_test(function (package)
        -- TODO check includes and interfaces
        -- assert(package:has_cfuncs("foo", {includes = "foo.h"})
    end)
