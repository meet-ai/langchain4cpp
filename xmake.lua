add_rules("mode.debug", "mode.release")
--------------------------------------------------------
add_cxxflags("-std=c++20")
set_policy("build.c++.modules", true)

if is_mode("debug") then
    add_cxxflags("-fsanitize=address")
    add_ldflags("-fsanitize=address")
end

add_repositories("local-repo repo")
add_requires("gtest")
add_requires("gflags")
add_requires("cpptrace")
add_requires("conan::poco/1.13.3", { alias = "poco", configs = { settings = "compiler.cppstd=20" } })
add_requires("conan::matchit/1.0.1", { alias = "matchit", configs = { settings = "compiler.cppstd=20" } })
add_requires("conan::pfr/2.2.0", { alias = "pfr", configs = { settings = "compiler.cppstd=20" } })

add_requires("spdlog")
add_requires("cpr")
add_requires("toml++")
add_requires("cli11")
add_requires("reflect-cpp")
--add_requires("prometheus")
--
--
----------------------------private packages

----------------------------
target("modules")
    add_packages("cpr")
    add_packages("spdlog")
    --add_packages("poco")
    add_packages("cpp20-http-client")
    add_packages("reflect-cpp")
    add_includedirs("modules")
    add_files("modules/llm/anthropic/*.cpp")
    set_kind("static")

----------------------------
target("main")
add_deps("modules")

add_packages("cli11")
add_packages("spdlog")
add_packages("toml++")
add_packages("reflect-cpp")
add_packages("matchit")

add_includedirs("modules")
add_includedirs("src")
add_files("src/cmd/main.cpp")
set_kind("binary")
--add_files("src/config/*.cpp")

----------------------------
target("ut")
    add_deps("modules")
    add_packages("spdlog")
    add_packages("cpptrace")
    add_packages("reflect-cpp")
    add_packages("toml++")
    add_packages("cpr")
    add_packages("gtest")
    add_includedirs("modules")
    add_files("tests/modules/llm/anthropic/test-anthropic.cpp")
    add_cxxflags("-fsanitize=address")
    add_ldflags("-fsanitize=address")
    set_kind("binary")

target("ut-openai")
    add_deps("modules")
    add_packages("spdlog")
    add_packages("cpptrace")
    add_packages("reflect-cpp")
    add_packages("toml++")
    add_packages("cpr")
    add_packages("gtest")
    add_includedirs("modules")
    add_files("tests/modules/llm/anthropic/test-openai.cpp")
    add_cxxflags("-fsanitize=address")
    add_ldflags("-fsanitize=address")
    set_kind("binary")
