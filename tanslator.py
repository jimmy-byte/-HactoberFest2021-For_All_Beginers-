from googletrans import Translator #pip install googletrans
from gtts import gTTS
import os

translater = Translator()

fh=open("translate.txt","r")

out = translater.translate(text=fh.read().replace("\n", ' ') ,  scr='la' ,dest="hi")

print(out.text)

language = 'hi'

audioout = gTTS(text=out.text, lang=language ,slow=False)

audioout.save("translateaudio.mp3")

fh.close()

os.system("start translateaudio.mp3")