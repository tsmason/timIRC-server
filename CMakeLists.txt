cmake_minimum_required(VERSION 3.5)
project(timIRCserv)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Wpedantic)

find_package(OpenSSL 1.1.0)
if(OpenSSL_FOUND)
	#define key paths
	set(CERT_PATH "${CMAKE_BINARY_DIR}/server_cert.pem")
	set(KEY_PATH "${CMAKE_BINARY_DIR}/server_key.pem")

	#custom command to generate the certifcate and key
	add_custom_command(
		OUTPUT ${CERT_PATH} ${KEY_PATH}
		COMMAND openssl req -x509 -newkey rsa:4096 -keyout ${KEY_PATH} -out ${CERT_PATH} -days 365 -subj "/CN=localhost" -nodes > /dev/null 2>&1
		COMMENT "Generating self-signed certificate"
	)

	#custom target to run the custom command
	add_custom_target(
		GenerateCert ALL
		DEPENDS ${CERT_PATH} ${KEY_PATH}
	)

	#add definitions and includes
	add_definitions(-DUSE_SSL)
	include_directories(${OPENSSL_INCLUDE_DIR})
endif()

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "*.hpp" "*.cpp")
add_executable(timIRCserv ${SOURCE_FILES})

if(OpenSSL_FOUND)
	target_link_libraries(timIRCserv ${OPENSSL_LIBRARIES})
endif()

