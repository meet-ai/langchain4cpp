// Copyright[2024] meetai.co@gmail.com
#ifndef LANGCHAIN4CPP_MODULES_LLM_OPENAI_CLIENT_H_
#define LANGCHAIN4CPP_MODULES_LLM_OPENAI_CLIENT_H_

#include <cpr/cpr.h>
#include <spdlog/spdlog.h>

#include <iostream>
#include <memory>
#include <rfl.hpp>
#include <rfl/json.hpp>
#include <sstream>
#include <string>
#include <variant>
#include <vector>

#include "llm/anthropic/anthropic-req.h"
#include "llm/anthropic/anthropic-resp.h"
#include "llm/anthropic/message-content.h"
#include "llm/anthropic/user-message.h"
#include "llm/embedding.h"
#include "utils/meta.h"

using string = std::string;

class OpenAIClientBuilder;
using namespace cpr;
class OpenAIClient {
 public:
    friend class OpenAIClientBuilder;

 public:
    vector<TextEmbedding> embed() {}

 private:
    string base_url = "https://api.openai.com/v1/";
    string model = "";
    string api_key = "";
    string version = "";
    string beta = "";
    int timeout = 60;
    bool log_requests = false;
    bool log_responses = false;
};

class OpenAIClientBuilder {
 public:
    BUILDER_WITH(OpenAIClientBuilder, string, client, base_url)
    BUILDER_WITH(OpenAIClientBuilder, string, client, api_key)
    BUILDER_WITH(OpenAIClientBuilder, string, client, version)
    BUILDER_WITH(OpenAIClientBuilder, string, client, beta)
    BUILDER_WITH(OpenAIClientBuilder, int, client, timeout)
    BUILDER_WITH(OpenAIClientBuilder, bool, client, log_requests)
    BUILDER_WITH(OpenAIClientBuilder, bool, client, log_responses)
    std ::shared_ptr<OpenAIClient> build() { return client; }

 private:
    std::shared_ptr<OpenAIClient> client = std::make_shared<OpenAIClient>();
};
#endif  // LANGCHAIN4CPP_MODULES_LLM_OPENAI_CLIENT_H_
