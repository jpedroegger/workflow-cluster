import requests
from vosk import Model, KaldiRecognizer
import pyaudio
import json

# Load the Vosk model
model = Model("vosk-model-small-en-us-0.15")
samplerate = 16000
recognizer = KaldiRecognizer(model, samplerate)
cap = pyaudio.PyAudio()



def speech_to_text(recognizer, cap):
    stream = cap.open(format=pyaudio.paInt16, channels=1, rate = 16000, input=True, frames_per_buffer=8192)
    stream.start_stream()
    print("Listening...")
    while True:
        data = stream.read(4096)
        if len(data) == 0:
            break
        if recognizer.AcceptWaveform(data):
            res = json.loads(recognizer.Result())
            print("Input received: ", res["text"])
            return res["text"]

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
while (1):
    text = speech_to_text(recognizer, cap)
    if (text == "Go to sleep"):
        print("🤖: Going to sleep, goodbye ")
        break
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
              If you think none of this applies, return only 'Unrecognized command'. \
              Identify the user's intent and return only the corresponding command. \
              Dont explain reasoning, just give me the command you think it is"},
            {"role": "user", "content": f"Interpret this command: {text}"}
            #{"role": "user", "content": f"Interpret this command: change from kph to Fº"}
        ],
      })
    )
if response.status_code == 200:
    print("🤖: ", response.json()["choices"][0]["message"]["content"])