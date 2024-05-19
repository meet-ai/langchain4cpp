#include <boost/ut.hpp> // import boost.ut;
#include<spdlog/spdlog.h>
#include <memory>
#include <matchit.h>
#include "llm/anthropic/anthropic-api.h"
#include "llm/anthropic/chat-language-model.h"

using namespace std;
using namespace matchit;
using namespace Poco;
using namespace anthropic_api;

int main(int argc, char **argv) {
  using namespace boost::ut;
  ChatLanguageModel clm;
  "sum"_test = [clm] {
    clm.get_value_();
    auto sp_chat_language_model = ChatLanguageModelBuilder().withApiKey("hello").build();
    sp_chat_language_model->get_max_tokens();

  };
}
