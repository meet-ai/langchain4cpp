//use clang toolchain:xmake f --toolchain=llvm --sdk=/opt/homebrew/opt/llvm/
module;
#include <iostream>
//#include <Poco/StringTokenizer.h>
//#include <Poco/String.h>

#include <memory>
#include <iostream>
#include <string>
using namespace std;
export module strutil;  // 为模块 "foo" 声明主模块接口单元

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


export shared_ptr<vector<string>> split(const string&data, string sep) {
    Poco::StringTokenizer tokenizer(data, sep);
    auto vec = std::vector<string>(tokenizer.begin(), tokenizer.end());
    return make_shared<vector<string>>(vec);
}

export string join (const std::vector<std::string>& strings, const std::string& separator) {
    std::string result;
    if (!strings.empty()) {
        result += strings[0];
        for (size_t i = 1; i < strings.size(); ++i) {
            result += separator + strings[i];
        }
    }
    return result;
}
export std::string replace(const std::string& source, 
                    const std::string& from, 
                    const std::string& to) {
    std::string result = source;
    Poco::replaceInPlace(result, from, to);
    return result;
}
