#include "gen-cpp/WeatherService.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <memory>
#include <iostream>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;
using namespace Weather;

class WeatherServiceHandler : public WeatherServiceIf {
public:
    double getTemperature(const std::string& city) override {
        std::cout << "Request for city: " << city << std::endl;
        if (city == "Bangalore") return 28.5;
        if (city == "Delhi") return 21.0;
        return 25.0;
    }
};

int main() {
    auto handler = std::make_shared<WeatherServiceHandler>();
    auto processor = std::make_shared<WeatherServiceProcessor>(handler);
    auto serverTransport = std::make_shared<TServerSocket>(9090);
    auto transportFactory = std::make_shared<TBufferedTransportFactory>();
    auto protocolFactory = std::make_shared<TBinaryProtocolFactory>();

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    std::cout << "Weather Thrift server running on port 9090..." << std::endl;
    server.serve();

    return 0;
}
