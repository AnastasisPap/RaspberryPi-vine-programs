import pysftp
from sftp_info import *

cnopts = pysftp.CnOpts()
cnopts.hostkeys = None


def upload_to_web(file_name):
    try:
        with pysftp.Connection(host=host, username=username, password=password, cnopts=cnopts, port=21098) as sftp:
            print('Connection successfully established ...')

            localFile = './'+file_name
            remoteFilePath = '/home/pawepacr/vinenotifications.com/'+file_name

            sftp.put(localFile, remoteFilePath)
    except:
        print("oops")
