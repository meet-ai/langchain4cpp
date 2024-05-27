# langchain4cpp
Cpp version of langchain.

# future plan
  - [x]  Claude3 chat
  - [x]  openai embedding 
  - [x]  Openai chat
  - [ ]  Llama3 support 
  - [ ]  Cache
  - [ ]  Vector index support
  - [ ]  Prompt engineer
  - [ ]  Agent support
  - [ ]  RAG（Retrieval-Augmented Generation）support
  
# compile

```
#install xmake  
curl -fsSL https://xmake.io/shget.text | bash

# install conan
pip install conan

#compile openai unit 
xmake build -v ut-openai

#run as demo
xmake run -v ut-openai -a  --gtest_filter=OpenAiChatModelBuilder.build
```