// Copyright[2024] meetai.co@gmail.com

#include <Poco/AutoPtr.h>
#include <Poco/Util/IniFileConfiguration.h>
#include <matchit.h>
#include <spdlog/sinks/stdout_color_sinks.h>  // 确保包含这
#include <spdlog/spdlog.h>

#include <CLI/CLI.hpp>
#include <boost/ut.hpp>  // import boost.ut;
#include <memory>

#include "llm/anthropic/anthropic-api.h"
#include "llm/anthropic/chat-language-model.h"

// import strutil;
using namespace boost::ut;

std::unique_ptr<spdlog::logger> InitLog(const string& level) {
    using namespace matchit;
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto logger = std::make_unique<spdlog::logger>("logger", console_sink);
    auto log_level = matchit::match(level)(pattern | "debug" = matchit::expr(spdlog::level::debug),
                                           pattern | "info" = matchit::expr(spdlog::level::info),
                                           pattern | "warn" = matchit::expr(spdlog::level::warn));
    logger->set_level(log_level);
    return logger;
}

int main(int argc, char** argv) {
    CLI::App app{"cpp template"};
    argv = app.ensure_utf8(argv);
    std::string filename = "conf/config.toml";
    app.add_option("-c,--conf", filename, "A help string");
    CLI11_PARSE(app, argc, argv);

    Poco::AutoPtr<Poco::Util::IniFileConfiguration> pConfig(new Poco::Util::IniFileConfiguration(filename));
    spdlog::info("config:{}", pConfig->getString("log.log_level"));
    InitLog(pConfig->getString("log.log_level"));
}
