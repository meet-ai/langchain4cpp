#ifndef CHATREQUEST_H_
#define CHATREQUEST_H_
#include <string>
#include <memory>
#include "utils/meta.h"
using namespace std;

namespace anthropic_api {

  class ChatMessageRequest {
  public:
      ChatMessageRequest() = default;            // 显式请求默认构造函数
      ChatMessageRequest(const ChatMessageRequest&) = default; // 显式请求拷贝构造函数
      ChatMessageRequest(ChatMessageRequest&&) = default;   // 显式请求移动构造函数
      ChatMessageRequest& operator=(const ChatMessageRequest&) = default; // 显式请求拷贝赋值运算符
      ChatMessageRequest& operator=(ChatMessageRequest&&) = default; // 显式请求移动赋值运算符
      ~ChatMessageRequest() = default;           // 显式请求析构函数

      friend class ChatMessageRequestBuilder;

  
  private:
     PROPERTY(int,value_,0)
  
  };


  class ChatMessageRequestBuilder {
  public:
      ChatMessageRequestBuilder() = default;            // 显式请求默认构造函数
      ChatMessageRequestBuilder(const ChatMessageRequestBuilder&) = default; // 显式请求拷贝构造函数
      ChatMessageRequestBuilder(ChatMessageRequestBuilder&&) = default;   // 显式请求移动构造函数
      ChatMessageRequestBuilder& operator=(const ChatMessageRequestBuilder&) = default; // 显式请求拷贝赋值运算符
      ChatMessageRequestBuilder& operator=(ChatMessageRequestBuilder&&) = default; // 显式请求移动赋值运算符
      ~ChatMessageRequestBuilder() = default;           // 显式请求析构函数
  
  private:
      shared_ptr<ChatMessageRequest> sp_chat_message_req = make_shared<ChatMessageRequest>(); 
  };

} // namespace anthropic_api

#endif // CHATREQUEST_H_
