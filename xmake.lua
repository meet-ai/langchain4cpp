add_rules("mode.debug", "mode.release")
--------------------------------------------------------
add_cxxflags("-std=c++20")
set_policy("build.c++.modules", true)


add_repositories("local-repo repo")

add_requires("gtest")
add_requires("gflags")
add_requires("conan::poco/1.13.3",{alias = "poco",configs = {settings = "compiler.cppstd=20"}})
add_requires("conan::matchit/1.0.1",{alias = "matchit",configs = {settings = "compiler.cppstd=20"}})
add_requires("conan::pfr/2.2.0",{alias="pfr",configs={settings="compiler.cppstd=20"}})

add_requires("spdlog")
add_requires("toml++")
add_requires("cli11")
add_requires("boost_ut")
add_requires("reflect-cpp")
add_requires("outcome")

--add_requires("prometheus")
--
--
----------------------------private packages
--
--
--
--
--
--
target("strutil")
    set_kind("moduleonly")
    add_packages("poco")
    add_files("modules/strutil.ixx")

target("strutil")
    set_kind("moduleonly")
    add_packages("poco")
    add_files("modules/strutil.ixx")

----------------------------
target("main")
    add_deps("strutil")

    add_packages("cli11")
    add_packages("spdlog")
    add_packages("poco")
    add_packages("boost_di")
    add_packages("cista")
    add_packages("toml++")
    add_packages("reflect-cpp")
    add_packages("matchit")
    add_packages("poco")

    add_includedirs("modules")
    add_files("src/cmd/main.cpp")
    add_files("modules/llm/anthropic/*.cpp")
    add_includedirs("src")
    set_kind("binary")
    --add_files("src/config/*.cpp")

target("ut")
    add_deps("strutil")

    add_packages("cli11")
    add_packages("spdlog")
    add_packages("poco")
    add_packages("boost_di")
    add_packages("cista")
    add_packages("toml++")
    add_packages("reflect-cpp")
    add_packages("matchit")
    add_packages("poco")
    add_packages("boost_ut")
    add_packages("outcome")
    add_packages("pfr")

    add_includedirs("src")
    add_includedirs("modules")
    add_files("src/cmd/ut.cpp")
    add_files("modules/llm/anthropic/*.cpp")
    set_kind("binary")
