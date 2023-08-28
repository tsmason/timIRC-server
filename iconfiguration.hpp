#pragma once
#include <netinet/in.h>
#include "logger.hpp"

class IConfiguration{
	public:
		virtual in_addr		 	getIP() = 0;
		virtual in_port_t 		getPort() = 0;
		virtual unsigned int 		getMaxConnections() = 0;
		virtual unsigned int 		getClientTimeOut() = 0;
		virtual unsigned int 		getThreads() = 0;
		virtual unsigned int 		getMessageRateLimit() = 0;
		virtual Logger::LogLevel 	getLogLevel() = 0;
		virtual bool 			getUsingSSL() = 0;
};
