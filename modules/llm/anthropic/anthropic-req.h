#ifndef ANTHROPIC-REQ_H_
#define ANTHROPIC-REQ_H_
#include <map>
#include <string>

#include "utils/meta.h"
#include "llm/anthropic/user-message.h"
#include <vector>

using namespace std;

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
struct AnthropicReq {
    string model;
    int max_tokens;
    vector <UserMessage> messages;
};


#endif  // ANTHROPIC-REQ_H_
