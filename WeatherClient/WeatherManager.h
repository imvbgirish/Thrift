#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#pragma once
#include <QObject>
#include "gen-cpp/WeatherService.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <QDebug>

class WeatherManager : public QObject {
    Q_OBJECT
public:
    explicit WeatherManager(QObject* parent = nullptr);

    Q_INVOKABLE double getTemperature(const QString &city);

private:
    std::shared_ptr<apache::thrift::transport::TBufferedTransport> m_transport;
    std::shared_ptr<Weather::WeatherServiceClient> m_client;
};

#endif // WEATHERMANAGER_H
