#ifndef LLM_CONCEPTS
#define LLM_CONCEPTS
#include <concepts>

// 定义 LlmConcept 概念
template <typename T>
concept LlmConcept = requires(
    T t, const std::vector<std::string>& prompts, const string& prompt, const std::vector<std::string>& images) {
    { t.chat(prompts) } -> std::convertible_to<std::vector<string>>;
    { t.multiModelChat(prompt, images) } -> std::convertible_to<std::string>;
    // TODO: 了解图文混传的使用管理
    //{ t.generateTexts(prompts) } -> std::convertible_to<std::vector<std::string>>;
    { t.embeddings(prompts) } -> std::convertible_to<std::vector<std::vector<float>>>;
};

#endif  // LLM_CONCEPTS