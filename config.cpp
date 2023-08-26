#include <arpa/inet.h>
#include "config.hpp"

Config& 		Config::value(){
	static Config instance([]{
			in_addr serverAddress;
			inet_aton("127.0.0.1", &serverAddress);
			return serverAddress;}());
	return instance;
};

in_addr 		Config::serverAddress(){return m_ipAddress;}

unsigned int		Config::maximumConnections(){return m_maxConnections;}

unsigned int		Config::timeOut(){return m_clientTimeOut;}

unsigned int		Config::threads(){return m_threads;}

unsigned int		Config::rateLimit(){return m_messageRateLimit;}

Logger::LogLevel	Config::logLevel(){return m_logLevel;}

#ifdef USE_SSL
bool 			Config::usingSSL(){return m_usingSSL;}
#endif

Config::Config(in_addr serverAddress):m_ipAddress(serverAddress){}
