#include <gtest/gtest.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "llm/anthropic/anthropic-client.h"
#include "llm/anthropic/anthropic-req.h"

using namespace std;
#include "llm/anthropic/anthropic-api.h"
#include "llm/anthropic/anthropic-model.h"

TEST(GETENV, getenv) {
    auto envApi = string(std::getenv("CLUADE3_API_KEY")? std::getenv("CLAUDE3_API_KEY"):"" );
    spdlog::info("{}",envApi);
}

TEST(AnthropicReq, Build) {
    AnthropicClientBuilder builder;
//    auto anthropic_client_ptr = builder.with_url("").with_method_("post").with_body_("").build();
//    anthropic_client_ptr->AddHeaders("x-api-key","hello");
//    anthropic_client_ptr->AddHeaders("anthropic-version","2023-06-01");
//    anthropic_client_ptr->AddHeaders("content-type","application/json");
//    anthropic_client_ptr->Send();
    //anthropic_client_ptr->Create("hello");
}
TEST(Client, Create) {
    AnthropicClientBuilder builder;
    auto anthropic_client_ptr = builder.build();
    //anthropic_client_ptr->Create("hello");
}

TEST(Anthropic, ListModels) {
    AnthropicModelBuilder builder;
    auto anthropic_model_ptr = builder.build();
    anthropic_model_ptr->ListModels();
}
TEST(Anthropic, Pipeline) {
    AnthropicModelBuilder builder;
    //builder.with_model_name_("hello");
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
