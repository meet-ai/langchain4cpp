#ifndef OPENAI_EMBED_MODEL
#define OPENAI_EMBED_MODEL

// Copyright[2024] meetai.co@gmail.com

#include <stdlib.h>

#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "llm/embedding.h"
#include "llm/openai/openai-client.h"
#include "utils/meta.h"

using std::string;
using std::vector;

// Model -> Client -> Req/Resp
class OpenAIEmbedModelBuilder;
class OpenAIEmbedModel {
 public:
    vector<TextEmbedding> embedTexts(const vector<string> texts) {
        //        auto ums = vector<UserMessage>{message};
        //        auto textContents = openai_client->Create(ums);
        //        return textContents.size() > 0 ? std::move(textContents[0]) : TextContent{};
    }
    // vector<string> ListModels() { return vector<string>(); };

    // LlmMessage generate(const vector<UserMessage> &messages) { return std::move(LlmMessage{}); }

    friend class OpenAIEmbedModelBuilder;

 private:
    PROPERTY(string, api_key_, string(std::getenv("OPENAI_API_KEY") ? std::getenv("OPENAI_API_KEY") : ""))
    PROPERTY(string, model_name_, "text-embedding-3-small")
    PROPERTY(float, temperature, 0.9)
    PROPERTY(int, top_p, 10)
    PROPERTY(int, topk, 3)
    PROPERTY(int, max_tokens, 1024)
    PROPERTY(bool, stop_seq_, false)
    PROPERTY(bool, max_retries, 3)
    PROPERTY(std::shared_ptr<OpenAIClient>, openai_client, nullptr)
};
class OpenAIEmbedModelBuilder {
 public:
    BUILDER_WITH(OpenAIEmbedModelBuilder, string, openai_embed_model_ptr, api_key_)
    BUILDER_WITH(OpenAIEmbedModelBuilder, string, openai_embed_model_ptr, model_name_)
    BUILDER_WITH(OpenAIEmbedModelBuilder, int, openai_embed_model_ptr, temperature)
    BUILDER_WITH(OpenAIEmbedModelBuilder, int, openai_embed_model_ptr, top_p)
    BUILDER_WITH(OpenAIEmbedModelBuilder, int, openai_embed_model_ptr, topk)
    BUILDER_WITH(OpenAIEmbedModelBuilder, int, openai_embed_model_ptr, max_tokens)
    BUILDER_WITH(OpenAIEmbedModelBuilder, bool, openai_embed_model_ptr, stop_seq_)
    BUILDER_WITH(OpenAIEmbedModelBuilder, int, openai_embed_model_ptr, max_retries)
    BUILDER_WITH(OpenAIEmbedModelBuilder, shared_ptr<OpenAIClient>, openai_embed_model_ptr, openai_embed_client)
    std ::shared_ptr<OpenAIEmbedModel> build() { return openai_embed_model_ptr; }

 private:
    std::shared_ptr<OpenAIEmbedModel> openai_embed_model_ptr = std::make_shared<OpenAIEmbedModel>();
}
#endif