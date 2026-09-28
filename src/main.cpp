#include <Arduino.h>

#include <WiFi.h>
#include <WebServer.h>
#include <LittleFS.h>

WebServer server(80);

const char *AP_SSID = "PS4 slopkit ESP32";
const IPAddress AP_IP(192, 168, 4, 1);
const uint8_t ONBOARD_LED = 2;

void WiFiEvent(WiFiEvent_t event)
{
    switch (event)
    {
    case ARDUINO_EVENT_WIFI_AP_START:
        Serial.println("[WIFI] AP started");
        Serial.print("[WIFI] SSID: ");
        Serial.println(AP_SSID);
        Serial.print("[WIFI] IP:   ");
        Serial.println(WiFi.softAPIP());
        break;

    case ARDUINO_EVENT_WIFI_AP_STACONNECTED:
        Serial.println("[WIFI] Client connected");
        break;

    case ARDUINO_EVENT_WIFI_AP_STADISCONNECTED:
        Serial.println("[WIFI] Client disconnected");
        break;

    default:
        break;
    }
}

void setup()
{
    Serial.begin(115200);

    WiFi.onEvent(WiFiEvent);

    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(AP_IP, AP_IP, IPAddress(255, 255, 255, 0));

    Serial.print("[WIFI] Starting AP: ");
    Serial.println(AP_SSID);

    WiFi.softAP(AP_SSID);

    LittleFS.begin();

    server.serveStatic("/", LittleFS, "/");
    server.begin();

    Serial.println("[HTTP] Server started");
}

void loop()
{
    server.handleClient();
}