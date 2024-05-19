#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_MESSAGE_CONTENT_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_MESSAGE_CONTENT_H_
// Copyright[2024] meetai.co@gmail.com

#include <string>

#include "llm/anthropic/message-source.h"
#include "utils/meta.h"
using string = std::string;

struct ImageContent {
    string type = "image";
    MessageSource source = {};
};
struct TextContent {
    string type = "image";
    string text = "";
};
using MessageContent = std::variant<ImageContent, TextContent>;

#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_MESSAGE_CONTENT_H_
