#include<spdlog/spdlog.h>
#include <CLI/CLI.hpp>
#include <spdlog/spdlog.h>
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h> // 确保包含这
#include <matchit.h>
#include <Poco/Util/IniFileConfiguration.h>
#include <Poco/AutoPtr.h>

#include "llm/anthropic/anthropic-api.h"




using namespace std;
using namespace matchit;
using namespace Poco;
using namespace anthropic_api;

import strutil;

//namespace di = boost::di;

std::string filename = "conf/config.toml";



unique_ptr<spdlog::logger> InitLog(const string& level){
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto logger = std::make_unique<spdlog::logger>("logger",console_sink);
    auto log_level = match(level) (
        pattern | "debug" = expr(spdlog::level::debug),
        pattern | "info" = expr(spdlog::level::info),
        pattern | "warn" = expr(spdlog::level::warn)
    );
    logger->set_level(log_level);
    return logger;
}

int main(int argc, char**argv) {
    CLI::App app{"cpp template"};
    argv = app.ensure_utf8(argv);
    app.add_option("-c,--conf", filename, "A help string");
    CLI11_PARSE(app, argc, argv);

    AutoPtr<Util::IniFileConfiguration> pConfig(new Util::IniFileConfiguration(filename));
    //auto ini_config = make_shared<Util::IniFileConfiguration>(filename);
 //   ini_config->load();
    //config.globalConfig = ParseConfig(filename);
    //InitLog(globalConfig->log.log_level);
    spdlog::info("config:{}", pConfig->getString("log.log_level"));
}
