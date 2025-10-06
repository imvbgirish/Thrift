#include "gen-cpp/Calculator.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <iostream>
#include <memory>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace tutorial;

int main() {
    auto socket = std::make_shared<TSocket>("localhost", 9090);
    auto transport = std::make_shared<TBufferedTransport>(socket);
    auto protocol = std::make_shared<TBinaryProtocol>(transport);

    CalculatorClient client(protocol);

    try {
        transport->open();
        std::cout << "10 + 5 = " << client.add(10, 5) << std::endl;
        std::cout << "10 - 5 = " << client.subtract(10, 5) << std::endl;
        transport->close();
    } catch (TException &tx) {
        std::cerr << "ERROR: " << tx.what() << std::endl;
    }

    return 0;
}

