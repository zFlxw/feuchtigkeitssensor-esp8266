import os
import requests
import time

from dotenv import load_dotenv

load_dotenv()

host = os.getenv('HOST')

while True:
    res = requests.get(f'http://{host}:2301/')
    print(f"Feuchtigkeit: {res.json()['d']}")
    time.sleep(1)