from git import Repo
import os


repo_dir = os.getcwd() + '/.git'
commit_message = 'commit message'

def git_push():
    try:
        repo = Repo(repo_dir)
        repo.index.add('info.json')
        repo.index.commit(commit_message)
        origin = repo.remote('origin')
        origin.push()
    except:
        print('Some error occured while pushing the code')

git_push()
