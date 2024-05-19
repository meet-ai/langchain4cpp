module;
#include <iostream>
#include <Poco/StringTokenizer.h>
#include <Poco/String.h>

#include <memory>
#include <iostream>
#include <string>
#include <string>
#include <rfl.hpp>
#include <rfl/toml.hpp>
#include <Poco/File.h>
#include <Poco/FileStream.h>
using namespace std;
export module config;  // 为模块 "foo" 声明主模块接口单元

// 若编译器支持模块化的 stl 库，则可以删除以上所有代码，使用 import 语法引入 stl 库。
// import 具体语句可能取决于未来编译器和 stl 库的实现，可能的写法是：
// ```
// import <iostream>;
// ```


// 对模块外部**不可见**的函数声明与实现
//void FooFuncInternal() { std::cout << "Foo!" << std::endl; }
//
//// 对模块外部可见的函数声明与实现，通过 export 修饰
//export void FooFunc() { FooFuncInternal(); }

struct ServerBlock {
    string http_endpoint;
};

struct Log {
    string log_level;
};

struct TomlConfig {
    ServerBlock server_block;
    Log log;
};
export shared_ptr<TomlConfig> ParseConfig(const string &path) {
    Poco::FileInputStream fis(path); // 替换为实际文件路径
    std::string content((std::istreambuf_iterator<char>(fis)), std::istreambuf_iterator<char>());
    cout << content << std::endl;
    auto tConfig = rfl::toml::read<TomlConfig>(content).value();
    return make_shared<TomlConfig>(tConfig);
    //cout << tConfig.sb.httpEndpoint << endl;
}
export shared_ptr<TomlConfig> globalConfig;
