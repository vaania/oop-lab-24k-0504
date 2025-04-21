#include <iostream>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;
public:
    Shipment(string tn, double w) : trackingNumber(tn), weight(w) {}
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
};

class AirFreight : public Shipment {
public:
    AirFreight(string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() override {
        cout << "AirFreight Estimated Delivery: " << (1 + weight * 0.05) << " days\n";
    }
    void showDetails() override {
        cout << "AirFreight - Tracking #: " << trackingNumber << ", Weight: " << weight << "kg\n";
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() override {
        cout << "GroundShipment Estimated Delivery: " << (3 + weight * 0.1) << " days\n";
    }
    void showDetails() override {
        cout << "GroundShipment - Tracking #: " << trackingNumber << ", Weight: " << weight << "kg\n";
    }
};

int main() {
    Shipment* shipments[2];
    shipments[0] = new AirFreight("AIR123", 10.5);
    shipments[1] = new GroundShipment("GRD456", 25.0);

    for (int i = 0; i < 2; ++i) {
        shipments[i]->showDetails();
        shipments[i]->estimateDeliveryTime();
        delete shipments[i];
    }

    return 0;
}
