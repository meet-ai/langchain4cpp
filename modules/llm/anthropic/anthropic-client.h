// Copyright[2024] meetai.co@gmail.com
#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_

#include <memory>
#include <string>
#include <vector>
#include <cpp20_http_client.hpp>

#include <rfl.hpp>
#include <rfl/json.hpp>

#include "llm/anthropic/user-message.h"
#include "llm/anthropic/anthropic-req.h"
#include "utils/meta.h"

using string = std::string;

class AnthropicClientBuilder;
class AnthropicClient {
 public:
    friend class AnthropicClientBuilder;

 public:
    UserMessage Create(const std::vector<UserMessage>& user_messages) {

        AnthropicReq req{.model=model,.max_tokens=1024,.messages=std::move(user_messages)};

        auto body = rfl::json::write(req);

         auto const response = http_client::post(base_url)
        .add_header({.name="Content-Type", .value="application/json"})
        .add_header({.name="anthropic-version", .value="2023-06-01"})
        .add_header({.name="x-api-key", .value=api_key})
        .set_body(body)
        .send();
    }
    UserMessage Create(const std::vector<UserMessage>& user_message,int max_tokens, const string& model_name) {}
    //UserMessage Create(const string& user_message) {}

 private:
    string base_url = "https://api.anthropic.com/v1/";
    string model = "";
    string api_key = "";
    string version = "2023-06-01";
    string beta = "tools-2024-04-04";
    int timeout = 60;
    bool log_requests = false;
    bool log_responses = false;
};

class AnthropicClientBuilder {
 public:
    BUILDER_WITH(AnthropicClientBuilder, string, client, base_url)
    BUILDER_WITH(AnthropicClientBuilder, string, client, api_key)
    BUILDER_WITH(AnthropicClientBuilder, string, client, version)
    BUILDER_WITH(AnthropicClientBuilder, string, client, beta)
    BUILDER_WITH(AnthropicClientBuilder, int, client, timeout)
    BUILDER_WITH(AnthropicClientBuilder, bool, client, log_requests)
    BUILDER_WITH(AnthropicClientBuilder, bool, client, log_responses)
    std ::shared_ptr<AnthropicClient> build() { return client; }

 private:
    std::shared_ptr<AnthropicClient> client = std::make_shared<AnthropicClient>();
};
#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_
