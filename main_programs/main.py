from raspberry_pi_temp import measure_temp
from move_to_website import upload_to_web
from write_to_json import write_to_json
import time

while True:
    write_to_json(str(measure_temp()),
                  str(13),
                  str(51)+'%',
                  str(21)+'%',
                  str(51),
                  str(11)+'cm')
    file_name = 'info.json'
    upload_to_web(file_name)
    print('Successfully uploaded them!')
    time.sleep(60*60)