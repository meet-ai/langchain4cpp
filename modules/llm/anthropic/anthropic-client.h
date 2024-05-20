// Copyright[2024] meetai.co@gmail.com
#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_

#include <memory>
#include <string>
#include <vector>

#include "llm/anthropic/user-message.h"
#include "utils/meta.h"

using string = std::string;

class AnthropicClientBuilder;
class AnthropicClient {
 public:
    friend class AnthropicClientBuilder;

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
 private:
    std::shared_ptr<AnthropicClient> client = std::make_shared<AnthropicClient>();

 public:
    BUILDER_WITH(AnthropicClientBuilder, string, client, base_url)
    BUILDER_WITH(AnthropicClientBuilder, string, client, api_key)
    BUILDER_WITH(AnthropicClientBuilder, string, client, version)
    BUILDER_WITH(AnthropicClientBuilder, string, client, beta)
    BUILDER_WITH(AnthropicClientBuilder, int, client, timeout)
    BUILDER_WITH(AnthropicClientBuilder, bool, client, log_requests)
    BUILDER_WITH(AnthropicClientBuilder, bool, client, log_responses)
    std ::shared_ptr<AnthropicClient> build() { return client; }
};
#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_
