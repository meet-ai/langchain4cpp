#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_REQUEST_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_REQUEST_H_
// Copyright[2024] meetai.co@gmail.com

#include <memory>
#include <string>

#include "utils/meta.h"
namespace anthropic_api {

class ChatMessageRequest {
 public:
    ChatMessageRequest() = default;                                      // 显式请求默认构造函数
    ChatMessageRequest(const ChatMessageRequest&) = default;             // 显式请求拷贝构造函数
    ChatMessageRequest(ChatMessageRequest&&) = default;                  // 显式请求移动构造函数
    ChatMessageRequest& operator=(const ChatMessageRequest&) = default;  // 显式请求拷贝赋值运算符
    ChatMessageRequest& operator=(ChatMessageRequest&&) = default;       // 显式请求移动赋值运算符
    ~ChatMessageRequest() = default;                                     // 显式请求析构函数

 private:
    PROPERTY(int, value_, 0)
};

class ChatMessageRequestBuilder {
 public:
    ChatMessageRequestBuilder() = default;                                             // 显式请求默认构造函数
    ChatMessageRequestBuilder(const ChatMessageRequestBuilder&) = default;             // 显式请求拷贝构造函数
    ChatMessageRequestBuilder(ChatMessageRequestBuilder&&) = default;                  // 显式请求移动构造函数
    ChatMessageRequestBuilder& operator=(const ChatMessageRequestBuilder&) = default;  // 显式请求拷贝赋值运算符
    ChatMessageRequestBuilder& operator=(ChatMessageRequestBuilder&&) = default;       // 显式请求移动赋值运算符
    ~ChatMessageRequestBuilder() = default;                                            // 显式请求析构函数

 private:
    std::shared_ptr<ChatMessageRequest> sp_chat_message_req = std::make_shared<ChatMessageRequest>();
};

}  // namespace anthropic_api

#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_REQUEST_H_
