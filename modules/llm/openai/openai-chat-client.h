#ifndef OPENAI_CHAT_CLIENT
#define OPENAI_CHAT_CLIENT
#include <cpr/cpr.h>
#include <spdlog/spdlog.h>

#include <algorithm>
#include <rfl.hpp>
#include <rfl/json.hpp>

#include "llm/openai/openai-chat-req.h"
#include "llm/openai/openai-chat-resp.h"
// gpt-4 and dated model releases,
// gpt-4-turbo-preview and dated model releases,
// gpt-4-vision-preview,
// gpt-4-32k and dated model releases,
// gpt-3.5-turbo and dated model releases,
// gpt-3.5-turbo-16k and dated model releases,
// fine-tuned versions of gpt-3.5-turbo
using namespace openai_llm;
struct OpenAiChatClient {
    friend struct OpenAiChatClientBuilder;
    OpenAiChatResp chat(const OpenAiChatReq& req) {
        auto body = rfl::json::write(req);
        cpr::Response r = cpr::Post(
            cpr::Url{url}, cpr::Body(body),
            cpr::Header{{"Content-Type", "application/json"}, {"Authorization", "Bearer " + api_key}});
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
        return rfl::json::read<OpenAiChatResp>(r.text).value();
    }

 private:
    string url = "https://api.openai.com/v1/chat/completions";
    string api_key = std::getenv("OPENAI_API_KEY") ? std::getenv("OPENAI_API_KEY") : "";
    int timeout = 60;
};
struct OpenAiChatClientBuilder {
    BUILDER_WITH(OpenAiChatClientBuilder, string, client, url)
    BUILDER_WITH(OpenAiChatClientBuilder, string, client, api_key)
    BUILDER_WITH(OpenAiChatClientBuilder, int, client, timeout)
    std ::shared_ptr<OpenAiChatClient> build() { return client; }

 private:
    std::shared_ptr<OpenAiChatClient> client = std::make_shared<OpenAiChatClient>();
};
#endif  // OPENAI_CHAT_CLIENT