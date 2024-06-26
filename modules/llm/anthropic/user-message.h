// Copyright[2024] meetai.co @gmail.com
#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_USER_MESSAGE_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_USER_MESSAGE_H_

#include <string>
#include <variant>
#include <vector>

#include "llm/anthropic/message-content.h"
#include "utils/meta.h"


//with text message
//curl https://api.anthropic.com/v1/messages \
//     --header "x-api-key: $ANTHROPIC_API_KEY" \
//     --header "anthropic-version: 2023-06-01" \
//     --header "content-type: application/json" \
//     --data \
//'{
//    "model": "claude-3-opus-20240229",
//    "max_tokens": 1024,
//    "messages": [
//        {"role": "user", "content": "Hello, world"}
//    ]
//}'
//
// with image message
// {"role": "user", "content": [
//  {
//    "type": "image",
//    "source": {
//      "type": "base64",
//      "media_type": "image/jpeg",
//      "data": "/9j/4AAQSkZJRg...",
//    }
//  },
//  {"type": "text", "text": "What is in this image?"}
//]}
//
using string = std::string;
struct UserMessage {
    string role;
    std::variant<string, std::vector<MessageContent>> content;
};

#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_USER_MESSAGE_H_
