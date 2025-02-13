import sounddevice as sd
import numpy as np
import soundfile as sf  # To save the recording as a .wav file

# Set the sample rate to match the device
samplerate = 44100

# Record a short duration
duration = 5  # in seconds
print("Recording...")
audio_data = sd.rec(int(samplerate * duration), samplerate=samplerate, channels=1, dtype='int16', device=device)
sd.wait()  # Wait until recording is done
print("Recording finished.")

# Save the audio data to a WAV file
sf.write('recorded_audio.wav', audio_data, samplerate)
print("Recording saved to 'recorded_audio.wav'.")
