import os
import sys
import json
import sounddevice as sd
import numpy as np
from vosk import Model, KaldiRecognizer

# Load the Vosk model
model = Model("vosk-model-small-en-us-0.15")
samplerate = 44100

def listen_and_transcribe():
    rec = KaldiRecognizer(model, samplerate)
    with sd.RawInputStream(samplerate=samplerate, blocksize=8000, dtype='int16', channels=1, callback=lambda indata, frames, time, status: rec.AcceptWaveform(indata)):
        print("Listening...")
        while True:
            data = rec.Result()
            if data:
                result = json.loads(data)
                print(result)
                text = result.get("text", "")
                if text:
                    print("Transcribed:", text)
                    return text
            else:
                continue

if __name__ == "__main__":
    transcription = listen_and_transcribe()
    print(transcription)