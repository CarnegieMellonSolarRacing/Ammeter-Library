#ifndef OPERATOR_BRIDGE_H
#define OPERATOR_BRIDGE_H

#include "Arduino.h"
#include <stdbool.h>
#include <ArduinoJson.h>

const int NUM_CURRENT_SENSORS = 3;
const int NUM_TEMP_SENSORS = 2;
const int NUM_VOLTAGE_SENSORS = 3;

class OperatorBridge {
public:
    class PacketOut {
    public:
        float current[NUM_CURRENT_SENSORS];
        float temp[NUM_TEMP_SENSORS];
        float volt[NUM_VOLTAGE_SENSORS];
    };

    class PacketIn {
    public:
        bool error;
        float testValue;
    };

    OperatorBridge();
    ~OperatorBridge();

    // Reads a packet from the connection, null if nothing
    // has been received.
    PacketIn *read();
    // Sends a packet over the connection, returns
    // true iff success.
    bool send(PacketOut packet);
};

#endif
