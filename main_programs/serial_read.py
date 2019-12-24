import serial
import time
temperature = [0]
atm_humidity = [0]
soil_humidity = [0]
air_quality = [0]
plant_height = [0]
freq_type = [0]
ser = serial.Serial('/dev/ttyACM0', 9600)

#16.30?57.20?100.00%?40?190.00?None

def read_serial():
    i = 0
    while i<1:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8')
            items = line.split("?")
            if(len(items) == 6):
                temperature[0] = items[0]
                atm_humidity[0] = items[1]
                soil_humidity[0] = items[2].split(".")[0]
                air_quality[0] = items[3]
                plant_height[0] = items[4].split(".")[0]
                freq_type[0] = items[5].split("\r")[0]
                i = i+1
