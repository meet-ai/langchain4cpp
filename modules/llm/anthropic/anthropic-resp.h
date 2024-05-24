#ifndef ANTHROPIC-RESP_H_
#define ANTHROPIC-RESP_H_
#include <map>
#include <string>

#include "utils/meta.h"

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
class AnthropicRespBuilder;
class AnthropicResp {
 public:
    friend class AnthropicRespBuilder;

 private:
    string url_ = "";
    string method_ = "post";
    string body_ = "";
    map<string, string> headers_ = {};
};

class AnthropicRespBuilder {
 public:
    std::shared_ptr<AnthropicResp> build() { return req_ptr; }

 private:
    std::shared_ptr<AnthropicResp> req_ptr = std::make_shared<AnthropicResp>();
};


#endif // ANTHROPIC-RESP_H_
