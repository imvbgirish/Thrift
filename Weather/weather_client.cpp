#include "gen-cpp/WeatherService.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <iostream>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace Weather;

int main(){
    auto socket = std::make_shared<TSocket>("127.0.0.1",9090);
    auto transport = std::make_shared<TBufferedTransport>(socket);
    auto protocol = std::make_shared<TBinaryProtocol>(transport);
    WeatherServiceClient client(protocol);

    try{
        transport->open();
        double temp = client.getTemperature("Bangalore");
        std::cout << "Temperature in Bangalore: " << temp << "°C" << std::endl;
        transport->close();
    } catch (TException& tx) {
        std::cerr << "Error: " << tx.what() << std::endl;
    }

    return 0;
}
