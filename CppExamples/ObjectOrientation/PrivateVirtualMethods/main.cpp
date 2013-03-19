#include<iostream>

using namespace std;

class BasicComms {
private:
    virtual void openConnection() = 0;
    virtual void transmit() = 0;
    virtual void closeConnection() = 0;
public:
    void sendMessage();
};

class SMTPComms : public BasicComms {
private:
    void openConnection();
    void transmit();
    void closeConnection();
};

class HTTPComms : public BasicComms {
private:
    void openConnection();
    void transmit();
    void closeConnection();
};

void BasicComms::sendMessage() {
    openConnection();
    transmit();
    closeConnection();
}

void SMTPComms::openConnection() {
    cout << "SMTP - Opening Connection" << endl;
}
void SMTPComms::transmit() {
    cout << "SMTP - Transmitting Data" << endl;
}
void SMTPComms::closeConnection() {
    cout << "SMTP - Closing Connection" << endl;
}
void HTTPComms::openConnection() {
    cout << "HTTP - Opening Connection" << endl;
}
void HTTPComms::transmit() {
    cout << "HTTP - Transmitting Data" << endl;
}
void HTTPComms::closeConnection() {
    cout << "HTTP - Closing Connection" << endl;
}

int main() {
    SMTPComms smtp;
    HTTPComms http;
    smtp.sendMessage();
    http.sendMessage();
}