# moisture-sensor-esp8266

A simple example respository for creating a REST-service on a esp8266-based board.
Also, this repository contains a simple python script to access to API endpoint of the board.

## 📦 Used Items

-   1x ESP8266-based board (Octopus Board)
-   1x Grove Moisture Sensor

## 💁‍♂️ How to use?

With the items above, plug-in the moisture sensor to the A0 pin on the board and then plug-in the board to your PC via USB.
The moisture sensor will return the resistance, with higher resistance being a more wet measuring environment.

To make the API work, change the `ssid` and `password` variable to your router's SSID and password.

To use the python script, rename the `.env.example` file and enter your board's IP-adress as `HOST` as well as the defined port from your <a href="/sensor.ino">sensor.ino</a> as `PORT`. Note: your board's IP-address will be printed to the serial monitor on startup.
