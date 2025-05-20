[10week] OpenCV
===

### opencv
```bash
# ERROR 발생 시
sudo rm /usr/lib/python3.11/EXTERNALLY-MANAGED

# opencv
pip install opencv-contrib-python
sudo apt-get install python3-opencv

# memory swap(before install opencv)
free -m
sudo vim /etc/dphys-swapfile - CONF_SWAPSIZE = 200 -> 2048

# memory swqp(after install opencv)
sudo vim /etc/dphys-swapfile - CONF_SWAPSIZE = 2048 -> 200
```

### telegram-bot
```bash
# python-telegram-bot(lib)
pip install python-telegram-bot --upgrade
pip install python-telegram-bot[job-queue] --pre

# git clone
git clone https://github.com/python-telegram-bot/python-telegram-bot

cd python-telegram-bot/examples/
vim timerbot.py(main -> token(my_token))

python timerbot.py
```
