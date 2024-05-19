#pragma once
#include <memory>
#include <string>
#include "utils/meta.h"

using namespace std;



class ChatLanguageModel {
public:
    ChatLanguageModel() = default;            // 显式请求默认构造函数
    ChatLanguageModel(const ChatLanguageModel&) = default; // 显式请求拷贝构造函数
    ChatLanguageModel(ChatLanguageModel&&) = default;   // 显式请求移动构造函数
    ChatLanguageModel& operator=(const ChatLanguageModel&) = default; // 显式请求拷贝赋值运算符
    ChatLanguageModel& operator=(ChatLanguageModel&&) = default; // 显式请求移动赋值运算符
    ~ChatLanguageModel() = default;           // 显式请求析构函数
    ChatLanguageModel(int value) : value_(value) {} // 用户定义的构造函数


    vector<string> generate(vector<string> messages) {
        return vector<string>();
    }


private:
   PROPERTY(int,value_,0)
   PROPERTY(string, api_key_,"")
   PROPERTY(string, model_name_,"")
   PROPERTY(float,temperature,0.9)
   PROPERTY(int,top_p,10)
   PROPERTY(int,topk,3)
   PROPERTY(int, max_tokens,1024)
   PROPERTY(bool, stop_seq_,false)
   PROPERTY(bool, max_retries,3)
};
class ChatLanguageModelBuilder {
public:
    ChatLanguageModelBuilder() = default;            // 显式请求默认构造函数
    ChatLanguageModelBuilder(const ChatLanguageModelBuilder&) = default; // 显式请求拷贝构造函数
    ChatLanguageModelBuilder(ChatLanguageModelBuilder&&) = default;   // 显式请求移动构造函数
    ChatLanguageModelBuilder& operator=(const ChatLanguageModelBuilder&) = default; // 显式请求拷贝赋值运算符
    ChatLanguageModelBuilder& operator=(ChatLanguageModelBuilder&&) = default; // 显式请求移动赋值运算符
    ~ChatLanguageModelBuilder() = default;           // 显式请求析构函数

  public:
    ChatLanguageModelBuilder &withApiKey(const string &apiKey) {
        sp_chat_language_model->set_api_key_(apiKey);
        return (*this);
    }
    ChatLanguageModelBuilder &withModelName(const string &modelName) {
        sp_chat_language_model->set_model_name_(modelName);
        return (*this);
    }
    ChatLanguageModelBuilder &withTemperature(int temperature) {
        sp_chat_language_model->set_temperature(temperature);
        return (*this);
    }
    ChatLanguageModelBuilder &withTopP(int topP) { 
        sp_chat_language_model->set_top_p(topP);
        return (*this);
    }

    ChatLanguageModelBuilder &withTopK(int topK) {
        sp_chat_language_model->set_topk(topK);
        return (*this);
    }
    ChatLanguageModelBuilder &withMaxRetries(int retry) {
        sp_chat_language_model->set_max_retries(retry);
        return (*this);

    }
    ChatLanguageModelBuilder &withStopSeq(bool stop) {
        sp_chat_language_model->set_stop_seq_(stop);
        return (*this);
    }

    shared_ptr<ChatLanguageModel> build() {
        return sp_chat_language_model;
    }

  private:
    shared_ptr<ChatLanguageModel> sp_chat_language_model=make_shared<ChatLanguageModel>();

};
