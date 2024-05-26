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

#include "llm/openai/openai-req.h"
#include "llm/openai/openai-resp.h"
#include "utils/meta.h"

using string = std::string;

class OpenAIClientBuilder;
using namespace cpr;
class OpenAIClient {
 public:
    friend class OpenAIClientBuilder;

 public:
    TextEmbedding embed(const vector<string> &input) {
        OpenAIReq req{.input = std::move(input), .model = model};

        auto body = rfl::json::write(req);
        spdlog::info("messages req:{}", body);

        cpr::Response r = cpr::Post(
            cpr::Url{base_url + "/embeddings"}, cpr::Body(body),
            cpr::Header{{"Content-Type", "application/json"}, {"Authorization", "Bearer " + api_key}});

        spdlog::info("api-key:{}", api_key);
        if (r.error) {
            if (r.error.code == cpr::ErrorCode::OPERATION_TIMEDOUT) {
                spdlog::error("request timeout");
            } else {
                spdlog::error("request failed with error:{}", r.error.message);
            }
            return TextEmbedding();
        }
        if (r.status_code != 200) {
            spdlog::error("request failed with status code:{},text:{}", r.status_code, r.text);
            return TextEmbedding();
        }
        // spdlog::info("messages response:{}", r.text);
        auto resp = rfl::json::read<OpenAIResp>(r.text).value();
        // std::get_if<std::vector<TextContent>>(&resp.content)
        spdlog::info("{},{}", resp.data.size(), resp.data[0].embedding.size());
        return resp.data.size() > 0 ? resp.data[0] : TextEmbedding();
    }

 private:
    string base_url = "https://api.openai.com/v1/";
    string model = "";
    string api_key = std::getenv("OPENAI_API_KEY") ? std::getenv("OPENAI_API_KEY") : "";
    int timeout = 60;
};

class OpenAIClientBuilder {
 public:
    BUILDER_WITH(OpenAIClientBuilder, string, client, base_url)
    BUILDER_WITH(OpenAIClientBuilder, string, client, model)
    BUILDER_WITH(OpenAIClientBuilder, string, client, api_key)
    BUILDER_WITH(OpenAIClientBuilder, int, client, timeout)
    std ::shared_ptr<OpenAIClient> build() { return client; }

 private:
    std::shared_ptr<OpenAIClient> client = std::make_shared<OpenAIClient>();
};
#endif  // LANGCHAIN4CPP_MODULES_LLM_OPENAI_CLIENT_H_