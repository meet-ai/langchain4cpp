#ifndef  CHATRESPONSE_H_
#define CHATRESPONSE_H_

#include <string>
#include "utils/meta.h"
using namespace std;

class ChatMessageResponse {
public:
    ChatMessageResponse() = default;            // 显式请求默认构造函数
    ChatMessageResponse(const ChatMessageResponse&) = default; // 显式请求拷贝构造函数
    ChatMessageResponse(ChatMessageResponse&&) = default;   // 显式请求移动构造函数
    ChatMessageResponse& operator=(const ChatMessageResponse&) = default; // 显式请求拷贝赋值运算符
    ChatMessageResponse& operator=(ChatMessageResponse&&) = default; // 显式请求移动赋值运算符
    ~ChatMessageResponse() = default;           // 显式请求析构函数

private:
   PROPERTY(int,value_,0)

};

class ChatMessageResponseBuilder{
public:
    ChatMessageResponseBuilder() = default;            // 显式请求默认构造函数
    ChatMessageResponseBuilder(const ChatMessageResponseBuilder&) = default; // 显式请求拷贝构造函数
    ChatMessageResponseBuilder(ChatMessageResponseBuilder&&) = default;   // 显式请求移动构造函数
    ChatMessageResponseBuilder& operator=(const ChatMessageResponseBuilder&) = default; // 显式请求拷贝赋值运算符
    ChatMessageResponseBuilder& operator=(ChatMessageResponseBuilder&&) = default; // 显式请求移动赋值运算符
    ~ChatMessageResponseBuilder() = default;           // 显式请求析构函数

private:

};

#endif // CHATRESPONSE_H_
