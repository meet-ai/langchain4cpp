#include <gtest/gtest.h>

#include <cpptrace/cpptrace.hpp>
#include <cstdlib>
#include <stdexcept>
#include <string>

#include "llm/anthropic/anthropic-api.h"
#include "llm/anthropic/anthropic-client.h"
#include "llm/anthropic/anthropic-model.h"
#include "llm/anthropic/anthropic-req.h"
#include "llm/anthropic/anthropic-resp.h"

using namespace std;
TEST(GETENV, getenv) {
    auto envApi = string(std::getenv("CLUADE3_API_KEY") ? std::getenv("CLAUDE3_API_KEY") : "");
    spdlog::info("{}", envApi);
}

TEST(Struct, init) { UserMessage um = {"hello", "whatday"}; }

TEST(reflect, read) {
    string body =
        R"({"id":"msg_017VDvj8bLHJa7gKArJCSUjS","type":"message","role":"assistant","model":"claude-3-opus-20240229","content":[{"type":"text","text":"Today is Monday, March 13, 2023."}],"stop_reason":"end_turn","stop_sequence":null,"usage":{"input_tokens":15,"output_tokens":15}})";
    auto ar = rfl::json::read<AnthropicResp>(body).value();
    // spdlog::info("ar:{}",ar.content[0].text);
}

TEST(Cpr, Post) {
    //    UserMessage um = {.role = "user",.content="hello,what day is it today?"};
    //    vector<UserMessage> ums;
    //    ums.push_back(um);
    std::vector<UserMessage> ums = {{"user", "hello, what day is it today?"}};

    AnthropicReq req = {.model = "mockmodel", .max_tokens = 1024, .messages = ums};
    auto body = rfl::json::write(req);
    spdlog::info("ANTHROPIC:{}", std::getenv("ANTHROPIC_API_KEY"));
    auto api_key = std::getenv("ANTHROPIC_API_KEY") ? std::getenv("ANTHROPIC_API_KEY") : "";
    cpr::Response r = cpr::Post(
        cpr::Url{"https://api.anthropic.com/v1/messages"}, cpr::Body(body),
        cpr::Header{{"Content-Type", "application/json"}, {"x-api-key", api_key}, {"anthropic-version", "2023-06-01"}});
    spdlog::info("api-key:{}", api_key);
    spdlog::info("r.text:{}", r.text);
}

TEST(AnthropicClient, Create) {
    AnthropicClientBuilder builder;
    auto api_key = std::getenv("ANTHROPIC_API_KEY") ? std::getenv("ANTHROPIC_API_KEY") : "";

    auto client_ptr = builder.with_api_key(api_key).build();
    std::vector<UserMessage> ums = {{"user", "hello, what day is it today?"}};
    client_ptr->Create(ums);
}

TEST(AnthropicReq, Build) {
    AnthropicReq req = {.model = "mockmodel", .max_tokens = 1024, .messages = vector<UserMessage>()};
    auto body = rfl::json::write(req);
    EXPECT_EQ(body, R"({"model":"mockmodel","max_tokens":1024,"messages":[]})");
}

TEST(AnthropicChatModel, generate) {
    AnthropicClientBuilder builder;
    auto api_key = std::getenv("ANTHROPIC_API_KEY") ? std::getenv("ANTHROPIC_API_KEY") : "";

    auto client_ptr = builder.with_api_key(api_key).build();
    std::vector<UserMessage> ums = {{"user", "hello, what day is it today?"}};
    // client_ptr->Create(ums);

    AnthropicModelBuilder modelBuilder;
    auto model = modelBuilder.with_anthropic_client(client_ptr).build();
    auto result = model->generate("hello-world");
    spdlog::info("anthropic model response:{}", result);
}
TEST(Anthropic, ListModels) {
    AnthropicModelBuilder builder;
    auto anthropic_model_ptr = builder.build();
    anthropic_model_ptr->ListModels();
}

TEST(Anthropic, Pipeline) {
    AnthropicModelBuilder builder;
    // builder.with_model_name_("hello");
}

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
