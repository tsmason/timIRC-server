#include <arpa/inet.h>
#include "config.hpp"
#include "configparser.hpp"

Config& 		Config::value(){
	static Config instance;
	return instance;
};

in_addr 		Config::serverAddress(){return m_ipAddress;}

in_port_t 		Config::port(){return m_port;}

unsigned int		Config::maximumConnections(){return m_maxConnections;}

unsigned int		Config::timeOut(){return m_clientTimeOut;}

unsigned int		Config::threads(){return m_threads;}

unsigned int		Config::rateLimit(){return m_messageRateLimit;}

Logger::LogLevel	Config::logLevel(){return m_logLevel;}

bool 			Config::usingSSL(){return m_usingSSL;}

Config::Config(){
	ConfigParser& parser = ConfigParser::value();
	m_ipAddress = parser.getIP();
	m_port = parser.getPort();
	m_maxConnections = parser.getMaxConnections();
	m_clientTimeOut = parser.getClientTimeOut();
	m_threads = parser.getThreads();
	m_messageRateLimit = parser.getMessageRateLimit();
	m_logLevel = parser.getLogLevel();
	m_usingSSL = parser.getUsingSSL();
}
