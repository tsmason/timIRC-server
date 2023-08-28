#pragma once
#include <fstream>
#include <nlohmann/json.hpp>
#include "iconfiguration.hpp"

class ConfigParser : public IConfiguration {
	public:
		static ConfigParser&	value();
		in_addr			getIP() override;
		in_port_t		getPort() override;
		unsigned int		getMaxConnections() override;
		unsigned int 		getClientTimeOut() override;
		unsigned int 		getThreads() override;
		unsigned int 		getMessageRateLimit() override;
		Logger::LogLevel 	getLogLevel() override;
		bool			getUsingSSL() override;

	private:
		//Constructors
		ConfigParser();
		ConfigParser(const ConfigParser&) = delete;
		ConfigParser& operator=(const ConfigParser&) = delete;

		//Properties
		std::ifstream 		configFileStream;
		nlohmann::json 		configData;
};
