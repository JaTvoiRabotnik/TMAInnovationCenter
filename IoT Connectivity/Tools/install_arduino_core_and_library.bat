@echo off

set EXECUTED_DIR="%CD%"
set ARDUINO_DIR=%UserProfile%\Documents\Arduino
set HARDWARE_DIR=%ARDUINO_DIR%\hardware
set LIBRARY_DIR=%ARDUINO_DIR%\libraries

if not exist "%UserProfile%\Documents" mkdir "%UserProfile%\Documents"
if not exist "%ARDUINO_DIR%" mkdir "%ARDUINO_DIR%"
if not exist "%HARDWARE_DIR%" mkdir "%HARDWARE_DIR%"
if not exist "%LIBRARY_DIR%" mkdir "%LIBRARY_DIR%"

REM ARDUINO CORE
REM ---------------------------------------------------------------------------
REM Install Arduino core for Expressif ESP8266/ESP32
echo Install Arduino core for Expressif ESP8266/ESP32
set EXPRESSIF_HARDWARE_DIR=%HARDWARE_DIR%\espressif
set EXPRESSIF_ESP32_DIR=%EXPRESSIF_HARDWARE_DIR%\esp32
set EXPRESSIF_ESP8266_DIR=%EXPRESSIF_HARDWARE_DIR%\esp8266
set EXPRESSIF_ESP32_URL=https://github.com/espressif/arduino-esp32.git
set EXPRESSIF_ESP8266_URL=https://github.com/esp8266/Arduino.git

if exist "%EXPRESSIF_HARDWARE_DIR%" rm -r -f "%EXPRESSIF_HARDWARE_DIR%"
mkdir %EXPRESSIF_HARDWARE_DIR%

REM Expressif ESP32
cd /D "%EXPRESSIF_HARDWARE_DIR%"
call git clone "%EXPRESSIF_ESP32_URL%" esp32
cd /D "%EXPRESSIF_ESP32_DIR%\tools"
call get.exe
cd /D "%EXPRESSIF_ESP32_DIR%libraries\BLE"
git clone https://github.com/nkolban/ESP32_BLE_Arduino.git .

REM Expressif ESP8266
cd /D "%EXPRESSIF_HARDWARE_DIR%"
call git clone "%EXPRESSIF_ESP8266_URL%" esp8266
cd /D "%EXPRESSIF_ESP8266_DIR%\tools"
call python get.py

echo Install Arduino core for Expressif ESP8266/ESP32 completed.
REM ---------------------------------------------------------------------------


REM ---------------------------------------------------------------------------
REM Install Arduino core for Heltec WiFi Kit 32 board
echo Install Arduino core for Heltec WiFi Kit 32 board
set HELTEC_HARDWARE_DIR=%HARDWARE_DIR%\heltec
set HELTEC_ESP32_DIR=%HELTEC_HARDWARE_DIR%\esp32
set HELTEC_ESP32_URL=https://github.com/Alictronix/LoRa-ESP32-OLED.git

if exist "%HELTEC_HARDWARE_DIR%" rm -r -f "%HELTEC_HARDWARE_DIR%"

REM Heltec WiFi Kit 32
cd /D "%HARDWARE_DIR%"
call git clone "%HELTEC_ESP32_URL%" heltec
cd /D "%HELTEC_ESP32_DIR%\tools"
call get.exe

echo Install Arduino core for Heltec WiFi Kit 32 board completed.
REM ---------------------------------------------------------------------------

REM INSTALL LIBRARY
REM ---------------------------------------------------------------------------
cd /D "%LIBRARY_DIR%"

echo Install PubSubClient library
set PUBSUBCLIENT_DIR=%LIBRARY_DIR%\pubsubclient
set PUBSUBCLIENT_URL=https://github.com/knolleary/pubsubclient.git
if exist "%PUBSUBCLIENT_DIR%" rm -r -f "%PUBSUBCLIENT_DIR%"
call git clone "%PUBSUBCLIENT_URL%" pubsubclient
echo Install PubSubClient library completed.

echo Install WIFIMANAGER-ESP32 library
set WIFIMANAGER_DIR=%LIBRARY_DIR%\WIFIMANAGER-ESP32
set WIFIMANAGER_URL=https://github.com/zhouhan0126/WIFIMANAGER-ESP32.git
if exist "%WIFIMANAGER_DIR%" rm -r -f "%WIFIMANAGER_DIR%"
call git clone "%WIFIMANAGER_URL%" WIFIMANAGER-ESP32
echo Install WIFIMANAGER-ESP32 library completed.

echo Install WebServer-esp32 library
set WEBSERVER_DIR=%LIBRARY_DIR%\WebServer-esp32
set WEBSERVER_URL=https://github.com/zhouhan0126/WebServer-esp32.git
if exist "%WEBSERVER_DIR%" rm -r -f "%WEBSERVER_DIR%"
call git clone "%WEBSERVER_URL%" WebServer-esp32
echo Install WebServer-esp32 library completed.

echo Install DNSServer-esp32 library
set DNSSERVER_DIR=%LIBRARY_DIR%\DNSServer-esp32
set DNSSERVER_URL=https://github.com/zhouhan0126/DNSServer---esp32.git
if exist "%DNSSERVER_DIR%" rm -r -f "%DNSSERVER_URL%"
call git clone "%DNSSERVER_URL%" DNSServer-esp32
echo Install DNSServer-esp32 library completed.

echo Install AWS_IOT-esp32 library
set AWS_IOT_DIR=%LIBRARY_DIR%\AWS_IOT-esp32
set AWS_IOT_URL=https://github.com/ExploreEmbedded/Hornbill-Examples.git
if exist "%AWS_IOT_DIR%" rm -r -f "%AWS_IOT_DIR%"
mkdir %AWS_IOT_DIR%
call git clone "%AWS_IOT_URL%" _tmp_dir
xcopy /s _tmp_dir\arduino-esp32\AWS_IOT "%AWS_IOT_DIR%"
rm -r -f _tmp_dir
echo Install AWS_IOT-esp32 library completed.

echo Install RFID MFRC522 library
set RFID_MFRC522_DIR=%LIBRARY_DIR%\rfid-mfrc522
set RFID_MFRC522_URL=https://github.com/miguelbalboa/rfid.git
if exist "%RFID_MFRC522_DIR%" rm -r -f "%RFID_MFRC522_DIR%"
call git clone "%RFID_MFRC522_URL%" rfid-mfrc522
echo Install RFID MFRC522 library completed.

echo Install CoAP library
set COAP_DIR=%LIBRARY_DIR%\CoAP
set COAP_URL=https://github.com/hirotakaster/CoAP-simple-library.git
if exist "%COAP_DIR%" rm -r -f "%COAP_DIR%"
call git clone "%COAP_URL%" CoAP
echo Install CoAP library completed.

cd /D "%EXECUTED_DIR%"
echo Press any keys to exit.
pause
