
#ifndef OPENAI_CHAT_REQ
#define OPENAI_CHAT_REQ
#include <string>
using namespace std;
//curl https://api.openai.com/v1/chat/completions \
//  -H "Content-Type: application/json" \
//  -H "Authorization: Bearer $OPENAI_API_KEY" \
//  -d '{
//    "model": "gpt-4o",
//    "messages": [
//      {
//        "role": "system",
//        "content": "You are a helpful assistant."
//      },
//      {
//        "role": "user",
//        "content": "Hello!"
//      }
//    ]
//  }'
// curl https://api.openai.com/v1/chat/completions \
//  -H "Content-Type: application/json" \
//  -H "Authorization: Bearer $OPENAI_API_KEY" \
//  -d '{
//    "model": "gpt-4-turbo",
//    "messages": [
//      {
//        "role": "user",
//        "content": [
//          {
//            "type": "text",
//            "text": "What'\''s in this image?"
//          },
//          {
//            "type": "image_url",
//            "image_url": {
//              "url":
//              "https://upload.wikimedia.org/wikipedia/commons/thumb/d/dd/Gfp-wisconsin-madison-the-nature-boardwalk.jpg/2560px-Gfp-wisconsin-madison-the-nature-boardwalk.jpg"
//            }
//          }
//        ]
//      }
//    ],
//    "max_tokens": 300
//  }'

namespace openai_llm {
struct TextContent {
    string type;
    string text;
};
struct Image {
    string url;
};
struct ImageContent {
    string type;
    Image image_url;
};

using VarContent = std::variant<ImageContent, TextContent>;
using VarStrContent = std::variant<string, std::variant<ImageContent, TextContent>>;
struct Message {
    string role;
    vector<VarStrContent> content;
};
struct OpenAiChatReq {
    string model = "";
    vector<Message> messages;
};
}  // namespace openai_llm
#endif  // OPENAI_CHAT_REQ
