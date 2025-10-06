#include "gen-cpp/display.h"
#include <iostream>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;


class NameHandler : public person::displayIf {
public:
    void add(const std::string &name)
    {
        std::cout<<"Name is "<< name <<std::endl;
    }
};

int main() {
    int port = 6026;
    ::std::shared_ptr<NameHandler> name(new NameHandler());
    ::std::shared_ptr<TProcessor> processor(new person::displayProcessor(name));
    ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    ::std::shared_ptr<TProtocolFactory> protocalFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocalFactory);
    std::cout<<"Server started on port "<< port << "....." <<std::endl;
    server.serve();

    return 0;
}
