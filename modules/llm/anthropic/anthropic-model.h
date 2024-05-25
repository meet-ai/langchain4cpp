#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_LANGUAGE_MODEL_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_LANGUAGE_MODEL_H_
// Copyright[2024] meetai.co@gmail.com

#include <stdlib.h>

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "llm/anthropic/anthropic-client.h"
#include "llm/anthropic/anthropic-resp.h"
#include "llm/anthropic/user-message.h"
#include "utils/meta.h"

using std::string;
using std::vector;

// Model -> Client -> Req/Resp
class AnthropicModelBuilder;
class AnthropicModel {
 public:
    string generate(const string &message) {
        auto ums = vector<UserMessage>{{"user", message}};
        auto respMessages = anthropic_client->Create(ums);
        return respMessages.size() > 0 ? respMessages[0].text : "";
    }
    TextContent generate(const UserMessage &message) {
        auto ums = vector<UserMessage>{message};
        auto textContents = anthropic_client->Create(ums);
        return textContents.size() > 0 ? std::move(textContents[0]) : TextContent{};
    }
    // vector<string> ListModels() { return vector<string>(); };

    // LlmMessage generate(const vector<UserMessage> &messages) { return std::move(LlmMessage{}); }

    friend class AnthropicModelBuilder;

 private:
    PROPERTY(string, api_key_, string(std::getenv("ANTHROPIC_API_KEY") ? std::getenv("ANTHROPIC_API_KEY") : ""))
    PROPERTY(string, model_name_, "claude-3-opus-20240229")
    PROPERTY(float, temperature, 0.9)
    PROPERTY(int, top_p, 10)
    PROPERTY(int, topk, 3)
    PROPERTY(int, max_tokens, 1024)
    PROPERTY(bool, stop_seq_, false)
    PROPERTY(bool, max_retries, 3)
    PROPERTY(std::shared_ptr<AnthropicClient>, anthropic_client, nullptr)
};
class AnthropicModelBuilder {
 public:
    BUILDER_WITH(AnthropicModelBuilder, string, anthropic_model_ptr, api_key_)
    BUILDER_WITH(AnthropicModelBuilder, string, anthropic_model_ptr, model_name_)
    BUILDER_WITH(AnthropicModelBuilder, int, anthropic_model_ptr, temperature)
    BUILDER_WITH(AnthropicModelBuilder, int, anthropic_model_ptr, top_p)
    BUILDER_WITH(AnthropicModelBuilder, int, anthropic_model_ptr, topk)
    BUILDER_WITH(AnthropicModelBuilder, int, anthropic_model_ptr, max_tokens)
    BUILDER_WITH(AnthropicModelBuilder, bool, anthropic_model_ptr, stop_seq_)
    BUILDER_WITH(AnthropicModelBuilder, int, anthropic_model_ptr, max_retries)
    BUILDER_WITH(AnthropicModelBuilder, shared_ptr<AnthropicClient>, anthropic_model_ptr, anthropic_client)
    std ::shared_ptr<AnthropicModel> build() { return anthropic_model_ptr; }

 private:
    std::shared_ptr<AnthropicModel> anthropic_model_ptr = std::make_shared<AnthropicModel>();
};

#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_LANGUAGE_MODEL_H_
