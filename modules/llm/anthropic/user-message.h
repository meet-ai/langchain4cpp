// Copyright[2024] meetai.co @gmail.com
#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_USER_MESSAGE_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_USER_MESSAGE_H_

#include <string>
#include <variant>
#include <vector>

#include "llm/anthropic/message-content.h"
#include "utils/meta.h"

using string = std::string;

using string = std::string;
struct UserMessage {
    string role;
    std::variant<string, std::vector<MessageContent>> content;
};

#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_USER_MESSAGE_H_
