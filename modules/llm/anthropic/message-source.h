#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_MESSAGE_SOURCE_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_MESSAGE_SOURCE_H_
// Copyright[2024] meetai.co@gmail.com

#include <string>
using string = std::string;

struct MessageSource {
    string type = "image";
    string media_type = "image/jpeg";
    string data = "";
};

#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_MESSAGE_SOURCE_H_
