
#ifndef OPENAI_LLM
#define OPENAI_LLM
#include <memory>
#include <string>
#include <vector>

#include "utils/meta.h"
using namespace std;
struct OpenAiLlmBuilder;
struct OpenAiLlm {
    vector<string> chat(const vector<string>& texts) { return vector<string>{"hello"}; }
    string multiModelChat(const string& prompt, const vector<string>& images) { return ""; }
    vector<vector<float>> embedding(const vector<string>& texts) { return vector<vector<float>>{{0.0}}; }
    friend struct OpenAiLlmBuilder;

 private:
    string model = "";
    string api_key = "";
    string base_url = "";
};

struct OpenAiLlmBuilder {
    BUILDER_WITH(OpenAiLlmBuilder, string, llm_ptr, model)
    BUILDER_WITH(OpenAiLlmBuilder, string, llm_ptr, api_key)
    BUILDER_WITH(OpenAiLlmBuilder, string, llm_ptr, base_url)
    shared_ptr<OpenAiLlm> build() { return llm_ptr; }

 private:
    shared_ptr<OpenAiLlm> llm_ptr = make_shared<OpenAiLlm>();
};
#endif