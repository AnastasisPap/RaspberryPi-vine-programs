import serial
import time


temperature = [0]
atm_humidity = [0]
soil_humidity = [0]
air_quality = [0]
plant_height = [0]
ser = serial.Serial('/dev/ttyACM0', 9600)


def read_serial():
    i = 0
    ser = serial.Serial('/dev/ttyACM0', 9600)
    while i<1:
        if ser.in_waiting > 0:
            
            line = ser.readline().decode('utf-8')
            items = line.split("?")            
            if(len(items) == 5):
                temperature[0] = items[0]
                atm_humidity[0] = items[1]                
                soil_humidity[0] = items[2].split(".")[0]
                air_quality[0] = items[3]
                plant_height[0] = items[4].split(".")[0]
                i = i+1
