#include <arpa/inet.h>
#include <cstdlib>
#include <string>
#include "configparser.hpp"


//TODO: LOGGING for everything

ConfigParser::ConfigParser(){
	configFileStream = std::ifstream("config.json");
	configData = nlohmann::json::parse(configFileStream);
};

ConfigParser&		ConfigParser::value(){
	static ConfigParser instance;
	return instance;
};

in_addr 		ConfigParser::getIP(){
	in_addr returnAddress;
	std::string ipAddress = configData["IPAddress"];

	//assign ip address string to in_addr pointer.  If this fails, exit with status 1
	if (inet_aton(ipAddress.c_str(), &returnAddress) == 0){
		std::exit(1);
	};

	return returnAddress;
}

in_port_t 		ConfigParser::getPort(){
	unsigned int port = configData["Port"];
	return htons(port);
}

unsigned int 		ConfigParser::getMaxConnections(){
	return configData["MaxConnections"];
}

unsigned int 		ConfigParser::getClientTimeOut(){
	return configData["TimeOut"];
}

unsigned int 		ConfigParser::getThreads(){
	return configData["Threads"];
}

unsigned int 		ConfigParser::getMessageRateLimit(){
	return configData["RateLimit"];
}

Logger::LogLevel 	ConfigParser::getLogLevel(){
	//TODO: Error handling for out of range LogLevel

	return static_cast<Logger::LogLevel>(configData["LogLevel"]);
}

bool			ConfigParser::getUsingSSL(){
	bool usingSSL = configData["SSL"];

	//If usingSSL is set but OpenSSL not found, exit with error 2.
#ifndef USE_SSL
	if (usingSSL){
		std::exit(2);
	}
#endif

	return usingSSL;
}
