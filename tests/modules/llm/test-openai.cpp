#include <gtest/gtest.h>

#include <cpptrace/cpptrace.hpp>
#include <cstdlib>
#include <stdexcept>
#include <string>

#include "llm/openai/llm.h"
#include "llm/openai/openai-chat-model.h"
#include "llm/openai/openai-embed-client.h"
#include "llm/openai/openai-embed-model.h"
#include "llm/openai/openai-req.h"
#include "llm/openai/openai-resp.h"

using namespace std;

TEST(VariantVector, mustSame) {
    auto x = vector<Image>();
    auto a = ImageContent();
    auto b = TextContent();
    x.push_back(a);
    x.push_back(b);
}
TEST(OpenAIClient, embed) {
    OpenAiEmbedClientBuilder builder;
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
TEST(OpenAiChatModelBuilder, build) {
    OpenAiChatClientBuilder builder;
    auto client_ptr = builder.build();

    OpenAiChatModelBuilder mbuilder;
    auto openAiChatModel = mbuilder.with_client_ptr(client_ptr).build();
    auto reMess = openAiChatModel->chat(vector<string>({"hello"}));
    spdlog::info("chat {}:{}", reMess.size(), reMess[0]);
}
TEST(OpenAiChatModelBuilder, mmchat) {
    OpenAiChatClientBuilder builder;
    auto client_ptr = builder.build();

    OpenAiChatModelBuilder mbuilder;
    auto openAiChatModel = mbuilder.with_client_ptr(client_ptr).with_model("gpt-4o").build();
    auto images = vector<string>{
        "https://images.pexels.com/photos/1563356/pexels-photo-1563356.jpeg?auto=compress&cs=tinysrgb&w=800"};
    auto reMess = openAiChatModel->mmchat(images, "what is in the image");
    spdlog::info("chat response {}:", reMess);
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
