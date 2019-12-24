import json
import os

dir = os.getcwd()


def write_to_json(pi_temp, temp, humidity, soil_hum, air_q, plant_h):
    data = {
        "pi_temp": pi_temp,
        "temp": temp,
        "humidity": humidity,
        "soil_hum": soil_hum,
        "air_q": air_q,
        "plant_h": plant_h
    }
    file_name = "info.json"
    with open(file_name, 'w') as file:
        json.dump(data, file)
