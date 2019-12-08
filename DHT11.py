import Adafruit_DHT as DHT
import time

DHT_SENSOR = DHT.DHT11
DHT_PIN = 4

while True:
    humidity, temperature = DHT.read(DHT_SENSOR, DHT_PIN)
    if humidity is not None and temperature is not None:
        print("Temp={0:0.1f}C  Humidity={1:0.1f}%".format(temperature, humidity))
    else:
        print("Sensor failure, check wiring")
    time.sleep(2)
