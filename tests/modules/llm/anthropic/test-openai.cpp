#include <gtest/gtest.h>

#include <cpptrace/cpptrace.hpp>
#include <cstdlib>
#include <stdexcept>
#include <string>

#include "llm/openai/llm.h"
#include "llm/openai/openai-client.h"
#include "llm/openai/openai-embed-model.h"
#include "llm/openai/openai-req.h"
#include "llm/openai/openai-resp.h"

using namespace std;
TEST(OpenAIClient, embed) {
    OpenAIClientBuilder builder;
    auto api_key = std::getenv("OPENAI_API_KEY") ? std::getenv("OPENAI_API_KEY") : "";
    auto client_ptr = builder.with_api_key(api_key).with_model("text-embedding-3-small").build();
    auto response = client_ptr->embed(vector<string>{"hello,world", "你是说"});
    spdlog::info(response.index);
}

TEST(OpenAILlmBuilder, build) {
    OpenAiLlmBuilder builder;
    auto openAiLlm = builder.with_model("hello").with_api_key("hello").with_base_url("hello").build();
    openAiLlm->chat(vector<string>({"hello"}));
}
// TEST(AnthropicClient, Create) {
//     AnthropicClientBuilder builder;
//     auto api_key = std::getenv("ANTHROPIC_API_KEY") ? std::getenv("ANTHROPIC_API_KEY") : "";
//
//     auto client_ptr = builder.with_api_key(api_key).build();
//     std::vector<UserMessage> ums = {{"user", "hello, what day is it today?"}};
//     client_ptr->Create(ums);
// }
//
// TEST(AnthropicReq, Build) {
//     AnthropicReq req = {.model = "mockmodel", .max_tokens = 1024, .messages = vector<UserMessage>()};
//     auto body = rfl::json::write(req);
//     EXPECT_EQ(body, R"({"model":"mockmodel","max_tokens":1024,"messages":[]})");
// }
//
// TEST(AnthropicChatModel, generate) {
//     AnthropicClientBuilder builder;
//     auto api_key = std::getenv("ANTHROPIC_API_KEY") ? std::getenv("ANTHROPIC_API_KEY") : "";
//
//     auto client_ptr = builder.with_api_key(api_key).build();
//     std::vector<UserMessage> ums = {{"user", "hello, what day is it today?"}};
//     // client_ptr->Create(ums);
//
//     AnthropicModelBuilder modelBuilder;
//     auto model = modelBuilder.with_anthropic_client(client_ptr).build();
//     auto result = model->generate("hello-world");
//     spdlog::info("anthropic model response:{}", result);
// }
//
// TEST(Anthropic, Pipeline) {
//     AnthropicModelBuilder builder;
//     // builder.with_model_name_("hello");
// }

void signalHandler(int signum) {
    std::cerr << "Error: signal " << signum << std::endl;
    cpptrace::generate_trace().print();
    exit(signum);
}

void setupSignalHandlers() {
    signal(SIGSEGV, signalHandler);
    signal(SIGABRT, signalHandler);
    signal(SIGFPE, signalHandler);
    signal(SIGILL, signalHandler);
    signal(SIGBUS, signalHandler);
    signal(SIGTRAP, signalHandler);
}

int main(int argc, char **argv) {
    setupSignalHandlers();
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
