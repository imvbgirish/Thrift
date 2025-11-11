cmake_minimum_required(VERSION 3.16)

project(WeatherClient VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

# Include generated Thrift code
include_directories(${CMAKE_SOURCE_DIR}/gen-cpp)

# --- Create the executable ---
qt_add_executable(appWeatherClient
    main.cpp
    WeatherManager.cpp
    WeatherManager.h
    gen-cpp/WeatherService.cpp
    gen-cpp/weather_types.cpp
    gen-cpp/weather_constants.cpp
)

# --- Add QML module inside the executable ---
qt_add_qml_module(appWeatherClient
    URI WeatherClient
    VERSION 1.0
    QML_FILES main.qml
)

# --- Link Qt and Thrift ---
target_link_libraries(appWeatherClient
    PRIVATE
        Qt6::Quick
        thrift
)

set_target_properties(appWeatherClient PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS appWeatherClient
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
