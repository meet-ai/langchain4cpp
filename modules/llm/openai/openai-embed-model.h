#ifndef OPENAI_EMBED_MODEL
#define OPENAI_EMBED_MODEL

// Copyright[2024] meetai.co@gmail.com

#include <stdlib.h>

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "llm/embedding.h"
#include "llm/openai/openai-embed-client.h"
#include "utils/meta.h"

using std::string;
using std::vector;

// Model -> Client -> Req/Resp
class OpenAIEmbedModelBuilder;
class OpenAiEmbedModel {
 public:
    TextEmbedding embedText(string text) { return openai_client->embed(vector<string>{text}); }
    // vector<string> ListModels() { return vector<string>(); };

    // LlmMessage generate(const vector<UserMessage> &messages) { return std::move(LlmMessage{}); }

    friend class OpenAIEmbedModelBuilder;

 private:
    PROPERTY(string, api_key_, string(std::getenv("OPENAI_API_KEY") ? std::getenv("OPENAI_API_KEY") : ""))
    PROPERTY(string, model_name_, "text-embedding-3-small")
    PROPERTY(bool, max_retries, 3)
    PROPERTY(std::shared_ptr<OpenAiEmbedClient>, openai_client, nullptr)
};
class OpenAIEmbedModelBuilder {
 public:
    BUILDER_WITH(OpenAIEmbedModelBuilder, string, openai_embed_model_ptr, api_key_)
    BUILDER_WITH(OpenAIEmbedModelBuilder, string, openai_embed_model_ptr, model_name_)
    BUILDER_WITH(OpenAIEmbedModelBuilder, int, openai_embed_model_ptr, max_retries)
    BUILDER_WITH(OpenAIEmbedModelBuilder, shared_ptr<OpenAiEmbedClient>, openai_embed_model_ptr, openai_client)
    std ::shared_ptr<OpenAiEmbedModel> build() { return openai_embed_model_ptr; }

 private:
    std::shared_ptr<OpenAiEmbedModel> openai_embed_model_ptr = std::make_shared<OpenAiEmbedModel>();
};
#endif