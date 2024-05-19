
// Copyright[2024] meetai.co@gmail.com

#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_LLM_MESSAGE_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_LLM_MESSAGE_H_

#include <string>

#include "llm/anthropic/message-content.h"

using string = std::string;
struct Usage {
    int input_tokens = 0;
    int output_tokens = 0;
};
struct LlmMessage {
    string id = "";
    string type = "message";
    string role = "assistant";
    TextContent content = {};
    Usage usage = {};
};
#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_LLM_MESSAGE_H_
