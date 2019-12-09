import pysftp

host='ip address'
username='host'
password='password'
cnopts = pysftp.CnOpts()
cnopts.hostkeys = None

with pysftp.Connection(host=host, username=username, password=password, cnopts=cnopts, port=21098) as sftp:
    print('Connection successfully established ...')

    localFile = './file.json'
    remoteFilePath = '/path/to_file/file.json'

    sftp.put(localFile, remoteFilePath)
