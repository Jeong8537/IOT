[3주차]미세먼지 센서, 아두이노 연동
===

> 1) 센서 중앙 홀을 통해 공기중에 먼지량을 측정
> 2) 원형 구멍의 양옆으로 두개의 소자가 부착됨(적외선 LED, 수신소자)

### 미세먼지 센서
1) 적외선 LED 작동 방법
    - LED On/Off 총 10ms, (0.32ms LED ON/ 9.68ms LED OFF)

2) 데이터 수신
    - 적외선 LED 켠 후 0.28ms 흐르고, 적외선 수신기 작동 시켜 읽어옴

3) 아날로그 데이터 : 전압을 0 ~ 1023로 표현
    - 전압 V : 아날로그 핀 값 * 5.0 / 1023.0

4) 전압 값을 이용, 미세먼지 양 측정
- - -
### Python Module install
```bash
$  pip install influxdb-client
$  pip install influxdb
$  pip install pyserial
```
- - -
### influxdb
> url: http://localhost:8086
>> influxdb_token = 생성한 token

#### 데이터 조회
Dashboard -> bucket -> measurement -> field -> tag