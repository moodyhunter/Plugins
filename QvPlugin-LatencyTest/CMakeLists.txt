set(CMAKE_AUTOMOC ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(${CMAKE_CURRENT_LIST_DIR}/cmake/libuvw.cmake)

add_library(QvPlugin-LatencyTest SHARED
    ${CMAKE_CURRENT_LIST_DIR}/BuiltinLatencyTesterPlugin.hpp
    ${CMAKE_CURRENT_LIST_DIR}/BuiltinLatencyTesterPlugin.cpp
    ${CMAKE_CURRENT_LIST_DIR}/latency/DNSBase.hpp
    ${CMAKE_CURRENT_LIST_DIR}/latency/TCPLatencyTester.hpp
    ${CMAKE_CURRENT_LIST_DIR}/latency/TCPLatencyTester.cpp
    ${CMAKE_CURRENT_LIST_DIR}/latency/ICMPLatencyTester.hpp
    ${CMAKE_CURRENT_LIST_DIR}/latency/ICMPLatencyTester.cpp)

target_link_libraries(QvPlugin-LatencyTest
    PRIVATE
        Qt::Core
        Qv2ray::libuvw
        Qv2ray::QvPluginInterface)

qv2ray_configure_plugin(QvPlugin-LatencyTest)
