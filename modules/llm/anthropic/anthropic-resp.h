#ifndef ANTHROPIC_RESP_H_
#define ANTHROPIC_RESP_H_
#include <map>
#include <string>
#include <optional>

#include "llm/anthropic/message-content.h"
#include "utils/meta.h"

using namespace std;

// with text message
// curl  https://api.anthropic.com/v1/messages \
//     --header "x-api-key: $ANTHROPIC_API_KEY" \
//     --header "anthropic-version: 2023-06-01" \
//     --header "content-type: application/json" \
//     --data \
//'{
//     "model": "claude-3-opus-20240229",
//     "max_tokens": 1024,
//     "messages": [
//         {"role": "user", "content": "Hello, world"}
//     ]
// }'
//
//  with image message
//  {"role": "user", "content": [
//   {
//     "type": "image",
//     "source": {
//       "type": "base64",
//       "media_type": "image/jpeg",
//       "data": "/9j/4AAQSkZJRg...",
//     }
//   },
//   {"type": "text", "text": "What is in this image?"}
//]}
////{
//  "content": [
//    {
//      "text": "Hi! My name is Claude.",
//      "type": "text"
//    }
//  ],
//  "id": "msg_013Zva2CMHLNnXjNJJKqJ2EF",
//  "model": "claude-3-opus-20240229",
//  "role": "assistant",
//  "stop_reason": "end_turn",
//  "stop_sequence": null,
//  "type": "message",
//  "usage": {
//    "input_tokens": 10,
//    "output_tokens": 25
//  }
//}
//

struct Usage {
    int input_tokens;
    int output_tokens;
};

struct AnthropicResp {
    string id;
    string model;
    string role;
    string type;
    string stop_reason;
    std::optional<string> stop_sequence;
    Usage usage;
    vector<MessageContent> content;
};

#endif  // ANTHROPIC_RESP_H_
