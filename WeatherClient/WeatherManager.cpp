#include "WeatherManager.h"
using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;
using namespace Weather;

WeatherManager::WeatherManager(QObject *parent)
    : QObject(parent)
{
    auto socket = std::make_shared<TSocket>("127.0.0.1", 9090);
    m_transport = std::make_shared<TBufferedTransport>(socket);
    auto protocol = std::make_shared<TBinaryProtocol>(m_transport);
    m_client = std::make_shared<WeatherServiceClient>(protocol);
    m_transport->open();
}

double WeatherManager::getTemperature(const QString &city)
{
    double t = m_client->getTemperature(city.toStdString());
    qDebug() << "Temperature received for" << city << ":" << t;
    return t;
}
