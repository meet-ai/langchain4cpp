// Copyright[2024] meetai.co@gmail.com

#ifndef LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_API_H_
#define LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_API_H_

#include <Poco/Ascii.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/NameValueCollection.h>
#include <Poco/Net/NetException.h>
#include <Poco/NumberFormatter.h>
#include <Poco/StreamCopier.h>
#include <Poco/String.h>
#include <Poco/URI.h>
#include <spdlog/spdlog.h>

#include <iostream>
#include <memory>
#include <rfl.hpp>
#include <rfl/json.hpp>

#include "llm/anthropic/chat-request.h"
#include "llm/anthropic/chat-request.h"
#include "llm/anthropic/chat-response.h"
#include "llm/anthropic/chat-model.h"

namespace anthropic_api {}  // namespace anthropic_api

#endif  // LANGCHAIN4CPP_MODULES_LLM_ANTHROPIC_ANTHROPIC_API_H_
