
#ifndef OPENAI_CHAT_RESP
#define OPENAI_CHAT_RESP
#include <string>
using namespace std;
//{
//  "id": "chatcmpl-123",
//  "object": "chat.completion",
//  "created": 1677652288,
//  "model": "gpt-3.5-turbo-0125",
//  "system_fingerprint": "fp_44709d6fcb",
//  "choices": [{
//    "index": 0,
//    "message": {
//      "role": "assistant",
//      "content": "\n\nHello there, how may I assist you today?",
//    },
//    "logprobs": null,
//    "finish_reason": "stop"
//  }],
//  "usage": {
//    "prompt_tokens": 9,
//    "completion_tokens": 12,
//    "total_tokens": 21
//  }
//}
namespace openai_llm {
struct Usage {
    int32_t prompt_tokens;
    int32_t completion_tokens;
    int32_t total_tokens;
};
struct AssistantMessage {
    string role;
    string content;
};
struct Choice {
    int32_t index;
    AssistantMessage message;
    std::optional<string> logprobs;
    string finish_reason;
};
struct OpenAiChatResp {
    string id;
    string object;
    int64_t created;
    string model;
    std::optional<string> system_fingerprint;
    vector<Choice> choices;
    Usage usage;
};
}  // namespace openai_llm
#endif  // ifndef OPENAI_CHAT_RESP
