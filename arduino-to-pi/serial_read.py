import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
while 1:
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8')
        items = line.split("?")
        temperature = items[0]
        atm_humidity = items[1]
        soil_humidity = items[2]
        air_quality = items[3]
        plant_height = items[4]
