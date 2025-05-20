[11week] Raspberry pi(Middle Ware) 
===

Arduino Uno(미세먼지 센서) -> 


### influxDB
```bash
# influxDB download key using wget
wget -q https://repos.influxdata.com/influxdata-archive_compat.key
```

```bash
echo '393e8779c89ac8d958f81f942f9ad7fb82a25e133faddaf92e15b16e6ac9ce4c influxdata-archive_compat.key' | sha256sum -c && cat influxdata-archive_compat.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg > /dev/null
```

```bash
echo 'deb [signed-by=/etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg] https://repos.influxdata.com/debian stable main' | sudo tee /etc/apt/sources.list.d/influxdata.list
```

```bash
# Package up to date && install influxDB
sudo apt-get update && sudo apt-get install influxdb -y

# Background service on start up
sudo service influxdb start

# influxDB status(service)
sudo service influxdb status

# Create influxDB database
$ influx
>create database <database_name>
확인 : show databases
```

### Grafana 
```bash
# install pakages
sudo apt-get install -y apt-transport-https software-properties-common wget

# Import the gpg key
sudo mkdir -p /etc/apt/keyrings/
```

```bash
wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor | sudo tee /etc/apt/keyrings/grafana.gpg > /dev/null
```

```bash
echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list
```

```bash
sudo apt-get update && sudo apt-get install grafana -y

sudo systemctl start grafana-server

```