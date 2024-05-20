#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_LANGUAGE_MODEL_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_LANGUAGE_MODEL_H_
// Copyright[2024] meetai.co@gmail.com

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "llm/anthropic/anthropic-client.h"
#include "llm/anthropic/llm-message.h"
#include "llm/anthropic/user-message.h"
#include "utils/meta.h"

using std::string;
using std::vector;

// Model -> Client -> Req/Resp
class ChatLanguageModelBuilder;
class ChatLanguageModel {
 public:
    LlmMessage generate(const string &messages) { return std::move(LlmMessage{}); }
    LlmMessage generate(const UserMessage &message) { return std::move(LlmMessage{}); }
    // LlmMessage generate(const vector<UserMessage> &messages) { return std::move(LlmMessage{}); }

    friend class ChatLanguageModelBuilder;

 private:
    PROPERTY(string, api_key_, "")
    PROPERTY(string, model_name_, "")
    PROPERTY(float, temperature, 0.9)
    PROPERTY(int, top_p, 10)
    PROPERTY(int, topk, 3)
    PROPERTY(int, max_tokens, 1024)
    PROPERTY(bool, stop_seq_, false)
    PROPERTY(bool, max_retries, 3)
    PROPERTY(std::shared_ptr<AnthropicClient>, anthropic_client, nullptr)
};
class ChatLanguageModelBuilder {
 public:
    BUILDER_WITH(ChatLanguageModelBuilder, string, sp_chat_language_model, api_key_)
    BUILDER_WITH(ChatLanguageModelBuilder, string, sp_chat_language_model, model_name_)
    BUILDER_WITH(ChatLanguageModelBuilder, int, sp_chat_language_model, temperature)
    BUILDER_WITH(ChatLanguageModelBuilder, int, sp_chat_language_model, top_p)
    BUILDER_WITH(ChatLanguageModelBuilder, int, sp_chat_language_model, topk)
    BUILDER_WITH(ChatLanguageModelBuilder, int, sp_chat_language_model, max_tokens)
    BUILDER_WITH(ChatLanguageModelBuilder, bool, sp_chat_language_model, stop_seq_)
    BUILDER_WITH(ChatLanguageModelBuilder, int, sp_chat_language_model, max_retries)
    std ::shared_ptr<ChatLanguageModel> build() { return sp_chat_language_model; }

 private:
    std::shared_ptr<ChatLanguageModel> sp_chat_language_model = std::make_shared<ChatLanguageModel>();
};

#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_LANGUAGE_MODEL_H_
