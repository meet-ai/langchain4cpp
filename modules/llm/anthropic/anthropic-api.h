#ifndef ANTHROPIC - API_H_
#define ANTHROPIC -API_H_

#include <memory>

#include <Poco/Ascii.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/NameValueCollection.h>
#include <Poco/Net/NetException.h>
#include <Poco/NumberFormatter.h>
#include <Poco/String.h>
#include <Poco/URI.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/URI.h>
#include <spdlog/spdlog.h>
#include <iostream>
#include <rfl/json.hpp>
#include <rfl.hpp>

#include "chat-response.h"
#include "chat-request.h"
#include "chat-language-model.h"

using namespace std;

namespace anthropic_api {


} // namespace anthropic_api

#endif // ANTHROPIC-API_H_
