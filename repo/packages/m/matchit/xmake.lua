package("matchit")
    add_deps("cmake")

    add_urls("https://github.com/BowenFu/matchit.cpp.git")
    add_versions("v1.0.0","v1.0.0")


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
