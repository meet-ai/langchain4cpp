#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_REQUEST_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_REQUEST_H_
// Copyright[2024] meetai.co@gmail.com

#include <memory>
#include <string>

#include "utils/meta.h"
namespace anthropic_api {

class ChatMessageRequest {
 public:
 private:
    PROPERTY(int, value_, 0)
};

class ChatMessageRequestBuilder {
 public:
 private:
    std::shared_ptr<ChatMessageRequest> chat_message_req_ptr = std::make_shared<ChatMessageRequest>();
};

}  // namespace anthropic_api

#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_CHAT_REQUEST_H_
