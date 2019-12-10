import os


def measure_temp():
    temp = os.popen("vcgencmd measure_temp").readline()
    output = temp.replace("temp=", "")
    return output[:2]
