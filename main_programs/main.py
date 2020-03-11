from raspberry_pi_temp import measure_temp
from move_to_website import upload_to_web
from write_to_json import write_to_json
from serial_read import *
from get_forecast import rain
import time

city_name = 'Kiato,GR'

cnt = 0
flag = rain(city_name)
while True:
    if (cnt = 40):
        flag = rain(city_name)
        cnt = 0
    
    read_serial()
    pi_temp = str(measure_temp())
    temp = str(temperature[0])
    atm_hum = str(atm_humidity[0])
    soil_hum = soil_humidity[0]
    air_q = str(air_quality[0])
    plant_h = str(plant_height[0])
    
    if (int(soil_hum) > 50 and flag == False):
        soil_hum = 'Needs water'
    else:
        soil_hum = str(soil_hum) + '%'

    if('eed' not in soil_hum):
        soil_hum = soil_hum + '%'
    
    write_to_json(pi_temp,
                  temp,
                  atm_hum+'%',
                  soil_hum,
                  air_q,
                  plant_h+'cm')
    file_name = 'info.json'
    print('Please wait')
    time.sleep(30)
    upload_to_web(file_name)
    print('Successfully uploaded them!')
    time.sleep(60)
    cnt += 1
