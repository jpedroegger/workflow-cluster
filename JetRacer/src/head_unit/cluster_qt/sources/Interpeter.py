import requests
import json

def read_api_key(file_path="deepseek_api.txt"):
    try:
        with open(file_path, "r") as file:
            api_key = file.read().strip() 
            return api_key
    except FileNotFoundError:
        print(f"Error: The file '{file_path}' was not found.")
        return None
    except Exception as e:
        print(f"An error occurred while reading the API key: {e}")
        return None

api_key = read_api_key()
response = requests.post(
  url="https://openrouter.ai/api/v1/chat/completions",
  headers={
    "Authorization": f"Bearer {api_key}",
  },
  data=json.dumps({
    "model":"deepseek/deepseek-chat",
    "messages": [
         {"role": "system", "content": "You are a command interpreter in a car dashboard. \
          You need to understand if the user wants to change the color theme of the dashboard \
          (changeColor()), change units from metrical to imperial (changeUnits()), \
          park the car (parkCar()) or initiate blinkers (turnOnBothBlinkers()). \
          Identify the user's intent and return only the corresponding command. \
          Dont explain reasoning, just give me the command you think it is"},
        #{"role": "user", "content": f"Interpret this command: {text}"}
        {"role": "user", "content": f"Interpret this command: change from kph to Fº"}
    ],
  })
)
if response.status_code == 200:
    print(response.json()["choices"][0]["message"]["content"])