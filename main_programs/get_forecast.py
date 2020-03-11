import requests
import json


current_dir = os.getcwd()
base_url = 'http://api.openweathermap.org/data/2.5/forecast?'
api_key = '0e0bd4dcfedac7fe749c8a42a2c04b4b'


def rain(city_name):
    try:
        flag = False

        complete_url = base_url + 'appid=' + api_key + '&q=' + city_name + '&units=metric'
        response = requests.get(complete_url)
        forecast_data = json.loads(response.text)
        
        flag = False

        if forecast_data["cod"] != '404':
            for data in forecast_data['list']:
                main = data['weather'][0]['main']
                date = data['dt_txt']
                if(main == 'Rain'):
                    flag = True 
            
        else:
            print('City not found')
    except Exception as e:
        print('oops, an error occured: ' + str(e))
    
    return flag

