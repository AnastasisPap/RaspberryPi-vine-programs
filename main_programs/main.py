from raspberry_pi_temp import measure_temp
from move_to_website import upload_to_web
from write_to_json import write_to_json
from serial_read import *
import time

while True:
    read_serial()
    pi_temp = str(measure_temp())
    temp = str(temperature[0])
    atm_hum = str(atm_humidity[0])
    soil_hum = str(soil_humidity[0])
    air_q = str(air_quality[0])
    plant_h = str(plant_height[0])
    write_to_json(pi_temp,
                  temp,
                  atm_hum+'%',
                  soil_hum,
                  air_q,
                  plant_h+'cm')
    file_name = 'info.json'
    upload_to_web(file_name)
    print('Successfully uploaded them!')
    time.sleep(60*10)
