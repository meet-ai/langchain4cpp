// Copyright[2024] meetai.co@gmail.com
#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_

#include <memory>
#include <string>
#include <vector>

#include "llm/anthropic/user-message.h"
#include "utils/meta.h"

using string = std::string;
class AnthropicClient {
 public:
    AnthropicClient() = default;                                   // 显式请求默认构造函数
    AnthropicClient(const AnthropicClient&) = default;             // 显式请求拷贝构造函数
    AnthropicClient(AnthropicClient&&) = default;                  // 显式请求移动构造函数
    AnthropicClient& operator=(const AnthropicClient&) = default;  // 显式请求拷贝赋值运算符
    AnthropicClient& operator=(AnthropicClient&&) = default;       // 显式请求移动赋值运算符
    ~AnthropicClient() = default;                                  // 显式请求析构函数

 public:
    void SendMessage(const std::vector<UserMessage>& user_message) {}
    void SendMessage(const UserMessage& user_message) {}
    void SendMessage(const string& user_message) {}

 private:
    PROPERTY(string, base_url, "https://api.anthropic.com/v1/")
    PROPERTY(string, api_key, "")
    PROPERTY(string, version, "2023-06-01")
    PROPERTY(string, beta, "tools-2024-04-04")
    PROPERTY(int, timeout, 60)
    PROPERTY(bool, log_requests, false)
    PROPERTY(bool, log_responses, false)
};

class AnthropicClientBuilder {
 public:
    AnthropicClientBuilder() = default;                                          // 显式请求默认构造函数
    AnthropicClientBuilder(const AnthropicClientBuilder&) = default;             // 显式请求拷贝构造函数
    AnthropicClientBuilder(AnthropicClientBuilder&&) = default;                  // 显式请求移动构造函数
    AnthropicClientBuilder& operator=(const AnthropicClientBuilder&) = default;  // 显式请求拷贝赋值运算符
    AnthropicClientBuilder& operator=(AnthropicClientBuilder&&) = default;       // 显式请求移动赋值运算符
    ~AnthropicClientBuilder() = default;                                         // 显式请求析构函数

 private:
    std::shared_ptr<AnthropicClient> client = std::make_shared<AnthropicClient>();

 public:
    AnthropicClientBuilder& baseUrl(const string& url) {
        client->set_base_url(url);
        return (*this);
    }
    AnthropicClientBuilder& apiKey(const string& api_key) {
        client->set_api_key(api_key);
        return (*this);
    }
    AnthropicClientBuilder& version(const string& version) {
        client->set_version(version);
        return (*this);
    }
    AnthropicClientBuilder& beta(const string& beta) {
        client->set_beta(beta);
        return (*this);
    }
    AnthropicClientBuilder& timeout(int timeout) {
        client->set_timeout(timeout);
        return (*this);
    }
    AnthropicClientBuilder& log_requests(bool log_req) {
        client->set_log_requests(log_req);
        return (*this);
    }
    AnthropicClientBuilder& log_response(bool log_resp) {
        client->set_log_responses(log_resp);
        return (*this);
    }
    std ::shared_ptr<AnthropicClient> build() { return client; }
};
#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_
