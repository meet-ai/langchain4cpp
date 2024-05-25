// Copyright[2024] meetai.co@gmail.com
#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_CLIENT_H_

#include <cpr/cpr.h>
#include <spdlog/spdlog.h>

#include <iostream>
#include <memory>
#include <rfl.hpp>
#include <rfl/json.hpp>
#include <sstream>
#include <string>
#include <vector>

#include "llm/anthropic/anthropic-req.h"
#include "llm/anthropic/anthropic-resp.h"
#include "llm/anthropic/message-content.h"
#include "llm/anthropic/user-message.h"
#include "utils/meta.h"

using string = std::string;

class AnthropicClientBuilder;
using namespace cpr;
class AnthropicClient {
 public:
    friend class AnthropicClientBuilder;

 public:
    vector<MessageContent> Create(const std::vector<UserMessage>& user_messages) {
        AnthropicReq req{.model = model, .max_tokens = 1024, .messages = std::move(user_messages)};

        auto body = rfl::json::write(req);
        spdlog::info("messages req:{}", body);
        cpr::Response r = cpr::Post(
            cpr::Url{base_url + "/messages"}, cpr::Body(body),
            cpr::Header{
                {"Content-Type", "application/json"}, {"x-api-key", api_key}, {"anthropic-version", "2023-06-01"}});
        if (r.error) {
            if (r.error.code == cpr::ErrorCode::OPERATION_TIMEDOUT) {
                spdlog::error("request timeout");
            } else {
                spdlog::error("request failed with error:{}", r.error.message);
            }
        }
        if (r.status_code != 200) {
            spdlog::error("request failed with status code:{}", r.status_code);
        }
        spdlog::info("messages response:{}", r.text);
        auto resp = rfl::json::read<AnthropicResp>(r.text).value();
        return resp.content;
    }

    //UserMessage Create(const std::vector<UserMessage>& user_message, int max_tokens, const string& model_name) {}
    // UserMessage Create(const string& user_message) {}

 private:
    string base_url = "https://api.anthropic.com/v1";
    string model = "claude-3-opus-20240229";
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
