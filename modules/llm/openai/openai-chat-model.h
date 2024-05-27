
#ifndef OPENAI_CHAT_MODEL
#define OPENAI_CHAT_MODEL
#include <memory>
#include <string>
#include <vector>

#include "llm/openai/openai-chat-client.h"
#include "llm/openai/openai-chat-req.h"
#include "llm/openai/openai-model.h"

using namespace std;
namespace openai_llm {

using OpenAiChatReq = openai_llm::OpenAiChatReq;
struct OpenAiChatModel : OpenAiModel {
    friend struct OpenAiChatModelBuilder;
    vector<string> chat(const std::vector<string> &texts) {
        // TODO: build req/resp
        vector<Message> messages(texts.size());
        std::transform(texts.begin(), texts.end(), messages.begin(), [](const string &text) {
            Message message;
            message.role = "user";
            message.content = text;
            return message;
        });

        OpenAiChatReq req{.model = model, .messages = messages};
        auto resp = client_ptr->chat(req);
        vector<string> reMessages(resp.choices.size());
        std::transform(resp.choices.begin(), resp.choices.end(), reMessages.begin(), [](const Choice &choice) {
            return choice.message.content;
        });
        return reMessages;
    }

    string mmchat(const std::vector<string> &_images, const string &prompts) {
        // TODO: build req/resp
        vector<Message> messages(1);
        vector<Image> images(_images.size());
        std::transform(_images.begin(), _images.end(), images.begin(), [](const string &image) {
            ImageContent imageContent{.type = "image_url", .image_url = {image}};
            return Image{imageContent};
        });
        auto promptInMessage = TextContent{.type = "text", .text = prompts};
        vector<Image> imagesInOneMessage;
        images.push_back(promptInMessage);

        messages[0].role = "user";
        messages[0].content = images;

        OpenAiChatReq req{.model = model, .messages = messages};
        auto resp = client_ptr->chat(req);
        vector<string> reMessages(resp.choices.size());
        std::transform(resp.choices.begin(), resp.choices.end(), reMessages.begin(), [](const Choice &choice) {
            return choice.message.content;
        });
        return reMessages.size() > 0 ? reMessages[0] : "";
    }

 private:
    shared_ptr<OpenAiChatClient> client_ptr = make_shared<OpenAiChatClient>();
    string model = "gpt-3.5-turbo";
    // string api_key = std::getenv("OPENAI_API_KEY") ? std::getenv("OPENAI_API_KEY") : "";
    // string url = "https://api.openai.com/v1/chat/completions";
};

struct OpenAiChatModelBuilder {
    BUILDER_WITH(OpenAiChatModelBuilder, string, openai_chat_model_ptr, model)
    BUILDER_WITH(OpenAiChatModelBuilder, shared_ptr<OpenAiChatClient>, openai_chat_model_ptr, client_ptr)
    std ::shared_ptr<OpenAiChatModel> build() { return openai_chat_model_ptr; }

 private:
    std::shared_ptr<OpenAiChatModel> openai_chat_model_ptr = std::make_shared<OpenAiChatModel>();
};
}  // namespace openai_llm
#endif  // OPENAI_CHAT_MODEL