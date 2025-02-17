from vosk import Model, KaldiRecognizer
import pyaudio
import json

# Load the Vosk model
model = Model("vosk-model-small-en-us-0.15")
samplerate = 16000
recognizer = KaldiRecognizer(model, samplerate)
cap = pyaudio.PyAudio()

stream = cap.open(format=pyaudio.paInt16, channels=1, rate = 16000, input=True, frames_per_buffer=8192)
stream.start_stream()
while True:
    data = stream.read(4096)
    if len(data) == 0:
        break
    if recognizer.AcceptWaveform(data):
        res = json.loads(recognizer.Result())
        print(res["text"])

