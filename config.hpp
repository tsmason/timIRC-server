#pragma once
#include <netinet/in.h>

class Config{
	public:
		/**
		 * @brief Returns singleton Config object
		 *
		 */
		static Config& value();

		/**
		 * @brief Gets the servers IP Address
		 *
		 * @return in_addr IP address object
		 */
		in_addr 	serverAddress();

		/**
		 * @brief Gets the maximum number of concurrent connections the server can handle.
		 *
		 */
		unsigned int	maximumConnections();

		/**
		 * @brief Gets the timeout value in milliseconds
		 *
		 */
		unsigned int	timeOut();

		/**
		 * @brief Returns the maximum number of threads;
		 *
		 */

		unsigned int	threads();
		
		/**
		 * @brief Returns the maximum number of messages a client can send in 5 seconds.
		 *
		 */
		unsigned int	rateLimit();

#ifdef USE_SSL
		/**
		 * @brief Returns if SSL is available and enabled
		 *
		 * @return True if SSL should be used
		 */
		bool 		usingSSL();
#endif

	private:
		//Consturctors
		Config(in_addr serverAddress);
		Config(const Config&) = delete;
		Config& operator=(const Config&) = delete;

		//Properties
		in_addr 	m_ipAddress;
		in_port_t 	m_port;
		unsigned int	m_maxConnections;
		unsigned int	m_clientTimeOut;
		unsigned int	m_threads;
		unsigned int	m_messageRateLimit;
#ifdef USE_SSL
		bool 		m_usingSSL;
#endif
};

