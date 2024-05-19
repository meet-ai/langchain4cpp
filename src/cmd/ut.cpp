// Copyright[2024] meetai.co@gmail.com

#include <matchit.h>
#include <spdlog/spdlog.h>

#include <boost/ut.hpp>  // import boost.ut;
#include <memory>
#include <rfl.hpp>
#include <rfl/toml.hpp>

#include "llm/anthropic/anthropic-api.h"
#include "llm/anthropic/chat-language-model.h"

// using namespace std;
// using namespace matchit;
// using namespace Poco;
// using namespace anthropic_api;

int main(int argc, char **argv) {
    ChatLanguageModel clm;
    using namespace boost::ut;
    "sum"_test = [clm] {
        auto sp_chat_language_model = ChatLanguageModelBuilder().withApiKey("hello").build();
        sp_chat_language_model->get_max_tokens();
    };

    "reflect"_test = [] {
        std::string x = R"({"role": "user", "content": [
  {
    "type": "image",
    "source": {
      "type": "base64",
      "media_type": "image/jpeg",
      "data": "/9j/4AAQSkZJRg..."
    }
  },
  {"type": "text", "text": "What is in this image?"}
]})";
        std::string y = R"({"role": "user", "content": "hello claude3"})";
        auto um = rfl::json::read<UserMessage>(x).value();
        boost::ut::expect(um.role == "user");
    };

    "anth_client"_test = [] {
        AnthropicClientBuilder builder;
        auto sp_anthropic_client = builder.baseUrl("http://www.baidu.com").apiKey("1234567").version("123456").build();
    };
}
