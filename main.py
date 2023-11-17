import os
import requests
import time

from dotenv import load_dotenv

load_dotenv()

host = os.getenv('HOST')
port = os.getenv('PORT')

while True:
    res = requests.get(f'http://{host}:{port}/')
    print(f"Feuchtigkeit: {res.json()['d']}")
    time.sleep(1)
